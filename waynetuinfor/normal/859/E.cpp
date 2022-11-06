#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, mod = 1e9 + 7;

int mul(int a, int b) { return a * 1ll * b % mod; }

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int v) { return p[v] == v ? v : p[v] = find(p[v]); }
    void merge(int u, int v) { p[find(u)] = find(v); }
} djs;

int sz[maxn];
bool c[maxn], v[maxn], d[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> ed;
    djs.init();
    for (int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        if (a == b) d[a] = true;
        if (djs.find(a) == djs.find(b)) c[a] = c[b] = true;
        djs.merge(a, b);
    }
    for (int i = 1; i <= 2 * n; ++i) ++sz[djs.find(i)], c[djs.find(i)] |= c[i], d[djs.find(i)] |= d[i];
    int ans = 1;
    for (int i = 1; i <= 2 * n; ++i) if (!v[djs.find(i)]) {
        if (d[djs.find(i)]);
        else if (c[djs.find(i)]) ans = mul(ans, 2);
        else ans = mul(ans, sz[djs.find(i)]);
        v[djs.find(i)] = true;
    }
    cout << ans << endl;
    return 0;
}