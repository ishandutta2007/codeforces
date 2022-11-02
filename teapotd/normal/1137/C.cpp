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
    Vi E, invE, res;
    ll sched{0};
    bool flag{0}, left{0};
    int scc{-1}, dist{-1};
};

struct Comp {
    Vi verts;
};

vector<Vert> G;
vector<Comp> scc;
Vi order;
int d;

int gcd(int a, int b) {
    while (b) {
        int c = a%b;
        a = b; b = c;
    }
    return a;
}

void dfs(int i) {
    if (G[i].flag) return;
    G[i].flag = 1;
    each(e, G[i].invE) dfs(e);
    order.pb(i);
}

void dfsScc(int i) {
    if (!G[i].flag) return;
    G[i].flag = 0;
    G[i].scc = sz(scc)-1;
    scc.back().verts.pb(i);
    each(e, G[i].E) dfsScc(e);
}

void dfsDist(int i, int& per) {
    each(e, G[i].E) if (G[i].scc == G[e].scc) {
        if (G[e].dist == -1) {
            G[e].dist = G[i].dist+1;
            dfsDist(e, per);
        } else if (!G[e].left) {
            per = gcd(per, G[i].dist-G[e].dist+1);
        }
    }
    G[i].left = 1;
}

Vi res, add, vAdd;

void solve(int i) {
    int from = scc[i].verts[0];
    int per = d;

    G[from].dist = 0;
    dfsDist(from, per);
    res.assign(d, 0);
    add.assign(d, 0);

    each(v, scc[i].verts) {
        G[v].res.resize(d);
        vAdd.assign(d, 0);

        rep(j, 0, d) {
            if ((G[v].sched >> j) & 1) {
                G[v].res[j % per] = 1;
            }
            each(e, G[v].E) if (G[v].scc != G[e].scc) {
                vAdd[j % per] = max(vAdd[j%per], G[e].res[(j+1)%d]);
            }
        }

        rep(j, per, d) {
            G[v].res[j] = G[v].res[j % per];
            vAdd[j] = vAdd[j%per];
        }

        rep(j, 0, d) {
            res[j] += G[v].res[(j+G[v].dist)%d];
            add[j] = max(add[j], vAdd[(j+G[v].dist)%d]);
        }
    }

    rep(j, 0, d) res[j] += add[j];

    each(v, scc[i].verts) {
        rep(j, 0, d) {
            G[v].res[(j+G[v].dist)%d] = res[j];
        }
    }
}

void run() {
    int n, m; cin >> n >> m >> d;
    G.resize(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        G[a-1].E.pb(b-1);
        G[b-1].invE.pb(a-1);
    }

    rep(i, 0, n) {
        string tmp; cin >> tmp;
        rep(j, 0, d) if (tmp[j] == '1') G[i].sched |= 1LL<<j;
    }

    rep(i, 0, n) dfs(i);
    while (!order.empty()) {
        int i = order.back();
        if (G[i].flag) {
            scc.emplace_back();
            dfsScc(i);
        }
        order.pop_back();
    }

    rep(i, 0, sz(scc)) solve(i);

    cout << G[0].res[0] << '\n';
}