#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int fa[maxn], a[maxn], c[maxn];
int fr[maxn];
bool v[maxn], us[maxn];

void init() {
    for (int i = 0; i < maxn; ++i)
        fa[i] = i;
}

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    fa[x] = y;
}

vector<int> cycle;

void dfs(int x, int p) {
    if (cycle.size() > 0) return;
    fr[x] = p;
    v[x] = true;
    if (v[a[x]]) {
        int y = x;
        while (true) {
            cycle.push_back(y);
            if (y == a[x]) break;
            y = fr[y];
        }
        return;
    }
    dfs(a[x], x);
}

int main() {
    int n; scanf("%d", &n);
    init();
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), merge(i, a[i]);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) if (!us[find(i)]) {
        us[find(i)] = true;
        cycle.clear();
        dfs(i, -1);
        int mc = maxn;
        for (int j : cycle) mc = min(mc, c[j]);
        ans += mc;
    }
    printf("%lld\n", ans);
    return 0;
}