#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;
const int sq = 319;
int dp1[100005][320], dp2[100005][320];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i=0;i<n;++i) {
            for(int j=1;j<=sq;++j) {
                dp1[i][j]=dp2[i][j]=0;
            }
        }
        ll ans = 0, pre = 0;
        if(a[n-1]<=sq) dp2[n-1][a[n-1]]=1;
        else dp1[n-1][1]=1;
        for(int i = n - 2; i >= 0; --i) {
            ans = (ans + pre) % mod;
            if(a[i]<=sq) dp2[i][a[i]]=1;
            else dp1[i][1]=1;
            ll tmp = 0;
            for(int j = 1, r; j <= a[i+1]; j = r + 1) {
                r = a[i+1]/(a[i+1]/j);
                int p=a[i+1]/j;
                if(p <= sq) {
                    if(!dp2[i+1][p]) continue;
                    int k = (a[i] + p - 1) / p;
                    tmp += 1ll * (k - 1) * dp2[i+1][p] % mod;
                    int q = a[i] / k;
                    if(q <= sq) (dp2[i][q] += dp2[i+1][p]) %= mod;
                    else (dp1[i][a[i]/q] += dp2[i+1][p]) %= mod;
                } else {
                    if(!dp1[i+1][a[i+1]/p]) continue;
                    int k = (a[i] + p - 1) / p;
                    tmp += 1ll * (k - 1) * dp1[i+1][a[i+1]/p] % mod;
                    int q = a[i] / k;
                    if(q <= sq) (dp2[i][q] += dp1[i+1][a[i+1]/p]) %= mod;
                    else (dp1[i][a[i]/q] += dp1[i+1][a[i+1]/p]) %= mod;
                }
            }
            pre = (pre + tmp) % mod;
            ans = (ans + tmp) % mod;
        }
        cout << ans << '\n';
    }
}