#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int grid[9][9];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        char temp;
        for (int i=0;i<9;++i){
            for (int k=0;k<9;++k){
                cin >> temp;
                grid[i][k]=temp-'0';
            }
        }
        grid[0][0]=grid[0][1];
        grid[1][3]=grid[1][4];
        grid[2][6]=grid[2][7];
        grid[3][1]=grid[3][2];
        grid[4][4]=grid[4][5];
        grid[5][7]=grid[5][8];
        grid[6][2]=grid[6][3];
        grid[7][5]=grid[7][6];
        grid[8][8]=grid[8][7];
        for (int i=0;i<9;++i){
            for (int k=0;k<9;++k){
                cout << grid[i][k];
            }
            cout << '\n';
        }
    }
    
}