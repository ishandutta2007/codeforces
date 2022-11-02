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

constexpr ll MAX_COORD = ll(1e9);
constexpr ll BS_RANGE = 3*MAX_COORD;

Pii coord(ll i) {
    if (i < MAX_COORD) {
        return { 0, i };
    } else if (i < MAX_COORD*2) {
        return { i-MAX_COORD, MAX_COORD };
    } else {
        return { MAX_COORD, MAX_COORD-(i-MAX_COORD*2) };
    }
}

void run() {
    ll n; cin >> n;

    ll begin = 0, end = BS_RANGE;

    rep(i, 0, n) {
        ll mid = (begin+end) / 2;
        Pii c = coord(mid);
        cout << c.x << ' ' << c.y << endl;

        string col;
        cin >> col;

        if (col[0] == 'w') {
            begin = mid;
        } else {
            end = mid;
        }
    }

    deb(begin, end);
    Pii c = coord(begin+1);
    cout << 1000 << ' ' << 0 << ' ' << c.x << ' ' << c.y << endl;
}