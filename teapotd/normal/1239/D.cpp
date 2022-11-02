#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct SCC : Vi {
    vector<Vi> comps;
    Vi S;
    int cnt{0};

    SCC() {}

    SCC(vector<Vi>& G) : Vi(sz(G),-1), S(sz(G)) {
        rep(i, 0, sz(G)) if (!S[i]) dfs(G, i);
    }

    int dfs(vector<Vi>& G, int v) {
        int low = S[v] = ++cnt, t = -1;
        S.pb(v);
        each(e, G[v]) if (at(e) < 0) low = min(low, S[e] ?: dfs(G, e));
        if (low == S[v]) {
            comps.emplace_back();
            for (; t != v; S.pop_back()) {
                at(t = S.back()) = sz(comps) - 1;
                comps.back().pb(t);
            }
        }
        return low;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Vi> G(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (a != b) G[a].pb(b);
    }

    SCC scc(G);

    if (sz(scc.comps) <= 1) {
        cout << "No\n";
        return;
    }

    Vi jury, cats;
    each(v, scc.comps[0]) jury.pb(v);
    rep(i, 1, sz(scc.comps)) each(v, scc.comps[i]) cats.pb(v);

    cout << "Yes\n";
    cout << sz(jury) << ' ' << sz(cats) << '\n';
    each(v, jury) cout << v+1 << ' ';
    cout << '\n';
    each(v, cats) cout << v+1 << ' ';
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}