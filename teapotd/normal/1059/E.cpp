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
    Vi edges, jumps;
    int level, pre, post;
    ll weight, sum;
    int reach;
};

int n, L;
ll S, ans = 0;
vector<Vert> G;
int counter;

void initLCA(int i, int parent=-1, int d=0) {
    if (parent >= 0) {
        G[i].sum += G[parent].sum + G[parent].weight;
    } else {
        G[i].sum = 0;
    }

    G[i].level = d;
    G[i].jumps.pb(parent < 0 ? i : parent);
    G[i].pre = ++counter;
    each(e, G[i].edges) if (e != parent)
        initLCA(e, i, d+1);
    G[i].post = ++counter;

    if (parent < 0) {
        int depth = int(log2(sz(G))) + 2;
        rep(j, 0, depth) each(vert, G)
            vert.jumps.pb(G[vert.jumps[j]].jumps[j]);
    }
}

int getReach(int a, int minLevel, ll minSum) {
    for (int j = sz(G[a].jumps)-1; j >= 0; j--) {
        int k = G[a].jumps[j];
        if (minLevel < G[k].level && minSum <= G[k].sum) {
            a = k;
        }
    }
    return G[a].level;
}

void dfs(int i, int p) {
    int& reach = G[i].reach = G[i].level+1;

    each(e, G[i].edges) if (e != p) {
        dfs(e, i);
        reach = min(reach, G[e].reach);
    }

    if (reach > G[i].level) {
        int lvl = G[i].level-L;
        ll sum = G[i].sum-S+G[i].weight;
        G[i].reach = getReach(i, lvl, sum);
        ans++;
    }
}

void run() {
    cin >> n >> L >> S;
    G.resize(n);

    rep(i, 0, n) cin >> G[i].weight;

    rep(i, 1, n) {
        int j; cin >> j;
        j--;
        G[i].edges.pb(j);
        G[j].edges.pb(i);
    }

    each(v, G) if (v.weight > S) {
        cout << -1 << endl;
        return;
    }

    initLCA(0);
    dfs(0, -1);
    cout << ans << endl;
}