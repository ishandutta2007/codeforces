#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,m;
    cin >> n >> m;
    char grid[n][m];
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            grid[i][j] = s[j];
        }
    }
    int numD =0;
    int numR = 0;
    for(int j=0;j<m-1;j++){
        if(grid[n-1][j]=='D'){
            numD++;
        }
    }
    for(int i=0;i<n-1;i++){
        if(grid[i][m-1]=='R'){
            numR++;
        }
    }
    int ans = numD+numR;
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}