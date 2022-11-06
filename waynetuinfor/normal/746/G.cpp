#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], deg[maxn], d[maxn];
vector<int> node[maxn], G[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, t, k; cin >> n >> t >> k;
    int leaf = n - t;
    if (leaf < k) return cout << "-1" << endl, 0;
    for (int i = 1; i <= t; ++i) cin >> a[i];
    int p = 1, now = 2;
    d[1] = 0;
    for (int i = 1; i <= t; ++i) {
        int np = -1;
        for (int j = 0; j < a[i]; ++j) {
            if (np == -1) np = now;
            d[now] = d[p] + 1;
            node[d[now]].push_back(now);
            ++deg[p]; ++deg[now];
            G[p].push_back(now);
            ++now;
        }
        p = np;
    }
    int curdep = t - 1;
    size_t ptr = 0, rptr = node[curdep].size() - 1;
    for (int i = 1; i <= t; ++i) sort(node[i].begin(), node[i].end(), [&](const int& a, const int& b) { return deg[a] > deg[b]; });
    while (leaf > k) {
        if (curdep == 0) return cout << "-1" << endl, 0;
        while (ptr < rptr) {
            if (leaf <= k) break;
            int u = node[curdep][ptr], b = node[curdep][rptr];
            if (deg[u] <= 2) {
                ++ptr;
                continue;
            }
            if (deg[b] >= 2) {
                rptr = -1;
                continue;
            }
            int v = G[u].back(); G[u].pop_back();
            --deg[u]; ++deg[b];
            G[b].push_back(v);
            --leaf; --rptr;
        }
        if (ptr >= rptr) ptr = 0, --curdep, rptr = node[curdep].size() - 1;
    }
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        for (int u : G[i]) cout << i << ' ' << u << endl;
    }
    return 0;
}