#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9, maxn = 1e5 + 10;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

struct dsu {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int v) { return p[v] == v ? v : p[v] = find(p[v]); }
    bool same(int u, int v) { return find(u) == find(v); }
    void merge(int u, int v) { p[find(u)] = find(v); }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    dsu.init();
    int now = 1;
    while (m--) {
        int a, b; cin >> a >> b;
        if (dsu.same(a, b)) now = mul(now, 2);
        else dsu.merge(a, b);
        cout << sub(now, 1) << endl;
    }
    return 0;
}