#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const long long inf = 1e18;
int a[maxn], b[maxn], c[maxn];
int sid[maxn], cnt;
long long nsq[maxn], sgsq[maxn];
long long w[maxn], dp[maxn];
vector<pair<int, int>> G[maxn], scc[maxn];
vector<int> R[maxn], tp, ed[maxn];
bool v[maxn];

long long cal(int k) {
    int n = upper_bound(nsq, nsq + maxn, k) - nsq - 1;
    return k * 1ll * (n + 1) - (nsq[n] + sgsq[n]) / 2;
}

void init() {
    fill(nsq, nsq + maxn, inf);
    for (int i = 1; ; ++i) {
        if (i * 1ll * (i + 1) / 2 > 1e8) break;
        nsq[i] = i * 1ll * (i + 1) / 2;
        sgsq[i] = i * 1ll * (i + 1) * (2 * i + 1) / 6;
    }
}

void rdfs(int now) {
    v[now] = true;
    for (int u : R[now]) if (!v[u]) rdfs(u);
    tp.push_back(now);
}

void dfs(int now) {
    sid[now] = cnt;
    for (auto u : G[now]) if (!sid[u.first]) dfs(u.first);
}

long long go(int now) {
    if (dp[now]) return dp[now];
    for (auto u : scc[now]) {
        long long d = go(u.first);
        dp[now] = max(dp[now], u.second + d);
    }
    dp[now] += w[now];
    return dp[now];
}

int main() {
    init();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        G[a[i]].emplace_back(b[i], i);
        R[b[i]].emplace_back(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) rdfs(i);
    }
    reverse(tp.begin(), tp.end());
    for (int u : tp) if (!sid[u]) {
        ++cnt;
        dfs(u);
    }
    for (int i = 1; i <= n; ++i) {
        for (auto j : G[i]) {
            if (sid[j.first] == sid[i]) ed[sid[i]].push_back(j.second);
            else scc[sid[i]].emplace_back(sid[j.first], c[j.second]);
        }        
    }
    for (int i = 1; i <= cnt; ++i) {
        sort(ed[i].begin(), ed[i].end()); ed[i].resize(unique(ed[i].begin(), ed[i].end()) - ed[i].begin());
        for (int j : ed[i]) w[i] += cal(c[j]);
    }
    int s; cin >> s;
    cout << go(sid[s]) << endl;
    return 0;
}