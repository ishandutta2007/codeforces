#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 3e5+5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    int w[n];
    for(int i=0;i<n;i++)
        cin >> w[i];
    int dp[1<<12];
    int cnt[1<<12];
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for(int i=0;i<m;i++) {
        string s; cin >> s;
        int bit = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') bit+=1<<i;
        }
        ++cnt[bit];
    }

    for(int msk=0;msk<1<<n;msk++) {
        for(int i=0;i<n;i++) {
            if(msk&(1<<i)) dp[msk]+=w[i];
        }
    }
    int num[1<<12][101];
    for(int msk=0;msk<1<<n;msk++) {
        for(int j=0;j<=100;j++) {
            num[msk][j] = 0;
        }
    }
    for(int msk=0;msk<1<<n;msk++) {
        for(int cmp=0;cmp<1<<n;cmp++) {
            int take = (1<<n)-1-(msk^cmp);
            int cost = dp[take];
            if(cost<=100) {
                num[msk][cost]+=cnt[cmp];
            }
        }
    }
    for(int msk=0;msk<1<<n;msk++) {
        for(int j=1;j<=100;j++) {
            num[msk][j]+=num[msk][j-1];
        }
    }
    for(int i=0;i<q;i++) {
        string t; cin >> t;
        int bit = 0;
        for(int j=0;j<n;j++) {
            if(t[j]=='1') bit+=(1<<j);
        }
        int k; cin >> k;
        printf("%d\n",num[bit][k]);
    }

}