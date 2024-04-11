#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

const int MAXN = 300010;

int N;
ll F[300100];
ll fac[300100];
ll fnv[300100];

ll ipow(ll a, ll n) {
    if (!n) return 1;
    ll t = ipow(a, n / 2);
    return t * t % MOD * (n % 2 ? a : 1) % MOD;
}

ll comb(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * fnv[r] % MOD * fnv[n - r] % MOD;
}

int main() {
    int ttt;

    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        F[i] = (F[i - 2] * (i - 1) + F[i - 1]) % MOD;
    }
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    fnv[MAXN] = ipow(fac[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; i--) {
        fnv[i] = fnv[i + 1] * (i + 1) % MOD;
    }

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d", &N);
        ll ans = 0;
        ll t = 1;
        for (int k = 0; k * 4 <= N; k++) {
            ans += comb(N - 2 * k, 2 * k) * F[N - 4 * k] % MOD * t % MOD;
            t = t * 2 * (2 * k + 1) % MOD;
        }
        printf("%lld\n", ans % MOD);
    }

    return 0;
}