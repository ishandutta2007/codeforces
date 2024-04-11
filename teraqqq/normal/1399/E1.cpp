#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;

const int INF = 1e9;
const ll LINF = 1e18;

struct edge {
    int to, w, c;

    edge(int to = 0, int w = 0, int c = 0) : to(to), w(w), c(c) { }
};

vector<vector<edge>> g;
vector<vector<ll>> vv(2), uu(2);
vector<priority_queue<pair<ll, int>>> q(2);
vi sz;
int n;
ll k = 0, s = 0;

void dfs(int v = 0, int p = -1) {
    sz[v] = 0;
    for(auto e : g[v]) {
        if(e.to == p) continue;

        dfs(e.to, v); sz[v] += sz[e.to];
        ll m = sz[e.to];
        k += m * e.w;
        q[e.c].push({ m * (e.w - e.w/2), (int)vv[e.c].size() });
        vv[e.c].push_back(e.w);
        uu[e.c].push_back(m);
    }
    if(!sz[v]) sz[v] ++;
}

void solve() {
    cin >> n >> s; k = 0;
    g.clear(); g.resize(n);
    sz.clear(); sz.resize(n);
    for(int i = 0; i < 2; ++i) {
        vv[i].clear(); uu[i].clear();
        while(!q[i].empty()) q[i].pop();
    }

    for(int i = 0; i < n-1; ++i) {
        int a, b, w; cin >> a >> b >> w;
        g[a-1].eb(b-1, w);
        g[b-1].eb(a-1, w);
    }
    dfs();

    //cout << "A" << endl;

    vector<vector<ll>> t(2);
    const int m = 21 * n;
    for(int i = 0; i < 2; ++i) {
        if(q[i].empty()) {
            t[i].assign(m, 0);
            continue;
        }

        for(int j = 0; j < m; ++j) {
            auto x = q[i].top(); q[i].pop();
            t[i].push_back(x.F);
            //cout << t[i].back() << "!" << endl;
            vv[i][x.S] /= 2;
            q[i].push( { uu[i][x.S]*(vv[i][x.S] - vv[i][x.S]/2), x.S } );
        }
    }

    //cout << "A" << endl;

    //cout << k << ": ";

    int res = 0;
    while(s < k) k -= t[0][res++];
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while(t--) solve();
}