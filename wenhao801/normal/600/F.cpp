#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define fr first
#define se second

const int MAXN = 100100;
int a, b, m, mx, ans[MAXN]; vector <int> E[MAXN];
pair <int, int> e[MAXN];

bool vis[MAXN][2];
void solve(int x, int k, vector <int> val, bool t) {
    ans[k] = val[t];
    for (auto i: E[x]) if (ans[i] == val[t] && i != k) { solve(e[i].fr ^ e[i].se ^ x, i, val, !t); break; }
}

int main() {
    a = read(), b = read(), m = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read(); e[i] = {u, v + a};
        E[u].push_back(i), E[v + a].push_back(i);
    }
    for (i = 1; i <= a + b; i++) mx = max(mx, int(E[i].size()));
    printf("%d\n", mx);
    for (i = 1; i <= m; i++) {
        for (int j = 1; j <= mx; j++) vis[j][0] = vis[j][1] = 0;
        for (auto k: E[e[i].fr]) vis[ans[k]][0] = 1;
        for (auto k: E[e[i].se]) vis[ans[k]][1] = 1;
        for (int j = 1; j <= mx; j++) if (!vis[j][0] && !vis[j][1]) {
            ans[i] = j;
            break;
        }
        if (ans[i]) continue;
        int A, B;
        for (int j = 1; j <= mx; j++) if (vis[j][0] && !vis[j][1]) { A = j; break; }
        for (int j = 1; j <= mx; j++) if (!vis[j][0] && vis[j][1]) { B = j; break; }
        ans[i] = B;
        for (auto k: E[e[i].se]) if (ans[k] == B) { solve(e[k].fr ^ e[k].se ^ e[i].se, k, {A, B}, 0); break; }
    }
    for (i = 1; i <= m; i++) printf("%d ", ans[i]);
    return 0;
}