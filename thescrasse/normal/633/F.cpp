#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll w[maxn], pr[maxn], w2[maxn], dist[maxn], ld;
ll m1, m2, ps[maxn], ss[maxn], sz;
bool vis[maxn], dd[maxn];
vector<ll> adj[maxn], vd;
multiset<ll> w1[maxn];

ll msum(multiset<ll> &s, ll x) {
    ll c = 0, r = 0;
    auto it = s.end();
    while (it != s.begin()) {
        it--; r += (*it); c++;
        if (c == 2) {
            r -= x; break;
        }
    }
    return r;
}

void diam(ll s) {
    vis[s] = true;
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        pr[u] = s;
        dist[u] = dist[s] + w[u];
        diam(u);
    }
}

ll mxd() {
    array<ll, 2> mx = {-1, -1};
    for (i = 1; i <= n; i++) mx = max(mx, {dist[i], i});
    return mx[1];
}

void dfs1(ll s, ll st) {
    vis[s] = true;
    if (dd[s]) dist[s] = w[s];
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        if (dd[u] == true && u != st) continue;
        pr[u] = s;
        dist[u] = dist[s] + w[u];
        dfs1(u, st);
    }
}

void dfs2(ll s, ll st) {
    // << "dfs2" _ s _ st << nf;
    ll c, f = 0;
    vis[s] = true;
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        if (dd[u] == true && u != st) continue;
        //  << "u =" _ u << nf;
        dfs2(u, st); f = 1;
        w1[s].insert(*(--w1[u].end()) + w[s]);
    }

    if (f == 0) w1[s].insert(w[s]);
    w2[s] = msum(w1[s], w[s]);
    if (!dd[s]) res = max(res, w2[s]);
}

void rst(ll s = 0) {
    ll i;
    for (i = 1; i <= n; i++) {
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (i = 1; i <= n; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    rst(1); diam(1);
    m1 = mxd(); rst(m1); diam(m1);
    m2 = mxd();

    vd.pb(m2); i = m2; ld += w[i];
    while (i != m1) {
        i = pr[i]; vd.pb(i); ld += w[i];
    }
    for (auto u : vd) dd[u] = true;

    for (auto u : vd) dfs1(u, u);
    rst(0);
    for (auto u : vd) dfs2(u, u);

    res += ld;

    /* for (auto u : vd) cout << u << ' ';
    cout << nf;

    for (i = 1; i <= n; i++) {
        for (auto u : w1[i]) cout << u << ' ';
        cout << nf;
    } */

    sz = vd.size();
    for (i = 0; i < sz; i++) {
        if (i == 0) ps[i] = w[vd[i]];
        else ps[i] = ps[i - 1] + w[vd[i]];
    }

    for (i = sz - 1; i >= 0; i--) {
        if (i == sz - 1) ss[i] = w[vd[i]];
        else ss[i] = ss[i + 1] + w[vd[i]];
    }

    for (i = 0; i < sz; i++) {
        ps[i] += (*(--w1[vd[i]].end()) - w[vd[i]]);
        ss[i] += (*(--w1[vd[i]].end()) - w[vd[i]]);
    }

    for (i = 1; i < sz; i++) ps[i] = max(ps[i], ps[i - 1]);
    for (i = sz - 2; i >= 0; i--) ss[i] = max(ss[i], ss[i + 1]);

    /* for (i = 0; i < sz; i++) {
        cout << i _ ps[i] _ ss[i] << nf;
    } */

    for (i = 0; i < sz - 1; i++) res = max(res, ps[i] + ss[i + 1]);

    // cout << res << nl;

    /* for (i = 1; i <= n; i++) cout << w2[i] << ' ';
    cout << nl; */

    cout << res << nl;

    return 0;
}