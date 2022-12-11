#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
vector <int> g[N], g2[N];
pair <int, int> lr[N];
int T = 0;
int ans = 0;

struct cmp {
    bool operator()(const int &a, const int &b) const {
        if (lr[a].first == lr[b].first)
            return (a < b);
        return (lr[a].first < lr[b].first);
    }
};

set <int, cmp> s;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        g2[i].clear();
    }
    T = 0;
    ans = 0;
    s.clear();
}

void dfs2(int v, int par = -1) {
    lr[v].first = T++;
    for (int u : g2[v])
        if (u != par)
            dfs2(u, v);
    lr[v].second = T++;
}

void dfs(int v, int par = -1) {
    //cout << v << ' ' << s.size() << endl;
    auto uk = s.upper_bound(v);
    int p = -1;
    bool ins = 0;
    if (uk != s.begin()) {
        auto uk2 = uk;
        int pp = *(--uk2);
        if (lr[pp].second >= lr[v].second) {
            p = pp;
        }
    }
    if (p != -1) {
        ins = 1;
        s.erase(p);
        s.insert(v);
    } else {
        if (uk != s.end() && lr[(*uk)].second <= lr[v].second) {
            ins = 0;
        } else {
            ins = 1;
            s.insert(v);
        }
    }
    ans = max(ans, (int) s.size());
    for (int u : g[v]) {
        if (u != par)
            dfs(u, v);
    }
    if (ins)
        s.erase(v);
    if (p != -1)
        s.insert(p);
}

void solve() {
    int n;
    cin >> n;
    init(n);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g2[p].push_back(i);
    }
    dfs2(1);
    dfs(1);
    cout << ans << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}