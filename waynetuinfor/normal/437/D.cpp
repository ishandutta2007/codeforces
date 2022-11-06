#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int a[maxn];
bool ok[maxn];

struct Dsu {
    int par[maxn], sz[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        if (x == y) return;
        x = find(x); y = find(y);
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x; sz[x] += sz[y];
    }
    int size(int x) {
        return sz[find(x)];
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vec.push_back(make_pair(a[i], i));
    }
    sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dsu.init();
    long long ans = 0;
    for (auto i : vec) {
        ok[i.second] = true;
        for (int u : G[i.second]) {
            if (!ok[u]) continue;
            if (dsu.find(i.second) == dsu.find(u)) continue;
            ans += (long long)dsu.size(i.second) * (long long)dsu.size(u) * (long long)i.first;
            dsu.merge(i.second, u);
        }
    }
    cout << fixed << setprecision(20) << (long double)ans / (long double)((long long)n * (long long)(n - 1) / 2) << endl;
    return 0;
}