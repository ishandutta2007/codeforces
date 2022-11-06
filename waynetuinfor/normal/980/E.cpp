#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int fa[21][maxn], dep[maxn];
vector<int> graf[maxn];
bool v[maxn];

void dfs(int x, int p) {
    fa[0][x] = p;
    dep[x] = p ? dep[p] + 1 : 0;
    for (int i = 1; fa[i - 1][x]; ++i) fa[i][x] = fa[i - 1][fa[i - 1][x]];
    for (int u : graf[x]) if (u != p) dfs(u, x);
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        graf[a].push_back(b), graf[b].push_back(a);
    }
    dfs(n, 0);
    int occ = 0;
    for (int i = n; i >= 1; --i) if (!v[i]) {
        int x = i, t = 0;
        for (int j = 20; j >= 0; --j) if (fa[j][x] && !v[fa[j][x]]) x = fa[j][x], t ^= (1 << j);
        if (occ + t + 1 > n - k) continue;
        v[i] = true;
        ++occ;
        x = i;
        while (t--) v[x = fa[0][x]] = true, ++occ;
    }
    for (int i = 1; i <= n; ++i) if (!v[i]) printf("%d ", i); puts("");
    return 0;
}