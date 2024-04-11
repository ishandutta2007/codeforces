#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> par;
vector<int> dep;
vector<int> timeIn;
vector<int> timeOut;

int timer = 0;
int depth = 0;
void dfs(int v, int p) {
    par[0][v] = p;
    for (int i = 1; i < par.size(); ++i) {
        par[i][v] = par[i - 1][par[i - 1][v]];
    }
    timeIn[v] = ++timer;
    dep[v] = ++depth;
    for (auto c : adj[v]) {
        if (c != p) {
            dfs(c, v);
        }
    }
    timeOut[v] = ++timer;
    --depth;
}

bool isAnc(int a, int b) {
    return timeIn[a] <= timeIn[b] && timeOut[a] >= timeOut[b];
}

int dist(int a, int b) {
    if (isAnc(a, b)) return dep[b] - dep[a];
    if (isAnc(b, a)) return dep[a] - dep[b];

    int c = a;
    for (int i = par.size() - 1; i >= 0; --i) {
        if (!isAnc(par[i][c], b)) {
            c = par[i][c];
        }
    }
    c = par[0][c];
    return (dep[a] - dep[c]) + (dep[b] - dep[c]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    par.assign(32 - __builtin_clz(n), vector<int>(n + 1));
    timeIn.resize(n + 1);
    timeOut.resize(n + 1);
    dep.resize(n + 1);
    dfs(1, 0);
    timeOut[0] = ++timer;

    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        string sol = "NO";
        for (auto i :
                {dist(a, b), dist(a, x) + 1 + dist(y, b), dist(a, y) + 1 + dist(x, b)}) {
            if (i <= k && i % 2 == k % 2) {
                sol = "YES";
            }
        }
        cout << sol << '\n';
    }
}