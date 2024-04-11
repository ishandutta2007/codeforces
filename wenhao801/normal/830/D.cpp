#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int mod = 1e9 + 7;
inline int add (int u, int v) { u += v; if (u >= mod) u -= mod; return u; }
inline void ADD (int &u, int v) { u = add(u, v); }
inline int mul (int u, int v) { return 1ll * u * v % mod; }

int f[440][440];
int F (int x, int k) {
    if (!k) return 1;
    if (x == 1) return k == 1;
    if (f[x][k] != -1) return f[x][k];
    f[x][k] = 0;
    for (int i = 0; i <= k; i++) ADD(f[x][k], mul(F(x - 1, i), F(x - 1, k - i)));
    f[x][k] = mul(f[x][k], k << 1 | 1);
    for (int i = 0; i < k; i++) ADD(f[x][k], mul(F(x - 1, i), F(x - 1, k - 1 - i)));
    for (int i = 0; i <= k + 1; i++) ADD(f[x][k], 1ll * F(x - 1, i) * F(x - 1, k + 1 - i) % mod * k % mod * (k + 1) % mod);
    return f[x][k];
}

int main () {
    int n; scanf("%d", &n);
    memset(f, -1, sizeof(f));
    printf("%d\n", F(n, 1));
    return 0;
}