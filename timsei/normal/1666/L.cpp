#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, m, S, vis[MAXN], fa[MAXN], bel[MAXN];
vector<int> g[MAXN], ans1, ans2;

void DFS(int u, int rt) {
    vis[u] = 1;
    bel[u] = rt;
    for (auto v : g[u]) {
        if (vis[v]) continue;
        fa[v] = u;
        DFS(v, rt);
    }
}

void solve() {
    read(n); read(m); read(S);
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        g[u].push_back(v);
    }
    vis[S] = 1;
    bel[S] = S;
    for (auto v : g[S]) {
        if (vis[v]) continue;
        fa[v] = S;
        DFS(v, v);
    }
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) continue;
        for (auto v : g[u]) {
            if (!vis[v] || v == S) continue;
            if (bel[u] != bel[v]) {
                if (u == S && fa[v] == S) continue;
                for (int x = v; x; x = fa[x]) {
                    ans1.push_back(x);
                }
                ans2.push_back(v);
                for (int x = u; x; x = fa[x]) {
                    ans2.push_back(x);
                }
                reverse(ans1.begin(), ans1.end());
                reverse(ans2.begin(), ans2.end());
                puts("Possible");
                printf("%d\n", ans1.size());
                for (auto x : ans1) {
                    printf("%d ", x);
                }
                printf("\n");
                printf("%d\n", ans2.size());
                for (auto x : ans2) {
                    printf("%d ", x);
                }
                printf("\n");
                return;
            }
        }
    }
    puts("Impossible");
}

int main() {
    solve();
    return 0;
}