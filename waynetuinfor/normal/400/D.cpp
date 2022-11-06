#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxk = 500 + 10;
const long long inf = 1e18 + 1;
int c[maxk], id[maxn];
long long dp[maxk][maxk];
vector<pair<int, int>> G[maxn];

struct Dsu {
    int par[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) par[i] = i;
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        par[x] = y;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) cin >> c[i];
    dsu.init();
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c)); G[b].push_back(make_pair(a, c));
        if (c == 0) dsu.merge(a, b);
    }
    int s = 0;
    bool correct = true;
    for (int i = 1; i <= k; ++i) {
        set<int> p;
        for (int j = s + 1; j <= s + c[i]; ++j) {
            p.insert(dsu.find(j));
            id[j] = i;
        }
        if (p.size() > 1) correct = false;
        s += c[i];
    }
    if (!correct) return cout << "No" << endl, 0;
    for (int i = 0; i < maxk; ++i) fill(dp[i], dp[i] + maxk, inf);
    for (int i = 1; i <= n; ++i) {
        for (pair<int, int> e : G[i]) {
            dp[id[i]][id[e.first]] = min(dp[id[i]][id[e.first]], (long long)e.second);
            dp[id[e.first]][id[i]] = min(dp[id[e.first]][id[i]], (long long)e.second);
        }
    } 
    for (int i = 1; i <= k; ++i) dp[i][i] = 0;
    for (int t = 1; t <= k; ++t) {
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) dp[i][j] = min(dp[i][j], dp[i][t] + dp[t][j]);
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (dp[i][j] == inf) cout << "-1 ";
            else cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}