#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll arr[MAXN], fact[MAXN], inv[MAXN];

ll fpow(ll b, ll e){
    ll ans=1;
    while (e){
        if (1&e) ans=ans*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ans;
}

ll choose(int n, int r){ return fact[n]*inv[r]%mod*inv[n-r]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=1, inv[0]=1;
    for (int i=1;i<MAXN;++i) fact[i]=fact[i-1]*i%mod, inv[i]=fpow(fact[i],mod-2);
    int t; cin >> t;
    while (t--){
        int n, m, k; cin >> n >> m >> k;
        for (int i=1;i<=n;++i) cin >> arr[i];
        sort(arr+1,arr+1+n); arr[0]=-0x3f3f3f3f;
        ll ans=0;
        for (int pr=n,pl=n;pr>=1;--pr){
            while (arr[pr]-arr[pl-1]<=k) pl--;
            if (pr-pl<m-1) continue;
            ans+=choose(pr-pl,m-1); ans%=mod;
        }
        cout << ans << '\n';

    }
}