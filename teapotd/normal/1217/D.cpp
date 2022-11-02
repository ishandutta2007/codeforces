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

int n, m, k = 1;
vector<Vi> G;
vector<Pii> edges;
Vi seen;

void dfs(int v) {
    if (seen[v]) {
        if (seen[v] == 1) k = 2;
        return;
    }

    seen[v] = 1;
    each(e, G[v]) dfs(e);
    seen[v] = 2;
}

void run() {
    cin >> n >> m;
    G.resize(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        edges.pb({a-1, b-1});
    }

    seen.resize(n);
    rep(i, 0, n) dfs(i);

    cout << k << '\n';

    each(e, edges) {
        if (k == 1 || e.x < e.y) {
            cout << "1 ";
        } else {
            cout << "2 ";
        }
    }

    cout << '\n';
}