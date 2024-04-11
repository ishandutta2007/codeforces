#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000;
vector <int> E[MAXN], rE[MAXN];
int n, m, cur; bool ans[MAXN], vis[MAXN];

void solve () {
    for (++cur; cur <= n && vis[cur]; ++cur);
    if (cur > n) return;
    int now = cur;
    ans[now] = vis[now] = 1;
    for (auto i: E[now]) vis[i] = 1;
    solve();
    for (auto i: rE[now]) if (ans[i]) { ans[now] = 0; break; }
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        E[u].emplace_back(v); rE[v].emplace_back(u);
    }
    solve();
    int s = 0; for (i = 1; i <= n; i++) s += ans[i];
    printf("%d\n", s);
    for (i = 1; i <= n; i++) if (ans[i]) printf("%d ", i);
    putchar('\n');
    return 0;
}