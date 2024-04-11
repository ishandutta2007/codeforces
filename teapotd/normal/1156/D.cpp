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

struct Vert {
    vector<Pii> E;
    array<int, 2> dp;
    DBP(E, dp);
};

vector<Vert> G;
ll ans = 0;

void dfs(int i, int p) {
    G[i].dp[0] = G[i].dp[1] = 1;

    each(e, G[i].E) if (e.x != p) {
        dfs(e.x, i);
        G[i].dp[0] += G[e.x].dp[e.y];
        if (e.y) G[i].dp[1] += G[e.x].dp[1];
    }
}

void solve(int i, int p) {
    ans += G[i].dp[0];

    each(e, G[i].E) if (e.x != p) {
        auto old = G[e.x].dp;

        int up[2];
        up[0] = G[i].dp[0] - old[e.y];
        up[1] = G[i].dp[1];
        if (e.y) up[1] -= old[1];

        G[e.x].dp[0] += up[e.y];
        if (e.y) G[e.x].dp[1] += up[1];

        solve(e.x, i);
        G[e.x].dp = old;
    }
}

void run() {
    int n; cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        G[a].E.pb({b, c});
        G[b].E.pb({a, c});
    }

    dfs(0, -1);
    solve(0, -1);
    cout << ans-n << endl;
}