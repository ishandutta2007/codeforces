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

int n, m;
vector<Vi> G;
Vi cost;
vector<ll> path, tot;
vector<bool> seen;
ll bestPath = 0;

bool dfs(int v, int p) {
    bool esc = 0;
    seen[v] = 1;
    tot[v] = path[v] = cost[v];

    each(e, G[v]) if (e != p) {
        if (seen[e]) {
            esc = 1;
        } else {
            if (dfs(e, v)) {
                esc = 1;
                tot[v] += tot[e];
            }
            path[v] = max(path[v], cost[v]+path[e]);
        }
    }

    if (!esc) {
        bestPath = max(bestPath, path[v]);
    }
    return esc;
}

void run() {
    cin >> n >> m;
    G.resize(n);
    cost.resize(n);
    seen.resize(n);
    path.resize(n);
    tot.resize(n);

    rep(i, 0, n) {
        cin >> cost[i];
    }

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    int s; cin >> s;
    s--;
    bool esc = dfs(s, -1);

    ll ans = bestPath;
    if (esc) ans += tot[s];
    cout << ans << endl;
}