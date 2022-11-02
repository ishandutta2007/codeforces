#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

vector<Vi> G;

Vi bfs(int src) {
    Vi dist(sz(G), -1);
    queue<int> que;

    dist[src] = 0;
    que.push(src);
    
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        each(e, G[v]) {
            if (dist[e] == -1) {
                dist[e] = dist[v]+1;
                que.push(e);
            }
        }
    }

    return dist;
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--; b--; c--;
    G.assign(n, {});

    vector<ll> price(m);
    each(p, price) cin >> p;

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    Vi da = bfs(a);
    Vi db = bfs(b);
    Vi dc = bfs(c);

    sort(all(price));
    price.insert(price.begin(), 0);
    rep(i, 1, sz(price)) price[i] += price[i-1];

    ll ans = INT64_MAX;

    rep(i, 0, n) {
        int xd = db[i], single = da[i]+dc[i];
        if (xd+single < sz(price)) {
            ll alt = price[xd+single] + price[xd];
            ans = min(ans, alt);
        }
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}