#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define REP(i, n) for (int i = 0; i < (n); ++i)
const int N = 2e5 + 10;
const int MOD = 998244353;

const int mod = 998244353;
const int MN = 1<<21;

typedef complex<double> cplex;
int rev[MN];
int wlen_pw[MN], fa[MN], fb[MN];

int pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1ll * r * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return r;
}

void fft(int a[], int n, bool invert) {
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap (a[i], a[rev[i]]);

    for (int len = 2; len <= n; len <<= 1) {
        //double alpha = 2 * PI / len * (invert ? -1 : +1);
        int len2 = len >> 1;

        wlen_pw[0] = 1;
        int wlen = pw(3, (mod - 1) / len);
        if (invert) wlen = pw(wlen, mod - 2);
        for (int i = 1; i < len2; ++i) wlen_pw[i] = 1ll * wlen_pw[i-1] * wlen % mod;

        for (int i = 0; i < n; i += len) {
            int t, *pu = a+i, *pv = a + i + len2,
                    *pu_end = a + i + len2, *pw = wlen_pw;
            for (; pu != pu_end; ++pu, ++pv, ++pw) {
                t = 1ll * *pv * *pw % mod;
                *pv = (*pu - t + mod) % mod;
                *pu = (*pu + t) % mod;
            }
        }
    }

    if (invert) REP(i, n) a[i] = 1ll * a[i] * pw(n, mod - 2) % mod;
}

void calcRev(int n, int logn) {
    REP(i, n) {
        rev[i] = 0;
        REP(j, logn) if (i & (1 << j)) rev[i] |= 1 << (logn - 1 - j);
    }
}

void mulpoly(int a[], int b[], int c[], int na, int nb, int &n) {
    int l = max(na, nb), logn = 0;
    for (n = 1; n < l; n <<= 1) ++logn;
    n <<= 1; ++logn;
    calcRev(n, logn);

    REP(i,n) fa[i] = fb[i] = 0;
    REP(i,na) fa[i] = a[i];
    REP(i,nb) fb[i] = b[i];

    fft(fa, n, false);
    fft(fb, n, false);

    REP(i,n) fa[i] = 1ll * fa[i] * fb[i] % mod;
    fft(fa, n, true);

    REP(i,n) c[i] = fa[i];
}

ll fac[N], rev2[N], revfac[N];
ll revK[N];
ll sumC[N];
int n;
ll k;
ll a[N];

ll C(int n, int m) {
    if (m > n || m < 0) return 0;
    return fac[n] * revfac[m] % MOD * revfac[n - m] % MOD;
}

int poly[N], poly2[N];
ll solve() {
    if (k == 1) return 0;
    int same = 0;
    for(int i = 1; i <= n; i++) same += a[i] == a[i + 1];

    if (k == 2) {
        ll ans = 0;
        for(int i = 0; i <= n - same; i++) {
            int j = n - same - i;
            if (i <= j) continue;
            ans = (ans + C(n - same, i)) % MOD;
        }
        for(int i = 1; i <= same; i++) 
            ans = (ans * 2) % MOD;
        return ans;
    }
    int n1 = n - same;
    for(int i = 0; i <= n1 + 1; i++) poly[i] = pw(fac[i], MOD - 2);
    //for(int i = 0; i <= n1 + 1; i++) cout << poly[i] << " "; cout << endl;

    
    int tmp;
    mulpoly(poly, poly, poly2, n1 + 2, n1 + 2, tmp);
    //for(int i = 0; i <= n1 + 1; i++) cout << poly2[i] << " "; cout << endl;

    ll ans = 0;
    for(int i = 0; i <= n1; i++) {
        ll sum = poly2[i];
        if (i % 2 == 0) {
            sum = (sum - pw(fac[i / 2], 2 * (MOD - 2)) + MOD) % MOD;
        }
        //cout << i << " " << sum * fac[n1] % MOD << '\n';
        sum = sum * rev2[2] % MOD;
        //cout << i << " " << sum * fac[n1] % MOD << '\n';
        sum = (sum * pw(fac[n1 - i], MOD - 2)) % MOD;
        sum = (sum * pw(k - 2, n1 - i)) % MOD;
        //cout << i << " " << sum * fac[n1] % MOD << '\n';
        ans = (ans + sum) % MOD;
    }




    ans = (ans * pw(k, same) % MOD * fac[n1]) % MOD;
    return ans;
}
int main() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    rev2[1] = 1;
    for(int i = 2; i < N; i++) rev2[i] = MOD - rev2[MOD % i] * (MOD / i) % MOD;
    revfac[0] = 1;
    for(int i = 1; i < N; i++) revfac[i] = revfac[i - 1] * rev2[i] % MOD;


    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i]; a[n + 1] = a[1];

    cout << solve() << '\n';


}