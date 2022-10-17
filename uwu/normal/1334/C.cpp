#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int n;
pii a[300001];
ll dp[300001];
ll f[300001];
ll cost[300001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t;  cin >> t;
    while (t--){
        cin >> n;
        for (int i=1;i<=n;++i){
            cin >> a[i].first >> a[i].second;
        }
        for (int i=1;i<=n;++i){
            f[i]=max((ll)0,a[i].first-a[i-1].second)+f[i-1];
            cost[i]=f[i]-f[i-1];
        }
        dp[1]=f[n];   
        dp[n]=a[n].first+f[n-1]-min(a[1].first,a[n].second);
        ll ans=min(dp[1],dp[n]); ll curr;
        for (int i=n-1;i>1;--i){
            dp[i]=a[i].first+dp[i+1]-min(a[i+1].first,a[i].second)-cost[i];
            ans=min(ans,dp[i]);
        }
        cout << ans << '\n';
    }
}