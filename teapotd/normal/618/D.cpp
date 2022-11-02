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

int n;
ll x, y;
vector<Vi> G;
Vi dist, dp, dp2;

void dfs(int v) {
    each(e, G[v]) {
        if (dist[e] == -1) {
            dist[e] = dist[v]+1;
            dfs(e);
        }
    }
}

void dfs2(int v, int p) {
    Vi diffs;
    int sum = 0;

    each(e, G[v]) if (e != p) {
        dfs2(e, v);
        sum += dp[e];
        diffs.pb(dp2[e]-dp[e]);
    }

    sort(all(diffs));

    dp2[v] = sum+1;
    if (sz(diffs) >= 1) {
        dp2[v] = min(dp2[v], sum+diffs[0]);
    }

    dp[v] = dp2[v];
    if (sz(diffs) >= 2) {
        dp[v] = min(dp[v], sum+diffs[0]+diffs[1]-1);
    }
}

void run() {
    cin >> n >> x >> y;
    G.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    ll yt = 0;

    if (x < y) {
        dp.resize(n);
        dp2.resize(n);
        dfs2(0, -1);
        yt = dp[0]-1;
    } else {
        dist.assign(n, -1);
        dist[0] = 0;
        dfs(0);
        int v = 0;
        rep(i, 1, n) if (dist[v] < dist[i]) v = i;
        dist.assign(n, -1);
        dist[v] = 0;
        dfs(v);
        int g = 0;
        each(d, dist) g = max(g, d);

        if (g >= 3) {
            yt = n-1;
        } else {
            yt = n-2;
        }
    }

    ll ans = yt*y + (n-yt-1)*x;
    cout << ans << '\n';
}