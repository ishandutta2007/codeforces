#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> graf[maxn];
int a[maxn];
bool v[maxn], vi[maxn];

struct djset {
    int p[maxn], sz[maxn];
    void init(int n) { for (int i = 0; i < n; ++i) sz[i] = 1, p[i] = i; }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    void merge(int u, int v) { p[u = find(u)] = (v = find(v)); if (v != u) sz[v] += sz[u]; }
    int size(int u) { return sz[find(u)]; }
} djs;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graf[a].push_back(b); graf[b].push_back(a);
    }
    djs.init(n);
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    long long vmax = 0;
    for (int i = 0; i < n; ++i) {
        int now = o[i];
        for (int u : graf[now]) if (v[u]) {
            vmax += a[now] * 1ll * djs.size(now) * 1ll * djs.size(u);
            djs.merge(now, u);
        }
        v[now] = true;
    }
    djs.init(n);
    memset(v, false, sizeof(v));
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return a[i] > a[j]; });
    long long vmin = 0;
    for (int i = 0; i < n; ++i) {
        int now = o[i];
        for (int u : graf[now]) if (v[u]) {
            vmin += a[now] * 1ll * djs.size(now) * 1ll * djs.size(u);
            djs.merge(now, u);
        }
        v[now] = true;
    }
    cout << vmax - vmin << endl;
    return 0;
}