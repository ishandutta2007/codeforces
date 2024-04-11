#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 10000000000037
#define maxn 12
#define maxm 100010
#define maxc 200010

ll i, i1, j, k, k1, t, n, m, flag[10], a, b;
ll c[maxn], hs[maxc];
unordered_set<ll> fb, fbm;
vector<array<ll, 2>> adj[maxn];
pair<ll, vector<ll>> res;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll calc_hash(vector<ll> v) {
    ll r = 1;
    for (auto u : v) r = ((ll)200021 * r + (ll)hs[u]) % mod;

    /* for (auto u : v) cout << u << ' ';
    cout << nl;
    cout << r << nl; */

    return r;
}

ll exists(vector<ll> v) {
    ll i;

    for (i = 0; i <= n - 1; i++) v[i] = adj[i][v[i]][1];

    /* for (auto u : fb) cout << u << ' ';
    cout << nl; */
    
    ll h = calc_hash(v);
    bool b = (fb.find(h) != fb.end());
    bool c = (fbm.find(h) != fbm.end());
    fbm.erase(h);
    if (b == false) return 0;
    if (c == false) return 1;
    return 2;
}

void dfs(vector<ll> &v) {
    ll i, j, k = 0, x;
    for (j = 0; j <= n - 1; j++) k += adj[j][v[j]][0];
    if (k < res.first) return;
    x = exists(v);
    if (x == 1) return;
    if (x == 0) {
        /* cout << "exists" << nl;
        for (i = 1; i <= n; i++) cout << v[i] << ' ';
        cout << nl; */
        res = max(res, {k, v});
        return;
    }
    for (i = 0; i <= n - 1; i++) {
        if (v[i] + 1 != c[i]) {
            v[i]++; dfs(v); v[i]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 0; i < maxc; i++) hs[i] = i;
    shuffle(hs, hs + maxc, rng);

    cin >> n;
    for (i = 0; i <= n - 1; i++) {
        cin >> c[i]; adj[i].resize(c[i]);
        for (j = 0; j <= c[i] - 1; j++) {
            cin >> a; adj[i][j] = {a, j};
        }

        sort(adj[i].begin(), adj[i].end()); reverse(adj[i].begin(), adj[i].end());
    }

    cin >> m;
    for (i = 0; i <= m - 1; i++) {
        vector<ll> w; w.resize(n);
        for (j = 0; j <= n - 1; j++) {
            cin >> a; w[j] = a - 1;
        }
        fb.insert(calc_hash(w));
    }
    fbm = fb;

    res = {-1, {}};
    vector<ll> st; st.resize(n);
    for (i = 0; i <= n - 1; i++) st[i] = 0;
    dfs(st);

    for (i = 0; i <= n - 1; i++) res.second[i] = adj[i][res.second[i]][1];
    // cout << res.first << nl;
    for (auto u : res.second) cout << u + 1 << ' ';
    cout << nl;

    return 0;
}