#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp2[3001][3001];
ll dp[3001][3001];
void solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }
    int nxt[n][n];
    int pos[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            nxt[i][j] = n+1;
    fill(pos,pos+n,n+1);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++) nxt[i][j] = pos[j];
        pos[a[i]] = i;
    }
    int bef[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            bef[i][j] = -1;
    fill(pos,pos+n,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) bef[i][j] = pos[j];
        pos[a[i]] = i;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
            dp2[i][j] = 0;
        }
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<n;i++){
            int j = i+len-1;
            if(j>=n) continue;
            dp2[i][j]++;
            int i1= nxt[i][a[i]];
            int j1 = bef[j][a[j]];
            if(i1==n+1 || j1==-1)
                continue;
            dp2[i][j]+=dp2[i][j1]+dp2[i1][j]-dp2[i1][j1];
        }
    }
    for(int len=4;len<=n;len++){
        for(int i=0;i<n;i++){
            
            int j = i+len-1;
            if(j>=n) continue;
            int i1 = nxt[i][a[j]];
            int j1 = bef[j][a[i]];
            dp[i][j] =dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            if(i1==n+1 || j1==-1)
                continue;
            dp[i][j]+=dp2[i1][j1];
        }
    }
    cout << dp[0][n-1] << endl;

}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}