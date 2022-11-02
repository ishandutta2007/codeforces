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
    bool our{0}, seen{0};
};

vector<Vert> G;

int dfs(int i) {
    if (G[i].our) return i;
    if (G[i].seen) return -1;
    G[i].seen = 1;

    each(e, G[i].E) {
        int r = dfs(e);
        if (r >= 0) return r;
    }
    return -1;
}

void handle() {
    int n; cin >> n;
    G.assign(n, {});

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].E.pb(b-1);
        G[b-1].E.pb(a-1);
    }

    int k; cin >> k;
    rep(i, 0, k) {
        int a; cin >> a;
        G[a-1].our = 1;
    }

    cin >> k;
    Vi their(k);
    each(e, their) cin >> e;

    cout << "B " << their[0] << endl;
    int some; cin >> some;

    int common = dfs(some-1);
    assert(common >= 0);

    cout << "A " << common+1 << endl;
    cin >> some;

    if (find(all(their), some) != their.end()) {
        cout << "C " << common+1 << endl;
    } else {
        cout << "C -1" << endl;
    }
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}