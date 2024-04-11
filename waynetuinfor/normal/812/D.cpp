#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int req[maxn], p[maxn], sz[maxn], tin[maxn], tout[maxn], stamp;
vector<int> T[maxn];
bitset<maxn> v, rt;

void dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(req, -1, sizeof(req));
    int n, m, k, q; cin >> n >> m >> k >> q;
    rt.set();
    while (k--) {
        int a, b; cin >> a >> b;
        if (req[b] != -1) T[req[b]].push_back(a), rt[a] = false;
        req[b] = a;
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i] && rt[i]) dfs(i, 0);
    }
    while (q--) {
        int x, y; cin >> x >> y;
        int z = req[y];
        if (z == -1) cout << "0\n";
        else {
            if (tin[z] >= tin[x] && tout[z] <= tout[x]) cout << sz[x] << '\n';
            else cout << "0\n";
        }
    }
    return 0;
}

void dfs(int x, int p) {
    v[x] = true;
    tin[x] = ++stamp;
    sz[x] = 1;
    for (int u : T[x]) if (u != p) {
        dfs(u, x);
        sz[x] += sz[u];
    }
    tout[x] = ++stamp;
}