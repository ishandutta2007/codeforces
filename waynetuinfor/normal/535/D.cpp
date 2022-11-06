#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5, mod = 1e9 + 7;
char p[maxn];
int x[maxn];

namespace hasht {
    static const int mod = 1e9 + 123, p = 131;
    int dat[maxn], pw[maxn];
    void init(const char *s) {
        dat[0] = s[0];
        int n = strlen(s);
        for (int i = 1; i < n; ++i) dat[i] = (dat[i - 1] * 1ll * p % mod + s[i]) % mod;
        pw[0] = 1;
        for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 1ll * p % mod;
    }
    int hashv(int l, int r) {
        if (l == 0) return dat[r];
        return ((dat[r] - pw[r - l + 1] * 1ll * dat[l - 1] % mod) % mod + mod) % mod;
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    scanf("%s", p);
    for (int i = 0; i < m; ++i) scanf("%d", x + i), --x[i];
    hasht::init(p);
    int r = -1, c = 0, z = strlen(p);
    for (int i = 0; i < m; ++i) {
        if (r >= x[i]) {
            int overlap = r - x[i] + 1;
            if (hasht::hashv(z - overlap, z - 1) != hasht::hashv(0, overlap - 1)) return 0 * puts("0");
            c += z - overlap;
            r = x[i] + z - 1;
        } else {
            r = x[i] + z - 1;
            c += z;
        }
    }
    int ans = 1;
    for (int i = 0; i < n - c; ++i) ans = ans * 26ll % mod;
    printf("%d\n", ans);
    return 0;
}