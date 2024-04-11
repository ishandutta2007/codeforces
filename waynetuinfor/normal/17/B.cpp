#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int q[maxn];
bool v[maxn];

struct Dsu {
    int par[maxn], sz[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y]; par[y] = x;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> q[i];
    dsu.init();
    int m; cin >> m;
    vector<pair<int, pair<int, int>>> edge;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edge.begin(), edge.end());
    int node = 1, ans = 0;
    for (auto e : edge) {
        if (v[e.second.second]) continue;
        int x = dsu.find(e.second.first), y = dsu.find(e.second.second);
        if (x == y) continue;
        v[e.second.second] = true;
        ++node; ans += e.first;
        dsu.merge(x, y);
    }
    if (node < n) return cout << "-1" << endl, 0;
    cout << ans << endl;
    return 0;
}