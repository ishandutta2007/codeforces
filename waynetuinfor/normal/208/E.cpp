#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
vector<int> G[maxn], nd[maxn];
int dep[maxn], p[lg][maxn], tin[maxn], tout[maxn], t;

void dfs(int now, int fa, int d) {
    p[0][now] = fa; dep[now] = d;
    tin[now] = ++t;
    nd[d].push_back(now);
    for (int i = 1; i < lg; ++i) {
        if ((1 << i) > d) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
    }
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
    }
    tout[now] = t;
}

int get(int v, int k) {
    int ans = v;
    for (int i = 0; i < lg; ++i) {
        if ((1 << i) & k) {
            ans = p[i][ans];
            k -= (1 << i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> root;
    for (int i = 1; i <= n; ++i) {
        int r; cin >> r;
        if (r == 0) root.push_back(i);
        else G[r].push_back(i); G[i].push_back(r);
    }
    for (int i : root) dfs(i, 0, 0);
    int m; cin >> m; while (m--) {
        int v, p; cin >> v >> p;
        int anc = get(v, p);
        int ans = 0;
        if (anc == 0) {
            cout << "0" << ' ';
            continue;
        }
        int ind = lower_bound(nd[dep[v]].begin(), nd[dep[v]].end(), anc, [&](const int& a, const int& b) { return tin[a] < tin[b]; }) - nd[dep[v]].begin();
        int tmp = ind;
        int d = 1; while (d <= n) d <<= 1;
        while (d >>= 1) if (ind + d < nd[dep[v]].size()) if (tin[nd[dep[v]][ind + d]] <= tout[anc]) ind += d;
        cout << ind - tmp << ' ';
    }
    return 0;
}