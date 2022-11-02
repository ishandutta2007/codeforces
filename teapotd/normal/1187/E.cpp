#define _USE_MATH_DEFINES
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

int n;
vector<Vi> G;
vector<ll> sub, cost;
ll ans = 0;

void dfs(int v, int p) {
    sub[v] = 1;
    cost[v] = 0;

    each(e, G[v]) if (e != p) {
        dfs(e, v);
        sub[v] += sub[e];
        cost[v] += cost[e];
    }

    cost[v] += sub[v];
}

void solve(int v, int p, ll overCost) {
    ans = max(ans, cost[v] - sub[v] + n + overCost);

    each(e, G[v]) if (e != p) {
        ll c = overCost + cost[v] - sub[v] - cost[e] + n - sub[e];
        solve(e, v, c);
    }
}

void run() {
    cin >> n;
    G.resize(n);
    sub.resize(n);
    cost.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    dfs(0, -1);
    solve(0, -1, 0);
    cout << ans << '\n';
}