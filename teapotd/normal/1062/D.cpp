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

vector<vector<Pii>> G;
vector<bool> seen;
int n;

void edge(int i, int j, int w) {
    G[i+n].pb({j+n, w});
    G[j+n].pb({i+n, w});
}

ll dfs(int i) {
    if (seen[i]) return 0;
    seen[i] = 1;
    ll ret = 0;
    each(e, G[i]) ret += dfs(e.x) + e.y;
    return ret;
}

void run() {
    cin >> n;
    G.resize(n*2+1);
    seen.resize(n*2+1);

    for (int i = 2; i <= n; i++) {
        int w = 2;
        for (int j = i*2; j <= n; j += i, w++) {
            edge(i, j, w);
            edge(-i, j, w);
            edge(i, -j, w);
            edge(-i, -j, w);
        }
    }

    ll ans = 0;
    rep(i, 0, sz(G)) ans = max(ans, dfs(i)/2);
    cout << ans << endl;
}