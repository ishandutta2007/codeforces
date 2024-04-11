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

int n, k;
vector<Vi> G;
Vi cost;
vector<Vi> dp;

void dfs(int v, int p) {
    if (p != -1) G[v].erase(find(all(G[v]), p));
    each(e, G[v]) dfs(e, v);

    rep(d, 1, k+1) {
        int x = d-1;
        int y = k-x-1;
        if (y > x) {
            int ysum = 0;
            each(e, G[v]) ysum += dp[e][y];
            each(e, G[v]) {
                dp[v][d] = max(dp[v][d], ysum-dp[e][y]+dp[e][x]);
            }
        } else {
            each(e, G[v]) dp[v][d] += dp[e][x];
        }
    }

    dp[v][0] = cost[v];
    each(e, G[v]) dp[v][0] += dp[e][k];

    for (int d = k-1; d >= 0; d--) {
        dp[v][d] = max(dp[v][d], dp[v][d+1]);
    }
}

void run() {
    cin >> n >> k;
    cost.resize(n);
    each(c, cost) cin >> c;

    G.resize(n);
    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    dp.resize(n, Vi(k+1));
    dfs(0, -1);

    int ans = 0;
    each(d, dp[0]) ans = max(ans, d);
    cout << ans << endl;
}