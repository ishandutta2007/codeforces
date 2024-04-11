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

vector<Vi> G;
vector<bool> seen;
Vi part[2];

void dfs(int v, int d) {
    if (seen[v]) return;
    seen[v] = 1;
    part[d].pb(v);
    each(e, G[v]) dfs(e, !d);
}

void solve() {
    int n, m; cin >> n >> m;
    G.assign(n, {});

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    rep(i, 0, 2) part[i].clear();
    seen.assign(n, 0);
    dfs(0, 0);

    Vi& ans = (sz(part[0]) < sz(part[1]) ? part[0] : part[1]);
    cout << sz(ans) << '\n';
    each(a, ans) cout << a+1 << ' ';
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}