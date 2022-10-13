#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ans[2001][2001][4];
int same[2001][2001][4];
int grid[2001][2001];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            grid[i][j] = s[j]-'a';
        }
    }
    //upright
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                ans[i][j][0] = 1;
                same[i][j][0] = 1;
            }
            else if(j==0){
                if(grid[i-1][j]==grid[i][j])
                    same[i][j][0] = same[i-1][j][0]+1;
                else
                    same[i][j][0] = 1;
                ans[i][j][0] = 1;
            }
            else{
                if(grid[i-1][j]==grid[i][j])
                    same[i][j][0] = same[i-1][j][0]+1;
                else
                    same[i][j][0] = 1;
                if(grid[i][j-1]!=grid[i][j])
                    ans[i][j][0] = 1;
                else
                    ans[i][j][0] = min(ans[i][j-1][0]+1,same[i][j][0]);

            }
        }
    }
    //upleft
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(i==0){
                ans[i][j][1] = 1;
                same[i][j][1] = 1;
            }
            else if(j==m-1){
                if(grid[i-1][j]==grid[i][j])
                    same[i][j][1] = same[i-1][j][1]+1;
                else
                    same[i][j][1] = 1;
                ans[i][j][1] = 1;
            }
            else{
                if(grid[i-1][j]==grid[i][j])
                    same[i][j][1] = same[i-1][j][1]+1;
                else
                    same[i][j][1] = 1;
                if(grid[i][j+1]!=grid[i][j])
                    ans[i][j][1] = 1;
                else
                    ans[i][j][1] = min(ans[i][j+1][1]+1,same[i][j][1]);

            }
        }
    }
    //downright
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1){
                ans[i][j][2] = 1;
                same[i][j][2] = 1;
            }
            else if(j==m-1){
                if(grid[i+1][j]==grid[i][j])
                    same[i][j][2] = same[i+1][j][2]+1;
                else
                    same[i][j][2] = 1;
                ans[i][j][2] = 1;
            }
            else{
                if(grid[i+1][j]==grid[i][j])
                    same[i][j][2] = same[i+1][j][2]+1;
                else
                    same[i][j][2] = 1;
                if(grid[i][j+1]!=grid[i][j])
                    ans[i][j][2] = 1;
                else
                    ans[i][j][2] = min(ans[i][j+1][2]+1,same[i][j][2]);

            }
        }
    }
    //downleft
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(i==n-1){
                ans[i][j][3] = 1;
                same[i][j][3] = 1;
            }
            else if(j==0){
                if(grid[i+1][j]==grid[i][j])
                    same[i][j][3] = same[i+1][j][3]+1;
                else
                    same[i][j][3] = 1;
                ans[i][j][3] = 1;
            }
            else{
                if(grid[i+1][j]==grid[i][j])
                    same[i][j][3] = same[i+1][j][3]+1;
                else
                    same[i][j][3] = 1;
                if(grid[i][j-1]!=grid[i][j])
                    ans[i][j][3] = 1;
                else
                    ans[i][j][3] = min(ans[i][j-1][3]+1,same[i][j][3]);

            }
        }
    }
    ll ret =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ret+=min(ans[i][j][0],min(ans[i][j][1],min(ans[i][j][2],ans[i][j][3])));
        }
    }
    cout << ret << endl;
    
}