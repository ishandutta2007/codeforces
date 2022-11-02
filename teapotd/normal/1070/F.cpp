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
    int n; cin >> n;
    
    Vi bobOnly, aliceOnly, none;

    ll ans = 0;
    int total = 0, bob = 0, alice = 0;

    rep(i, 0, n) {
        string view;
        int cost;
        cin >> view >> cost;

        if (view == "11") {
            ans += cost;
            total++;
            bob++;
            alice++;
        } else if (view == "00") {
            none.pb(cost);
        } else if (view == "01") {
            bobOnly.pb(cost);
        } else if (view == "10") {
            aliceOnly.pb(cost);
        } else {
            assert(0);
        }
    }

    sort(all(bobOnly), [](int a, int b) { return a > b; });
    sort(all(aliceOnly), [](int a, int b) { return a > b; });

    if (sz(bobOnly) > sz(aliceOnly)) {
        swap(bobOnly, aliceOnly);
        swap(bob, alice);
    }

    each(e, bobOnly) {
        ans += e;
        bob++;
        total++;
    }

    rep(i, 0, sz(bobOnly)) {
        ans += aliceOnly[i];
        alice++;
        total++;
    }

    none.insert(none.end(), aliceOnly.begin()+sz(bobOnly), aliceOnly.end());
    sort(all(none), [](int a, int b) { return a > b; });

    each(e, none) {
        if (2*bob < total+1) break;
        ans += e;
        total++;
    }

    cout << ans << endl;
}