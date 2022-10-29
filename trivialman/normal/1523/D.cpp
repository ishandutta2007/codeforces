#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
typedef long long LL;
const int N = 2e5 + 5, M = 65;
mt19937 rng(time(0));

int n, m, p;
int bit[M], cnt[(1 << 15) + 5];
LL a[N], ans = 0;

int main() {
    scanf("%d%d%d", &n, &m, &p);
    rep(i, 1, n) {
        char x[M];
        scanf("%s", x);
        a[i] = 0;
        rep(j, 0, m - 1) if (x[j] == '1') a[i] |= (1ll << j);
    }

    int th = (n + 1) / 2;
    rep(sample, 1, 30) {
        LL x = a[rng() % n + 1];
        int tot = 0;
        rep(i, 0, m - 1) if (x >> i & 1) bit[tot++] = i;
        rep(i, 0, (1 << tot) - 1) cnt[i] = 0;
        rep(i, 1, n) {
            int mask = 0;
            rep(j, 0, tot - 1) if (a[i] >> bit[j] & 1) mask |= 1 << j;
            cnt[mask]++;
        }

        for (int i = 1; i < (1 << tot); i <<= 1)
            for (int j = 0; j < (1 << tot); j += i << 1)
                rep(k, 0, i - 1) cnt[j + k] += cnt[j + k + i];

        rep(mask, 0, (1 << tot) - 1) if (cnt[mask] >= th && __builtin_popcount(mask) > __builtin_popcountll(ans)) {
            ans = 0;
            rep(j, 0, tot - 1) if (mask >> j & 1) ans |= 1ll << bit[j];
        }
    }

    rep(i, 0, m - 1) cout << (ans >> i & 1);
    return 0;
}