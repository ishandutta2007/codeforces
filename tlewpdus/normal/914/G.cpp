#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

int m = 1<<17, n, mnv;
ll MOD = 1000000007;
ll fib[140000];
ll c[140000];
ll ac[140000];
ll cc[140000];
int bt[140000];

ll power(ll a, ll n) {
    if (!n) return 1;
    ll t = power(a,n/2);
    if (n&1) return t*t%MOD*a%MOD;
    return t*t%MOD;
}

ll Rev(ll x) {
    ll i, r = 0;
    for (i = 0; i < 17; i++) {
        r = r << 1 | x & 1;
        x >>= 1;
    }
    return r;
}

void FFT(ll *a, bool f) {
    ll i, j, k, z;
    for (i = 0; i < m; i++) {
        j = Rev(i);
        if (i < j) {
            z = a[i];
            a[i] = a[j];
            a[j] = z;
        }
    }
    for (i = 1; i < m; i <<= 1) for (j = 0; j < m; j += i << 1) for (k = 0; k < i; k++) {
        z = a[i + j + k];
        a[i + j + k] = (a[j + k] + MOD - z)%MOD;
        a[j + k] = (a[j+k]+z)%MOD;
    }
    if (f) for (i = 0; i < m; i++) a[i] = a[i]*mnv%MOD;
}


ll bc[140000];
ll tac[140000], tbc[140000], tcc[140000], tt[140000];
int pcnt[140000];

int main() {
    fib[0] = 0; fib[1] = 1;
    int i, j;
    for (i=0;i<17;i++) bt[1<<i]=i;
    for (i=2;i<m;i++) fib[i] = (fib[i-1]+fib[i-2])%MOD;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        c[a]++;
        bc[a]++;
    }
    for (i=0;i<m;i++) {
        vector<int> v, ps;
        for (j=0;j<17;j++) {if (i>>j&1) v.push_back(1<<j);}
        for (j=0;j<v.size();j++) ps.push_back((ps.empty()?0:ps.back())+v[j]);
        int tv = 0;
        for (j=0;j<(1<<v.size());j++) {
            if (j) tv += ps[bt[j&-j]]-((~j&1)?2*ps[bt[j&-j]-1]:0);
            ac[i] = (ac[i]+c[tv]*c[i^tv]%MOD)%MOD;
        }
    }

    mnv = power(m,MOD-2);
    FFT(c,false);
    for (i=0;i<m;i++) c[i] = c[i]*c[i]%MOD;
    FFT(c,true);

    ll as = 0, bs = 0, cs = 0;
    for (i=0;i<m;i++) {
        ac[i] = fib[i]*ac[i]%MOD;
        bc[i] = fib[i]*bc[i]%MOD;
        cc[i] = fib[i]*c[i]%MOD;
    }
    for (i=0;i<17;i++) {
        for (j=0;j<(1<<17);j++) {
            if (~j>>i&1) {
                ac[j] = (ac[j]+ac[j^(1<<i)])%MOD;
                bc[j] = (bc[j]+bc[j^(1<<i)])%MOD;
                cc[j] = (cc[j]+cc[j^(1<<i)])%MOD;
            }
        }
    }

    for (i=0;i<m;i++) tt[i] = ac[i]*bc[i]%MOD*cc[i]%MOD;
    for (i=1;i<m;i++) pcnt[i] = pcnt[i-(i&-i)]+1;

    ll res = 0;
    for (i=0;i<17;i++) {
        for (j=0;j<(1<<17);j++) {
            int sg[2] = {-1,1};
            if (j>>i&1) {
                res += sg[pcnt[j]%2]*tt[j]%MOD;
                res %= MOD;
            }
        }
    }
    printf("%lld\n",(res+MOD)%MOD);

    return 0;
}