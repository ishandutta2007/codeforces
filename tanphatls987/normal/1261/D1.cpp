#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const int MOD = 998244353;

const int MODULO = 998244353;
const int ROOT = 3; // Primitive root

ll power(ll x, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}
ll inverse(ll n) {
    return power(n, MOD - 2);
}
void fft(vector<int> &a, bool invert) {
    int n = a.size();
    assert((n & (n - 1)) == 0);
    int lg = __builtin_ctz(n);
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (int k = 0; k < lg; ++k) if ((i&1<<k)!=0) j |= 1 << (lg-k-1);
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len *= 2) {
        int wlen = power(ROOT, (MODULO - 1) / len);
        if (invert) wlen = inverse(wlen);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j];
                int v = 1LL * a[i + j + len / 2] * w % MODULO;
                a[i + j] = (u + v) % MODULO;
                a[i + j + len / 2] = (u - v + MODULO) % MODULO;
                w = 1LL * w * wlen % MODULO;
            }
        }
    }
    if (invert) {
        int mul = inverse(n);
        for (auto &x : a) x = 1LL * x * mul % MODULO;
    }
}

ll fac[N], rev[N], revfac[N];
ll revK[N];
ll sumC[N];
int n;
ll k;
ll a[N];

ll C(int n, int m) {
    if (m > n || m < 0) return 0;
    return fac[n] * revfac[m] % MOD * revfac[n - m] % MOD;
}

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

    revK[0] = 1;
    revK[1] = power(k, MOD - 2);
    for(int i = 2; i < N; i++) revK[i] = revK[i - 1] * revK[1] % MOD;



    ll ans = 0;

    int n1 = n - same;
    for(int i = 0; i <= n1; i++) 
        for(int j = 0; j < i && i + j <= n1; j++) { 
            ans = (ans + C(n1, i) * C(n1 - i, j) % MOD * power(k - 2, n1 - i - j)) % MOD;
            //cout << i << " " << j << " " << ans << '\n';
        }
    ans = (ans * power(k, same)) % MOD;
    return ans;
}
int main() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    rev[1] = 1;
    for(int i = 2; i < N; i++) rev[i] = MOD - rev[MOD % i] * (MOD / i) % MOD;
    revfac[0] = 1;
    for(int i = 1; i < N; i++) revfac[i] = revfac[i - 1] * rev[i] % MOD;


    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i]; a[n + 1] = a[1];

    cout << solve() << '\n';


}