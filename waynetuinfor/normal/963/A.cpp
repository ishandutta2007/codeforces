#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, mod = 1e9 + 9;
char s[maxn];

int fpow(int a, int n) {
    int r = 1;
    for (; n; n >>= 1) {
        if (n & 1) r = r * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return r;
}

int main() {
    int n, a, b, k; scanf("%d %d %d %d", &n, &a, &b, &k);
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < min(k, n + 1); ++i) {
        int x = (s[i] == '+' ? 1 : mod - 1);
        int ast = fpow(a, n - i), bst = fpow(b, i);
        int s0 = ast * 1ll * bst % mod;
        // printf("s0 = %d\n", s0);
        int c = (n - i) / k + 1;
        // printf("c = %d\n", c);
        int r = fpow(b, k) * 1ll * fpow(fpow(a, k), mod - 2) % mod;
        // printf("r = %d\n", r);
        int p = s0 * 1ll * ((fpow(r, c) - 1 + mod) % mod) % mod;
        p = p * 1ll * fpow(r - 1, mod - 2) % mod;
        if (r == 1) p = s0 * 1ll * c % mod;
        // printf("p = %d\n", p);
        ans = (ans + p * 1ll * x % mod) % mod;
    }
    printf("%d\n", ans);
    return 0;
}