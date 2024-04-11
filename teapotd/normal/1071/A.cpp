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
    ll a, b; cin >> a >> b;

    ll lim = 0;
    while ((lim+1)*(lim+2)/2 <= a+b) lim++;

    ll cur = lim, banned = -1;
    vector<ll> first, sec;

    while (cur > 0 && a >= cur) {
        first.pb(cur);
        a -= cur;
        cur--;
    }

    if (cur > 0 && a > 0) {
        banned = a;
        first.pb(a);
    }

    while (cur > 0) {
        if (cur != banned) {
            assert(b >= cur);
            sec.pb(cur);
            b -= cur;
        }
        cur--;
    }

    cout << sz(first) << endl;
    each(k, first) cout << k << ' ';
    cout << endl;
    cout << sz(sec) << endl;
    each(k, sec) cout << k << ' ';
    cout << endl;
}