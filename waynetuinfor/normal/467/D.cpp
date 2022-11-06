#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
unordered_map<string, int> mp;
vector<int> G[maxn], R[maxn], t;
int a[maxn], r[maxn], l[maxn], c, sccid[maxn];
pair<int, int> scc[maxn], dp[maxn];
bool v[maxn];

string lower(const string &s) {
    string ret = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') ret += s[i] + 32;
        else ret += s[i];
    }
    return ret;
}

int find(string s) {
    s = lower(s);
    if (mp.find(s) == mp.end()) {
        mp[s] = mp.size();
        l[mp[s]] = (int)s.size();
        for (int i = 0; i < s.size(); ++i) if (s[i] == 'r') ++r[mp[s]];
    }
    return mp[s];
}

void add_edge(int u, int v) {
    G[u].push_back(v);
    R[v].push_back(u);
}

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) if (!v[u]) dfs(u);
    t.push_back(now);
}

void rdfs(int now) {
    v[now] = true;
    scc[c] = min(scc[c], make_pair(r[now], l[now])); 
    sccid[now] = c;
    for (int u : R[now]) if (!v[u]) rdfs(u);
}

pair<int, int> go(int now) {
    if (dp[now] != make_pair(0ll, 0ll)) return dp[now];
    dp[now] = scc[now];
    for (int u : R[now]) {
        pair<int, int> p = go(u);
        dp[now] = min(dp[now], p);
    }
    return dp[now];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        a[i] = find(s);
    }
    int n; cin >> n; while (n--) {
        string a, b; cin >> a >> b;
        int u = find(a), v = find(b);
        add_edge(u, v);
    }
    for (int i = 1; i <= mp.size(); ++i) if (!v[i]) dfs(i);
    reverse(t.begin(), t.end()); memset(v, false, sizeof(v));
    fill(scc, scc + maxn, make_pair(inf, inf));
    for (int u : t) if (!v[u]) ++c, rdfs(u);
    for (int i = 0; i < maxn; ++i) R[i].clear();
    for (int i = 1; i <= mp.size(); ++i) {
        for (int u : G[i]) {
            if (sccid[u] != sccid[i]) R[sccid[i]].push_back(sccid[u]);
        }
    }
    int rnow = 0, lnow = 0;
    for (int i = 0; i < m; ++i) {
        pair<int, int> p = go(sccid[a[i]]);
        rnow += p.first; lnow += p.second;
    }
    cout << rnow << ' ' << lnow << endl;
    return 0;
}