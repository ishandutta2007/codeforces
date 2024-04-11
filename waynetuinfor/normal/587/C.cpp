#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> tmp, ret;
    for (int i : a) tmp.push_back(i);
    for (int i : b) tmp.push_back(i);
    sort(tmp.begin(), tmp.end()); tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    for (int i = 0; i < min(10, (int)tmp.size()); ++i) ret.push_back(tmp[i]);
    return ret;
}

vector<int> G[maxn], ar[maxn];
vector<int> data[lg][maxn];
int p[lg][maxn], dep[maxn];

void dfs(int now, int fa, int d) {
    p[0][now] = fa;
    data[0][now] = ar[now];
    dep[now] = d;
    for (int i = 1; i < lg; ++i) {
        if ((1 << i) > d) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
        data[i][now] = merge(data[i - 1][now], data[i - 1][p[i - 1][now]]);
    }
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
    }
}

pair<vector<int>, int> lca(int a, int b) {
    vector<int> ret;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < lg; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) {
            ret = merge(ret, data[i][b]);
            b = p[i][b];
        }
    }
    if (a == b) return make_pair(ret, a);
    for (int i = lg - 1; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            ret = merge(ret, data[i][a]);
            ret = merge(ret, data[i][b]);
            a = p[i][a]; b = p[i][b];
        }
        if (a == b) return make_pair(ret, a);
    }
    if (a == b) return make_pair(ret, a);
    ret = merge(ret, data[0][a]); ret = merge(ret, data[0][b]);
    return make_pair(ret, p[0][a]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    for (int i = 1; i <= m; ++i) {
        int c; cin >> c;
        ar[c].push_back(i);
        ar[c] = merge(ar[c], vector<int>());
    }
    dfs(1, 0, 0);
    while (q--) {
        int a, b, sz; cin >> a >> b >> sz;
        auto tmp = lca(a, b);
        vector<int> ans = merge(tmp.first, ar[tmp.second]);
        cout << min((int)ans.size(), sz) << ' ';
        for (int i = 0; i < min((int)ans.size(), sz); ++i) cout << ans[i] << ' '; cout << endl;
    }
    return 0;
}