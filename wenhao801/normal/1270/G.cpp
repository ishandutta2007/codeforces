#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000;
vector <int> E[MAXN], ans;
int n;

bool vis[MAXN]; int fa[MAXN];
void dfs (int x, int f) {
    vis[x] = 1; fa[x] = f;
    for (auto i: E[x]) {
        if (i == f) { f = 0; continue; }
        if (vis[i]) {
            for (int j = x; j != i; j = fa[j]) ans.push_back(j);
            ans.push_back(i);
            return;
        }
        dfs(i, x);
        if (!ans.empty()) return;
    }
}

void clear () { ans.clear(); for (int i = 1; i <= n; i++) E[i].clear(), vis[i] = 0; }

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j, fin = 0;
        for (i = 1; i <= n; i++) {
            j = i - read(), E[i].push_back(j), E[j].push_back(i);
            if (i == j) fin = i;
        }
        if (fin) { printf("1\n%d\n", fin); clear(); continue; }
        for (i = 1; i <= n; i++) if (!vis[i]) {
            dfs(i, 0);
            if (!ans.empty()) {
                printf("%d\n", ans.size());
                for (auto i: ans) printf("%d ", i);
                putchar('\n'); break;
            }
        }
        clear();
    }
    return 0;
}