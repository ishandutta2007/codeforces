#include <bits/stdc++.h>
#define int long long

using namespace std;

struct edge{
    int v, u, w;
    edge() {}
    edge(int v, int u, int w): v(v), u(u), w(w) {}
};

const int N = 3e5 + 7;
vector <int> g[N];
vector <edge> ee;
int a[N], b[N];
bool ok[N];
set <pair <int, int>, greater <pair <int, int>>> active;
int sz[N], par[N];

int get_par(int v) {
    if (par[v] == v) return v;
    return get_par(par[v]);
}

bool merge(int v, int u) {
    v = get_par(v);
    u = get_par(u);
    if (v == u) return 0;
    if (sz[v] > sz[u]) swap(v, u);
    par[v] = u;
    sz[u] += sz[v];
    return 1;
}

void init() {
    for (int i = 0; i < N; i++) {
        sz[i] = 1;
        par[i] = i;
    }
}

bool cmp(edge a, edge b) {
    return (a.w > b.w);
}

signed main() {
    init();
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(ok, 0, sizeof(ok));
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int summ = 0;
    int all = 0;
    for (int i = 1; i <= m; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int x;
            cin >> x;
            edge e(x, n + i, a[i] + b[x]);
            all += a[i] + b[x];
            //g[n + i].push_back(ee.size());
            //g[x].push_back(ee.size());
            ee.push_back(e);
        }
    }
    sort(ee.begin(), ee.end(), cmp);
    for (auto elem : ee) {
        int v = elem.v, u = elem.u, w = elem.w;
        if (merge(v, u)) summ += w;
    }
    cout << all - summ << endl;
    return 0;
}