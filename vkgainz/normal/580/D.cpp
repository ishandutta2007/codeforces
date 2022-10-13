#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
ll dp[1<<18][18]; //stores max enjoyment from eating subset and ending at idx
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int c[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) c[i][j] = 0;
    for(int i=0;i<k;i++) {
        int x,y, w;
        cin >> x >> y >> w;
        --x, --y;
        c[y][x] = w;
    }
    ll ans = 0;
    for(int i=0;i<n;i++) {
        dp[1<<i][i] = a[i];
    }
    for(int i=0;i<1<<n;i++) {
        int cnt = 0;
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) {
                ++cnt;
                for(int k=0;k<n;k++) {
                    if(i&(1<<k) && k!=j) {
                        dp[i][j] = max(dp[i][j],dp[i^(1<<j)][k]+c[j][k]+a[j]);
                    }
                }
            }
        }
        if(cnt==m) {
            for(int j=0;j<n;j++) ans = max(ans,dp[i][j]);
        }
        
    }
    cout << ans << endl;
}