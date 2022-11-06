#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<pair<int, int>> graf[maxn];
vector<int> vans[maxn];
int z[maxn];

void dfs(int now, int fa, int p) {
    int t = 0;
    for (auto u : graf[now]) if (u.first != fa) {
        while (t == p) ++t;
        z[u.second] = t++;
        dfs(u.first, now, t - 1);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d %d", &a, &b); --a; --b;
        graf[a].emplace_back(b, i); graf[b].emplace_back(a, i);
    }
    dfs(0, -1, -1);
    int kans = *max_element(z, z + n - 1) + 1;
    for (int i = 0; i < n - 1; ++i) vans[z[i]].push_back(i);
    printf("%d\n", kans);
    for (int i = 0; i < kans; ++i) {
        printf("%d ", vans[i].size());
        for (int j = 0; j < vans[i].size(); ++j) printf("%d ", vans[i][j] + 1);
        puts("");
    }
    return 0;
}