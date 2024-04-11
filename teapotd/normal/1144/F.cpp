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
    Vi E;
    int seen{0};
};

vector<Vert> G;
vector<Pii> edges;

void dfs(int i, int col) {
    if (G[i].seen) {
        if (G[i].seen != col) {
            cout << "NO" << endl;
            exit(0);
        }
        return;
    }

    G[i].seen = col;
    each(e, G[i].E) dfs(e, col == 1 ? 2 : 1);
}

void run() {
    int n, m; cin >> n >> m;
    G.resize(n);
    edges.resize(m);

    each(e, edges) {
        cin >> e.x >> e.y;
        e.x--; e.y--;
        G[e.x].E.pb(e.y);
        G[e.y].E.pb(e.x);
    }

    rep(i, 0, n) {
        if (!G[i].seen) dfs(i, 1);
    }

    cout << "YES\n";
    each(e, edges) {
        cout << (G[e.x].seen == 1 ? 1 : 0);
    }
    cout << endl;
}