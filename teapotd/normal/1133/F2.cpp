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
Vi par, seen;

void dfs(int v, int p) {
    if (seen[v]) return;
    seen[v] = 1;
    par[v] = p;
    each(e, G[v]) if (e != p) dfs(e, v);
}

void run() {
    int n, m, d; cin >> n >> m >> d;
    G.resize(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    par.resize(n);
    seen.resize(n);
    dfs(0, -1);

    int minD = int(count(all(par), 0));
    int maxD = sz(G[0]);

    if (d < minD || d > maxD) {
        cout << "NO\n";
        return;
    }

    d -= minD;
    
    each(e, G[0]) {
        if (d == 0) break;
        if (par[e] == 0) continue;
        par[e] = 0;
        d--;
    }

    cout << "YES\n";
    rep(i, 0, n) {
        if (par[i] != -1) {
            cout << i+1 << ' ' << par[i]+1 << '\n';
        }
    }
}