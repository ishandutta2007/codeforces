#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5, mod = 1e9 + 123, p = 131;
int pw[maxn], hs[26][maxn];
vector<int> ps[26];
char s[maxn];

void predo(const char *s, int c, int *z) {
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) z[i] = (z[i - 1] * 1ll * p % mod + (s[i] - 'a' == c)) % mod;
}

int ghash(int *z, int l, int r) {
    return (z[r] - pw[r - l + 1] * 1ll * z[l - 1] % mod + mod) % mod;
}

int main() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) pw[i] = pw[i - 1] * 1ll * p % mod;
    int n, m; scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int c = 0; c < 26; ++c) predo(s, c, hs[c]);
    for (int i = 1; i <= n; ++i) ps[s[i] - 'a'].push_back(i);
    while (m--) {
        int x, y, k; scanf("%d %d %d", &x, &y, &k);
        bool ans = true;
        for (int c = 0; c < 26; ++c) {
            auto it = lower_bound(ps[c].begin(), ps[c].end(), x);
            if (it == ps[c].end() || *it >= x + k) continue;
            int z = *it;
            ans &= ghash(hs[c], x, x + k - 1) == ghash(hs[s[z - x + y] - 'a'], y, y + k - 1);
        }
        if (ans) puts("YES");
        else puts("NO");
    } 
    return 0;
}