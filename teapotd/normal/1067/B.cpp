#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

struct Vert {
    Vi E;
    int par{-1}, depth{0};
};

vector<Vert> G;

void dfs(int i) {
    each(e, G[i].E) if (e != G[i].par) {
        G[e].par = i;
        G[e].depth = G[i].depth+1;
        dfs(e);
    }
}

void answer(bool ok) {
    cout << (ok ? "Yes" : "No") << endl;
    exit(0);
}

void run() {
    int n, k; cin >> n >> k;
    G.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].E.pb(b-1);
        G[b-1].E.pb(a-1);
    }

    if (n == 1) {
        answer(0);
    }

    rep(i, 0, n) if (sz(G[i].E) == 1) {
        dfs(i);
        break;
    }

    int best = 0, bestD = -1;
    rep(i, 0, n) if (G[i].depth > bestD) {
        best = i;
        bestD = G[i].depth;
    }

    if (bestD % 2) {
        answer(0);
    }

    while (G[best].depth != bestD/2) {
        best = G[best].par;
    }

    each(v, G) {
        v.par = -1;
        v.depth = 0;
    }
    dfs(best);

    each(v, G) {
        if (sz(v.E) == 1) {
            if (v.depth != k) answer(0);
        } else {
            int h = sz(v.E) - (v.par != -1);
            if (h < 3) answer(0);
        }
    }

    answer(1);
}