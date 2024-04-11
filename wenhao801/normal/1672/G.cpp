#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 2020, mod = 998244353;
int n, m; char a[MAXN][MAXN];

bool val[MAXN << 1], vis[MAXN << 1]; vector <int> E[MAXN << 1];
int cnt, back;

void dfs (int x, int fa) {
    vis[x] = 1; cnt += val[x];
    for (auto i: E[x]) if (i != fa && vis[i]) ++back;
    for (auto i: E[x]) if (!vis[i]) dfs(i, x);
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    if (n % 2 == 0 && m % 2 == 0) {
        int ans = 1;
        for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) ans = (ans << (a[i][j] == '?')) % mod;
        printf("%d\n", ans); return 0;
    }
    if (m % 2 == 0) {
        for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) if (i < j) swap(a[i][j], a[j][i]);
        swap(n, m);
    }
    if (n % 2 == 0) {
        int u = 1, v = 1;
        for (i = 1; i <= n; i++) {
            int tmp = 0, cc = 0;
            for (j = 1; j <= m; j++) {
                if (a[i][j] == '?') ++cc;
                else tmp ^= a[i][j] - '0';
            }
            if (!cc) { if (!tmp) v = 0; else u = 0; }
            else {
                while (--cc) u = (u << 1) % mod, v = (v << 1) % mod;
            }
        }
        printf("%d\n", (u + v) % mod);
        return 0;
    }
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
        if (a[i][j] != '?') val[i] ^= a[i][j] - '0', val[n + j] ^= a[i][j] - '0';
        else E[i].emplace_back(n + j), E[n + j].emplace_back(i);
    }
    
    int u = 1, v = 1;
    for (i = 1; i <= n + m; i++) if (!vis[i]) {
        cnt = back = 0; dfs(i, 0);
        if (cnt & 1) { u = 0; break; }
        while (back--) u = (u << 1) % mod;
    }
    
    for (i = 1; i <= n + m; i++) vis[i] = 0, val[i] ^= 1;
    for (i = 1; i <= n + m; i++) if (!vis[i]) {
        cnt = back = 0; dfs(i, 0);
        if (cnt & 1) { v = 0; break; }
        while (back--) v = (v << 1) % mod;
    }
    printf("%d\n", (u + v) % mod);
    return 0;
}