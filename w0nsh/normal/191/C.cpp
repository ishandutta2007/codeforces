#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

std::vector<VI> g;
VI parent, level, head;
int dfs(int v) {
    int sz = 1;
    int max_sz = 0;
    for (auto& ch : g[v]) {
        if (ch == parent[v]) continue;
        parent[ch] = v;
        level[ch] = level[v] + 1;
        int cur_sz = dfs(ch);
        sz += cur_sz;
        if (cur_sz > max_sz) std::swap(g[v][0], ch);
    }
    return sz;
}

void decomp(int v, int h) {
    head[v] = h;
    for (auto& ch : g[v]) {
        if (ch == parent[v]) continue;
        decomp(ch, ch == g[v][0] ? h : ch);
    }
}

int lca(int a, int b) {
    for (; head[a] != head[b]; b = parent[head[b]])
        if (level[head[a]] > level[head[b]])
            std::swap(a, b);
    return level[a] < level[b] ? a : b;
}

VI add, ans;
int dfs2(int v) {
    ans[v] = add[v];
    for (auto& ch : g[v]) {
        if (ch == parent[v]) continue;
        ans[v] += dfs2(ch);
    }
    return ans[v];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    g.resize(n);
    parent.resize(n);
    level.resize(n);
    head.resize(n);
    std::vector<PII> edges;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(MP(a, b));
    }

    dfs(0);
    decomp(0, 0);
    VI vert(n-1);
    for (int i = 0; i < n-1; ++i)
        vert[i] = (parent[edges[i].X] == edges[i].Y ? edges[i].X : edges[i].Y);
    add.resize(n);
    ans.resize(n);

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;b--;
        add[a]++;
        add[b]++;
        add[lca(a, b)] -= 2;
    }
    
    dfs2(0);
    for (auto x : vert) std::cout << ans[x] << " ";

    return 0;
}