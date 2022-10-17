#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define fr first
#define se second
#define vi vector <int>
#define size(v) (int(v.size()))
const int MAXN = 150050, mod = 998244353;
map <int, int> vis;
int n, x, a[MAXN], ans, h, p2[MAXN];

int solve (vi u, vi v, int cur) {
    // printf("solve %d %d %d | %d\n", size(u), size(v), cur, ans);
    if (u.empty() || v.empty()) return 0;
    if (cur < 0) return 1ll * (p2[size(u)] - 1) * (p2[size(v)] - 1) % mod;
    vi tu[2], tv[2];
    for (auto i: u) tu[(i >> cur) & 1].push_back(i);
    for (auto i: v) tv[(i >> cur) & 1].push_back(i);
    if ((x >> cur) & 1) {
        int ret = 0;
        ret = (ret + 1ll * (p2[size(tu[0])] - 1) * (p2[size(tv[0])] - 1)) % mod;
        ret = (ret + 1ll * (p2[size(tu[1])] - 1) * (p2[size(tv[1])] - 1)) % mod;
        int resu = solve(tu[0], tv[1], cur - 1), resv = solve(tu[1], tv[0], cur - 1);
        ret = (ret + 1ll * resu * (p2[size(tu[1])] + p2[size(tv[0])] - 1)) % mod;
        ret = (ret + 1ll * resv * (p2[size(tu[0])] + p2[size(tv[1])] - 1)) % mod;
        ret = (ret + 1ll * resu * resv) % mod;
        return ret;
    }
    else return (solve(tu[0], tv[0], cur - 1) + solve(tu[1], tv[1], cur - 1)) % mod;
}

void pre (vi v) {
    vi vec[2];
    for (auto i: v) vec[(i >> (h - 1)) & 1].push_back(i);
    ans = (ans + p2[size(vec[0])] - 1) % mod; ans = (ans + p2[size(vec[1])] - 1) % mod;
    ans = (ans + solve(vec[0], vec[1], h - 2)) % mod;
}

int main () {
    n = read(), x = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    p2[0] = 1; for (i = 1; i <= n; i++) p2[i] = (p2[i - 1] << 1) % mod;
    if (!x) {
        for (i = 1; i <= n; i++) ++vis[a[i]];
        for (auto i: vis) ans = (ans + p2[i.se] - 1) % mod;
        printf("%d\n", (ans + mod) % mod);
        return 0;
    }
    for (i = x; i; i >>= 1) ++h;
    sort(a + 1, a + n + 1, [](int u, int v) { return (u >> h) < (v >> h); });
    vi v = {a[1]};
    for (i = 2; i <= n; i++) {
        if ((a[i - 1] >> h) != (a[i] >> h)) pre(v), v.clear();
        v.push_back(a[i]);
    }
    pre(v); printf("%d\n", (ans + mod) % mod);
    return 0;
}