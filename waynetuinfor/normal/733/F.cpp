#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, lg = 20;
const int inf9 = 1e9 + 1;
const long long inf = 1e18;
int w[maxn], c[maxn], a[maxn], b[maxn];
int p[lg][maxn], dep[maxn], d[lg][maxn];
bool t[maxn];
vector<pair<int, int>> G[maxn];

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    void merge(int u, int v) { p[find(u)] = find(v); }
} djs;

void dfs(int now, int fa, int wi, int dp) {
    p[0][now] = fa; d[0][now] = wi;
    dep[now] = dp;
    for (int i = 1; ; ++i) {
        if ((1 << i) > dp) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
        d[i][now] = max(d[i - 1][now], d[i - 1][p[i - 1][now]]);
    }
    for (auto u : G[now]) if (u.first != fa) {
        dfs(u.first, now, w[u.second], dp + 1);
    }
}

int lca(int a, int b) {
    int ret = 0, bst = -1;
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < lg; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) ret = max(ret, d[i][b]), b = p[i][b];
    }
    if (a == b) return ret;
    for (int i = lg - 1; i >= 0; --i) {
        if (p[i][b] != p[i][a]) {
            ret = max(ret, max(d[i][a], d[i][b]));
            a = p[i][a];
            b = p[i][b];
        }
        if (a == b) return ret;
    }
    return max(ret, max(d[0][a], d[0][b]));
}

int find(int now, int b, int fa, int res, int goal) {
    if (now == b) return res;
    for (auto u : G[now]) if (u.first != fa) {
        int k = find(u.first, b, now, (w[u.second] == goal ? u.second : res), goal);
        if (k != -1) return k;
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> eid(m); iota(eid.begin(), eid.end(), 0);
    for (int i = 0; i < m; ++i) cin >> w[i];
    for (int i = 0; i < m; ++i) cin >> c[i];
    for (int i = 0; i < m; ++i) cin >> a[i] >> b[i];
    int s; cin >> s;
    sort(eid.begin(), eid.end(), [&](const int &i, const int &j) { return w[i] < w[j]; });
    djs.init();
    long long mst = 0;
    for (int i : eid) {
        if (djs.find(a[i]) == djs.find(b[i])) continue;
        t[i] = true;
        djs.merge(a[i], b[i]);
        mst += w[i];
        G[a[i]].emplace_back(b[i], i);
        G[b[i]].emplace_back(a[i], i);
    }
    dfs(1, 0, 0, 0);
    long long ans = inf;
    int bst = -1, r = -1;
    for (int i = 0; i < m; ++i) {
        if (t[i]) {
            if (mst - (s / c[i]) < ans) {
                ans = mst - (s / c[i]);
                bst = i;
            }
            continue;
        }
        int lc = lca(a[i], b[i]);
        if (mst + w[i] - lc - (s / c[i]) < ans) {
            ans = mst + w[i] - lc - (s / c[i]);
            bst = i; 
            r = lc;
        }
    }
    cout << ans << endl;
    if (t[bst]) {
        for (int i = 0; i < m; ++i) {
            if (t[i] && i == bst) cout << i + 1 << ' ' << w[i] - (s / c[i]) << endl;
            else if (t[i]) cout << i + 1 << ' ' << w[i] << endl;
        }        
    } else {
        int rem = find(a[bst], b[bst], 0, -1, r);        
        cout << bst + 1 << ' ' << w[bst] - (s / c[bst]) << endl;
        for (int i = 0; i < m; ++i) {
            if (t[i] && i != rem) cout << i + 1 << ' ' << w[i] << endl;
        }
    }
    return 0;
}