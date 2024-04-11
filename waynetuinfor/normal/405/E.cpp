#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
vector<pair<int, int>> G[maxn];
bool v[maxn], use[maxn];

struct data {
    int a, b, c;
};

vector<data> ans;

void dfs(int now, int fa, int edge) {
    v[now] = true;
    int nxt = -1, cid = -1;
    for (auto u : G[now]) if (u.first != fa) {
        if (!v[u.first]) dfs(u.first, now, u.second);
        if (use[u.second]) continue;
        if (nxt == -1) nxt = u.second, cid = u.first;
        else if (nxt != -1) {
            ans.emplace_back((data){ u.first, now, cid });
            use[nxt] = use[u.second] = true;
            nxt = -1; cid = -1;
        }
    }
    if (nxt != -1) {
        if (edge && !use[edge] && !use[nxt]) {
            ans.emplace_back((data){ cid, now, fa });
            use[edge] = use[nxt] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    if (m & 1) return cout << "No solution" << endl, 0;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
        G[a[i]].emplace_back(b[i], i);
        G[b[i]].emplace_back(a[i], i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) dfs(i, 0, 0);
    }
    if (ans.size() < m / 2) return cout << "No solution" << endl, 0;
    for (auto e : ans) cout << e.a << ' ' << e.b << ' ' << e.c << endl;
    return 0;
}