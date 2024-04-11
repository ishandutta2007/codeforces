#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define ll long long

int pr[110], top, mu[110]; bool np[110];
void sieve () {
    mu[1] = 1; int i, j;
    for (i = 2; i <= 100; i++) {
        if (!np[i]) pr[++top] = i, mu[i] = -1;
        for (j = 1; j <= top; j++) {
            if (i * pr[j] > 100) break;
            np[i * pr[j]] = 1;
            if (i % pr[j] == 0) { mu[i * pr[j]] = 0; break; }
            mu[i * pr[j]] = -mu[i];
        }
    }
}

const ll inf = ((ll)(1e18)) + 5;
bool chk (__int128 x, __int128 y) { return x * y <= inf; }
ll qpow (ll x, int y) {
    ll ret = 1;
    while (y) {
        if (y & 1) {
            if (chk(ret, x)) ret *= x;
            else return inf;
        }
        if (y > 1) {
            if (chk(x, x)) x *= x;
            else return inf;
        }
        y >>= 1;
    }
    return ret;
}

ll sav[66][100100]; int cnt[66];

int main () {
    sieve();
    for (int i = 4; i <= 63; i++) {
        for (cnt[i] = 1; qpow(cnt[i], i) < inf; cnt[i]++)
            sav[i][cnt[i]] = qpow(cnt[i], i);
        sav[i][cnt[i]] = inf;
    }
    int T; scanf("%d", &T);
    while (T--) {
        ll n; scanf("%lld", &n);
        ll ans = 0, g[64] = {};
        for (int i = 1; i <= 63; i++) {
            if (i <= 3) {
                ll L = 1, R = n;
                while (L <= R) {
                    ll mid = (L + R) >> 1;
                    if (qpow(mid, i) > n) R = mid - 1;
                    else g[i] = mid, L = mid + 1;
                }
            }
            else g[i] = upper_bound(sav[i] + 1, sav[i] + cnt[i] + 1, n) - sav[i] - 1;
            --g[i];
            ans += g[i] * mu[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}