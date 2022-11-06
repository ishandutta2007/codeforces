#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 5;
int a[maxn], b[maxn];
bool v[maxn], ans[maxn];

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    void merge(int u, int v) { p[find(u)] = find(v); }
} djs;

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    djs.init();
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            int f = i, s = j;
            if (a[f] > a[s]) swap(f, s);
            if (a[s] < b[f] && a[s] > a[f] && b[s] > b[f]) { 
                // cout << "bang " << f << " " << s << endl;
                djs.merge(f << 1, s << 1 | 1), djs.merge(f << 1 | 1, s << 1); 
            }
        }
    }
    for (int i = 0; i < m; ++i) if (djs.find(i << 1) == djs.find(i << 1 | 1)) return cout << "Impossible" << endl, 0;
    for (int i = 0; i < m; ++i) if (!v[i]) {
        v[i] = true;
        ans[i] = true;
        for (int j = 0; j < m; ++j) if (i != j) {
            int now = djs.find(i << 1);
            if (djs.find(j << 1) != now && djs.find(j << 1 | 1) != now) continue;
            if (djs.find(j << 1) == djs.find(i << 1)) ans[j] = true; 
            v[j] = true;
        }
    }
    for (int i = 0; i < m; ++i) cout << (ans[i] ? 'i' : 'o'); cout << endl;
    return 0;
}