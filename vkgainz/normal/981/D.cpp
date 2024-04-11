#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[50];
ll pref[51];
int n,k;
bool work(ll x) {
    bool dp[51][51];
    for(int i=0;i<=50;i++)
        for(int j=0;j<=50;j++) dp[i][j] = 0;
    dp[0][0] = true;
    for(int buck=1;buck<=k;buck++) {
        for(int i=1;i<=n;i++) {
            for(int j=i;j>=1;j--) {
                if(((pref[i]-pref[j-1])&x)==x) {
                    dp[i][buck]|=dp[j-1][buck-1];
                }
            }
        }
    }
    return dp[n][k];
}
int main() {
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) pref[i] = pref[i-1]+a[i-1];
    ll ans = 0;
    for(int bit=60;bit>=0;bit--) {
        if(work(ans+(1LL<<bit))) {
            ans+=1LL<<bit;
        }
    }
    cout << ans << endl;
}