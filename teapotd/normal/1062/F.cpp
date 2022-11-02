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
    Vi in, out;
    int bad{0};
    bool seen{0};
};

vector<Vert> G;
Vi order;
vector<bool> zero, one;
int nZero, nOne;

void dfs(int i) {
    if (G[i].seen) return;
    G[i].seen = 1;
    each(e, G[i].out) dfs(e);
    order.pb(i);
}

void check(int i) {
    zero[i] = 1;
    nZero++;

    each(e, G[i].out) {
        if (zero[e]) {
            each(f, G[e].out) if (one[f]) {
                one[f] = 0;
                nOne--;
            }
            zero[e] = 0;
            one[e] = 1;
            nZero--;
            nOne++;
        }
    }

    int covered = 0;
    each(e, G[i].out) covered += one[e];

    if (nZero > 2 || covered < nOne) {
        G[i].bad += 2;
    } else if (nZero == 2) {
        G[i].bad++;
    }
}

void solve() {
    zero.assign(sz(G), 0);
    one.assign(sz(G), 0);
    nZero = nOne = 0;
    each(i, order) check(i);
}

void run() {
    int n, m; cin >> n >> m;
    G.resize(n);

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        G[a-1].out.pb(b-1);
        G[b-1].in.pb(a-1);
    }

    rep(i, 0, n) dfs(i);
    solve();
    each(v, G) v.in.swap(v.out);
    reverse(all(order));
    solve();

    int ans = 0;
    each(v, G) ans += (v.bad <= 1);
    cout << ans << endl;
}