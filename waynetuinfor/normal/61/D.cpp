#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<pair<int, int>> graf[maxn];
int dia, rt, sz[maxn];
long long ans;

void dfs(int now, int fa, int d) {
    if (d > dia) dia = d, rt = now;
    for (auto u : graf[now]) if (u.first != fa) {
        dfs(u.first, now, d + u.second);
    }
}

void dfssz(int now, int fa) {
    if (now == rt) ++sz[now];
    for (auto u : graf[now]) if (u.first != fa) {
        dfssz(u.first, now);
        sz[now] += sz[u.first];
    }
}

void dfsans(int now, int fa) {
    for (auto u : graf[now]) if (u.first != fa) {
        if (sz[u.first]) ans += u.second;
        else ans += 2 * u.second;
        dfsans(u.first, now);
    }    
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        graf[a].emplace_back(b, c); graf[b].emplace_back(a, c);
    }
    dfs(1, 0, 0); 
    dfssz(1, 0); dfsans(1, 0);
    printf("%lld\n", ans);
    return 0;
}