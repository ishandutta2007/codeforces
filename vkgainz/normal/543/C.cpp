#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main() {
    int n,m;
    cin >> n >> m;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    pair<int, int> cost[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int t = 0;
            int bit = 0;
            for(int x=0;x<n;x++) {
                if(x!=i && s[x][j]==s[i][j]) t+=a[x][j];
                if(s[x][j]==s[i][j]) bit+=1<<x;
            }
            cost[i][j] = {t, bit};
        }
    }
    int dp[1<<20];
    dp[0] = 0;
    for(int msk=1;msk<1<<n;msk++) {
        dp[msk] = 1000000000;
        for(int idx=0;idx<n;idx++) {
            if((msk&(1<<idx))==0) continue;
            for(int ch=0;ch<m;ch++) {
                dp[msk] = min(dp[msk], dp[msk^(1<<idx)]+a[idx][ch]);
                dp[msk] = min(dp[msk], dp[msk^(cost[idx][ch].s&msk)]+cost[idx][ch].f);
            }
        }
    }
    cout << dp[(1<<n)-1];
}