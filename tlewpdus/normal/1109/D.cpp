#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
ll fac[1000100], fnv[1000100];
ll comb(ll n, ll r) {
    if (r<0||r>n) return 0;
    return fac[n]*fnv[r]%MOD*fnv[n-r]%MOD;
}
ll P(ll n, ll r) {
    if (r<0||r>n) return 0;
    return fac[n]*fnv[n-r]%MOD;
}
ll po(ll a, ll n) {
    if (!n) return 1;
    ll t = po(a,n/2);
    return t*t%MOD*(n%2?a:1)%MOD;
}
ll D(ll k) {
    if (k==n-1) return 1;
    return (k+1)*po(n,n-k-2)%MOD;
}

int main() {
    int i;

    scanf("%d%d%*d%*d",&n,&m);
    fac[0] = 1;
    for (i=1;i<=max(n,m);i++) fac[i] = fac[i-1]*i%MOD;
    for (i=0;i<=max(n,m);i++) fnv[i] = po(fac[i],MOD-2);
    ll ans = 0;
    for (i=1;i<n;i++) {
        ans += D(i)*comb(m-1,i-1)%MOD*po(m,n-1-i)%MOD*P(n-2,i-1)%MOD;
    }
    printf("%lld\n",ans%MOD);

    return 0;
}