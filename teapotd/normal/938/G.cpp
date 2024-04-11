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

struct Edge {
    int a, b, w;
};

struct Node {
    int par{-1}, rank{0}, vxor{0};
    array<int, 30> base = {};

    void extend(int mask) {
        for (int i = 29; i >= 0; i--) {
            if ((mask >> i) & 1) {
                if ((base[i] >> i) & 1) {
                    mask ^= base[i];
                } else {
                    base[i] = mask;
                    return;
                }
            }
        }
    }

    int closest(int mask) {
        for (int i = 29; i >= 0; i--) {
            if (((mask >> i) & 1) && ((base[i] >> i) & 1)) {
                mask ^= base[i];
            }
        }
        return mask;
    }
};

vector<vector<Edge>> tree;
vector<Pii> queries;
vector<Node> dsu;
int n, q, len;

Pii find(int v) {
    int x = dsu[v].vxor;
    while (dsu[v].par != -1) {
        v = dsu[v].par;
        x ^= dsu[v].vxor;
    }
    return {v, x};
}

void addEdge(int u, int v, int w, vector<pair<int, Node>>& undo) {
    int wu, wv;
    tie(u, wu) = find(u);
    tie(v, wv) = find(v);
    w ^= wu ^ wv;

    if (u == v) {
        // Internal edge, add cycle to base
        undo.pb({u, dsu[u]});
        dsu[u].extend(w);
    } else {
        // Join spanning trees and bases
        undo.pb({u, dsu[u]});
        undo.pb({v, dsu[v]});
        if (dsu[u].rank > dsu[v].rank) swap(u, v);
        dsu[u].par = v;
        dsu[u].vxor ^= w ^ dsu[v].vxor;
        dsu[v].rank += (dsu[u].rank == dsu[v].rank);
        rep(i, 0, 30) dsu[v].extend(dsu[u].base[i]);
    }
}

int handle(Pii query) {
    Pii a = find(query.x), b = find(query.y);
    assert(a.x == b.x);
    return dsu[a.x].closest(a.y ^ b.y);
}

void solve(int b, int e, int i) {
    vector<pair<int, Node>> undo;
    each(p, tree[i]) addEdge(p.a, p.b, p.w, undo);

    if (i >= len) {
        auto query = queries[i-len];
        if (query.x != -1) cout << handle(query) << '\n';
    } else {
        int m = (b+e) / 2;
        solve(b, m, i*2);
        solve(m, e, i*2+1);
    }

    for (int j = sz(undo)-1; j >= 0; j--) {
        dsu[undo[j].x] = undo[j].y;
    }
}

void insertEdge(int vb, int ve, Edge val, int b = 0, int e = -1, int i = 1) {
    if (e < 0) e = len;
    if (vb >= e || b >= ve) return;

    if (b >= vb && e <= ve) {
        tree[i].pb(val);
        return;
    }

    int m = (b+e) / 2;
    insertEdge(vb, ve, val, b, m, i*2);
    insertEdge(vb, ve, val, m, e, i*2+1);
}

void run() {
    int m;
    cin >> n >> m;

    vector<Edge> initial(m);
    each(e, initial) {
        cin >> e.a >> e.b >> e.w;
        e.a--; e.b--;
        if (e.a > e.b) swap(e.a, e.b);
    }

    cin >> q;
    q += m;

    for (len = 1; len < q; len *= 2);
    tree.resize(len*2);
    queries.resize(len, {-1, -1});

    map<Pii, Pii> open; // a,b -> i,w

    rep(i, 0, m) {
        auto& e = initial[i];
        open[{e.a, e.b}] = {i, e.w};
    }

    rep(i, m, q) {
        int t, a, b, w; cin >> t >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);

        if (t == 1) {
            cin >> w;
            open[{a, b}] = {i, w};
        } else if (t == 2) {
            Pii beg = open[{a, b}];
            open.erase({a, b});
            insertEdge(beg.x, i, {a, b, beg.y});
        } else {
            queries[i] = {a, b};
        }
    }

    each(beg, open) {
        insertEdge(beg.y.x, q, {beg.x.x, beg.x.y, beg.y.y});
    }

    dsu.resize(n);
    solve(0, len, 1);
}