#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int sz[maxn];

void dfs(int x) {
    sz[x] = (int)g[x].size() == 0;
    for (const int &u : g[x]) {
        dfs(u);
        sz[x] += sz[u];
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int p; scanf("%d", &p);
        g[p - 1].push_back(i);
    }
    dfs(0);
    sort(sz, sz + n);
    for (int i = 0; i < n; ++i) printf("%d ", sz[i]);
    puts("");
    return 0;
}