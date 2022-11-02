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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll c = a%b;
        a = b;
        b = c;
    }
    return a;
}

ll common(ll la, ll lb, ll sa, ll sb) {
    ll a = max(la, lb);
    ll b = min(la+sa, lb+sb);
    return max(0ll, b-a);
}

ll solve(ll la, ll lb, ll sa, ll sb, ll g) {
    lb -= la;
    la = 0;

    lb %= g;
    if (lb < 0) lb += g;

    return common(la, lb, sa, sb);
}

void run() {
    ll la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;

    ll sa = ra-la+1, sb = rb-lb+1;
    ll g = gcd(ta, tb);

    cout << max(solve(la, lb, sa, sb, g), solve(lb, la, sb, sa, g)) << endl;
}