#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 150010

ll i, i1, j, k, k1, t, n[5], m[5], res, flag[10], a, b;
vector<ll> adj[5];
vector<ll> fbd[5][maxn];
multiset<ll> st;

void bld(ll ty) {
    st.clear();
    for (auto u : adj[ty]) {
        if (u != -1) st.insert(u);
    }
}

void rm(ll ty, ll i) {
    for (auto u : fbd[ty][i]) {
        st.erase(st.find(adj[ty - 1][u]));
        // cout << "rm " << u << nl;
    }
    if (st.empty()) {
        adj[ty][i] = INF;
    } else {
        auto it = st.begin();
        adj[ty][i] += (*it);
    }
    for (auto u : fbd[ty][i]) st.insert(adj[ty - 1][u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 1; i <= 4; i++) {
        cin >> n[i]; adj[i].pb(-1);
    }
    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= n[i]; j++) {
            cin >> a; adj[i].pb(a);
        }
    }
    for (i = 2; i <= 4; i++) {
        cin >> m[i];
        for (j = 1; j <= m[i]; j++) {
            cin >> a >> b; fbd[i][b].pb(a);
        }
    }

    for (i = 2; i <= 4; i++) {
        bld(i - 1);
        for (j = 1; j <= n[i]; j++) rm(i, j);
    }

    /* for (i = 1; i <= 4; i++) {
        for (auto u : adj[i]) cout << u << ' ';
        cout << nl;
    } */

    res = INF;
    for (auto u : adj[4]) {
        if (u != -1) res = min(res, u);
    }
    if (res == INF) res = -1;

    cout << res << nl;

    return 0;
}