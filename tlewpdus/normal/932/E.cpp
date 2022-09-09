#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
ll st[2][5010];
ll rp[5010];
ll n, k;

ll tp(ll n) {
    if (!n) return 1;
    ll t = tp(n/2);
    return t*t%MOD*(n%2?2:1);
}

int main() {
    scanf("%lld%lld",&n,&k);
    int i, j;
    st[0][0] = 1;
    for(i=0;i<k;i++) {
        for (j=1;j<=i+1;j++) st[1][j] = (st[0][j]*j%MOD+st[0][j-1])%MOD;
        for (j=0;j<=i+1;j++) st[0][j] = st[1][j];
    }
    rp[0] = n;
    for (i=1;i<=k;i++) rp[i]=rp[i-1]*(n-i)%MOD;
    ll res = 0;
    for (i=0;i<k;i++) {
        res += st[0][i+1]*tp(n-1-i)%MOD*rp[i]%MOD;
        res %= MOD;
    }
    printf("%lld\n",res);

    return 0;
}