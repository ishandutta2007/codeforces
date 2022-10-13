#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,q; 
    cin >> n >> q;
    int numDiag = 0;
    int numAdj = 0;
    int grid[2][n];
    for(int i=0;i<2;i++)
        for(int j=0;j<n;j++)
            grid[i][j] = 0;
    for(int i=0;i<q;i++){
        int r,c;
        cin >> r >> c;
        --r; --c;
        if(grid[r][c]){
            if(c>=1 && grid[(r+1)%2][c-1])
                --numDiag;
            if(c<n-1 && grid[(r+1)%2][c+1])
                --numDiag;
            if(grid[(r+1)%2][c])
                --numAdj;
        }
        else{
            if(c>=1 && grid[(r+1)%2][c-1])
                ++numDiag;
            if(c<n-1 && grid[(r+1)%2][c+1])
                ++numDiag;
            if(grid[(r+1)%2][c])
                ++numAdj;
        }
        grid[r][c] = (grid[r][c]+1)%2;
        if(numDiag>0 || numAdj>0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}