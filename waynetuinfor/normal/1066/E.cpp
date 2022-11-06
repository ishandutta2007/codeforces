#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int mod = 998244353;
char s[maxn], t[maxn];
int pw[maxn], c[maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) pw[i] = pw[i - 1] * 2 % mod;
    c[0] = (t[0] == '1');
    for (int i = 1; i < m; ++i) c[i] = c[i - 1] + (t[i] == '1');
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') continue;
        int k = pw[n - i - 1];
        int x = i + m - n;
        if (x >= 0) (ans += k * 1ll * c[x] % mod) %= mod;
    }
    printf("%d\n", ans);
    return 0;
}