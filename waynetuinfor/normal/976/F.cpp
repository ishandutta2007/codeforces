#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 5;
int deg[maxn], minc[maxn];
bool used[maxn];
vector<int> ans[maxn];

struct dinic {
    static const int inf = 1e9;
    struct edge {
        int dest, cap, flow, rev, idx;
        bool inc;
        edge(int a, int b, int c, int e, bool d): dest(a), cap(b), rev(c), flow(0), inc(d), idx(e) {}
        int operator()(int offset) const { return inc ? cap + offset : cap; }
    };
    vector<edge> graf[maxn];
    int level[maxn], qu[maxn], l, r;
    void add_edge(int from, int dest, int cap, int idx, bool inc) {
        graf[from].emplace_back(dest, cap, graf[dest].size(), idx, inc);
        graf[dest].emplace_back(from, 0, graf[from].size() - 1, idx, inc);
    }
    bool bfs(int s, int t, int offset) {
        memset(level, -1, sizeof(level));
        level[s] = 0;
        l = r = 0;
        qu[r++] = s;
        while (l < r) {
            int x = qu[l++];
            for (edge &e : graf[x]) if (e(offset) > e.flow && level[e.dest] == -1) {
                level[e.dest] = level[x] + 1;
                qu[r++] = e.dest;
            }
        }
        return level[t] != -1;
    }
    int dfs(int x, int t, int offset, int low) {
        if (x == t) return low;
        int r = 0;
        for (edge &e : graf[x]) if (e(offset) > e.flow && level[e.dest] == level[x] + 1) {
            int f = dfs(e.dest, t, offset, min(low - r, e(offset) - e.flow));
            e.flow += f;
            graf[e.dest][e.rev].flow -= f;
            r += f;
        }
        if (r == 0) level[x] = -1;
        return r;
    }
    int operator()(int s, int t, int offset) {
        static int r = 0;
        for (; bfs(s, t, offset); r += dfs(s, t, offset, inf));
        return r;
    }
} flow;

int main() {
    int n1, n2, m; scanf("%d %d %d", &n1, &n2, &m);
    int s = 0, t = n1 + n2 + 1;
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        flow.add_edge(a, b + n1, 1, i, false);
        ++deg[a], ++deg[b + n1];
    }
    int mindeg = maxn;
    for (int i = 1; i <= n1 + n2; ++i) mindeg = min(mindeg, deg[i]);
    for (int i = 1; i <= n1; ++i) flow.add_edge(s, i, deg[i] - mindeg, -1, true);
    for (int i = 1; i <= n2; ++i) flow.add_edge(i + n1, t, deg[i + n1] - mindeg, -1, true);
    for (int i = 0; i <= mindeg; ++i) {
        int f = flow(s, t, i);
        minc[mindeg - i] = m - f;
        memset(used, false, sizeof(used));
        for (int j = 1; j <= n1; ++j) {
            for (auto e : flow.graf[j]) if (e.dest > n1 && e.dest <= n1 + n2) {
                if (e.flow == 1) used[e.idx] = true;
            } 
        }
        for (int j = 0; j < m; ++j) if (!used[j]) ans[mindeg - i].push_back(j);
    } 
    for (int i = 0; i <= mindeg; ++i) {
        assert(minc[i] == (int)ans[i].size());
        printf("%d ", minc[i]);
        for (int j = 0; j < ans[i].size(); ++j) printf("%d ", ans[i][j] + 1);
        puts("");
    }
    return 0;
}