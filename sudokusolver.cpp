#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<char>>board;
    bool solvesudoku2(vector<vector<char>>& board) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == '.') {
                for(char l = '1'; l <= '9'; l++) {
                    if(checkrow(board, i, j, l) && checkcolumn(board, i, j, l) && checksquare(board, i, j, l)) {
                        board[i][j] = l;
                        if(solvesudoku2(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        solvesudoku2(board);
    }
    bool checkrow(vector<vector<char>>& board,int i,int j,char c)
    {
    for(int j=0;j<9;j++)
    {if(board[i][j]==c)
    {return false;}}
    return true;}
    bool checkcolumn(vector<vector<char>>& board,int i,int j,char c)
    {
    for(int i=0;i<9;i++)
    {if(board[i][j]==c)
    {return false;}}
    return true;}
    bool checksquare(vector<vector<char>>& board,int row,int col,char c)
    {for(int i=0;i<9;i++)
    {if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
     {return false;}}
    return true;}

};
int main() {

     vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
};

    Solution solution;
    solution.solveSudoku(board);
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout<<board[i][j];
            cout<<" ";
        }
        cout<<'\n';}

    return 0;
}

