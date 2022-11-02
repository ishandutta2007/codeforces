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

void run() {
    ll n, m, l; cin >> n >> m >> l;

    vector<ll> lens(n);
    each(x, lens) cin >> x;

    ll cur = (lens[0] > l);
    rep(i, 1, n) if (lens[i] > l && lens[i-1] <= l) cur++;

    while (m--) {
        int t; cin >> t;

        if (t == 0) {
            cout << cur << '\n';
        } else {
            int p, d; cin >> p >> d;
            p--;
            if (lens[p] > l) continue;

            lens[p] += d;
            if (lens[p] <= l) continue;

            bool left = (p > 0 && lens[p-1] > l);
            bool right = (p+1 < n && lens[p+1] > l);

            if (!left && !right) cur++;
            if (left && right) cur--;
        }
    }
}