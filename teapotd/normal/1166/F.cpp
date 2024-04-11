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
    Vi edges;
    map<int, int> cols;
    set<int> neighs;
    int id;
};

int n, m, maxC, q;
vector<Vert> G;
vector<Vi> sets;

void join(int u, int v) {
    u = G[u].id;
    v = G[v].id;
    if (u == v) return;
    if (sz(sets[u]) > sz(sets[v])) swap(u, v);

    each(e, sets[u]) {
        sets[v].pb(e);
        G[e].id = v;
        each(f, G[e].edges) {
            G[f].neighs.erase(u);
            G[f].neighs.insert(v);
        }
    }

    sets[u].clear();
}

void addEdge(int u, int v, int c) {
    G[u].edges.pb(v);
    G[v].edges.pb(u);
    G[u].neighs.insert(G[v].id);
    G[v].neighs.insert(G[u].id);

    if (G[u].cols.count(c)) {
        join(G[u].cols[c], v);
    } else {
        G[u].cols[c] = v;
    }

    if (G[v].cols.count(c)) {
        join(G[v].cols[c], u);
    } else {
        G[v].cols[c] = u;
    }
}

void run() {
    cin >> n >> m >> maxC >> q;
    G.resize(n);
    sets.resize(n);

    rep(i, 0, n) {
        sets[i].pb(i);
        G[i].id = i;
    }

    rep(i, 0, m) {
        int u, v, c; cin >> u >> v >> c;
        u--; v--; c--;
        addEdge(u, v, c);
    }

    rep(i, 0, q) {
        string t; cin >> t;

        if (t[0] == '+') {
            int u, v, c; cin >> u >> v >> c;
            u--; v--; c--;
            addEdge(u, v, c);
        } else {
            int u, v; cin >> u >> v;
            u--; v--;

            if (G[u].id == G[v].id || G[v].neighs.count(G[u].id)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}