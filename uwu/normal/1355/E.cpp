#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll n, a, r, m, arr[MAXN], tot[MAXN];

ll solve(ll x){
    int idx=upper_bound(arr+1,arr+1+n,x)-arr-1;
    ll ls=idx*x-tot[idx], rs=tot[n]-tot[idx]-(n-idx)*x;
    if (rs>ls) return (rs-ls)*r+m*ls;
    else return (ls-rs)*a+m*rs;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> r >> m;
    m=min(m,a+r);
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i) tot[i]=tot[i-1]+arr[i];
    ll ans=min(solve(tot[n]/n),solve(tot[n]/n+1));
    for (int i=1;i<=n;++i) ans=min(ans,solve(arr[i]));
    cout << ans << '\n';
}