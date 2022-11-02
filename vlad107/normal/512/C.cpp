#include <bits/stdc++.h>

using namespace std;

const int N = 500500;
const int C = 3e4;

struct Edge {
    int from, to, cap, flow;
    Edge() {}
    Edge(int from, int to, int cap) : from(from), to(to), cap(cap), flow(0) {}
};

vector<int> h[N], e[N], v[2], w;
vector<Edge> g;
int n, m, ss, ff, isp[N], a[N], pr[N], used[N];

void add(int x, int y, int cap) {
    e[x].push_back(g.size());
    g.push_back(Edge(x, y, cap));
    e[y].push_back(g.size());
    g.push_back(Edge(y, x, 0));
}

bool way() {
    for (int i = 0; i <= ff; i++) pr[i] = -1;
    queue<int> q;
    q.push(ss);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size(); i++) {
            int id = e[x][i];
            int y = g[id].to;
            if ((g[id].flow < g[id].cap) && (pr[y] < 0)) {
                pr[y] = id;
                q.push(y);
            }
        }
    }
    if (pr[ff] == -1) return false;
    for (int i = ff; i != ss;) {
        int id = pr[i];
        g[id].flow++;
        g[id ^ 1].flow--;
        i = g[id].from;
    }
    return true;
}

void dfs(int x) {
    used[x] = true;
    w.push_back(x);
    for (int i = 0; i < h[x].size(); i++) {
        int y = h[x][i];
        if (!used[y]) dfs(y);
    }
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) {
            v[0].push_back(i);
        } else {
            v[1].push_back(i);
        }
    }
    for (int i = 2; i < C; i++) isp[i] = true;
    for (int i = 2; i < C; i++) {
        if (isp[i]) {
            for (int j = i + i; j < C; j += i) isp[j] = false;
        }
    }
    if (v[0].size() != v[1].size()) {
        puts("Impossible");
        return 0;
    }
    for (int i = 0; i < v[0].size(); i++) {
        for (int j = 0; j < v[1].size(); j++) {
            if (isp[a[v[0][i]] + a[v[1][j]]]) {
                add(v[0][i], v[1][j], 1);
            }
        }
    }
    ss = n;
    ff = n + 1;
    for (int i = 0; i < v[0].size(); i++) add(ss, v[0][i], 2);
    for (int i = 0; i < v[1].size(); i++) add(v[1][i], ff, 2);
    while (way()) {
//      cerr << "---" << endl;
    }
    for (int i = 0; i < e[ss].size(); i++) {
        int id = e[ss][i];
        if (g[id].flow != g[id].cap) {
            puts("Impossible");
            return 0;
        }
    }
//  for (int i = 0; i < g.size(); i++) cerr << g[i].from << " " << g[i].to << " " << g[i].flow << " " << g[i].cap << endl;
    for (int i = 0; i < v[0].size(); i++) {
        int x = v[0][i];
//      cerr << x << endl;
        for (int j = 0; j < e[x].size(); j++) {
            int id = e[x][j];
            if (g[id].flow > 0) {
                int y = g[id].to;
                if (y == ff) continue;
//              cerr << x << " " << y << endl;
                h[x].push_back(y);
                h[y].push_back(x);
            }
        }
    }
    memset(used, 0, sizeof(used));
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            w.clear();
            dfs(i);
            ans.push_back(w);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto u : ans) {
        printf("%d ", (int)u.size());
        for (auto v : u) printf("%d ", 1 + v);
        puts("");
    }
}