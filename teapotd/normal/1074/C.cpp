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

ll dist(Pii a, Pii b) {
    return abs(a.x-b.x) + abs(a.y-b.y);
}

void run() {
    int n; cin >> n;
    vector<Pii> points(n);
    each(p, points) cin >> p.x >> p.y;

    ll four = 0;
    ll minX = INT64_MAX, minY = INT64_MAX;
    ll maxX = INT64_MIN, maxY = INT64_MIN;

    rep(i, 0, n) {
        four += dist(points[i], points[(i+1)%n]);
        minX = min(minX, ll(points[i].x));
        minY = min(minY, ll(points[i].y));
        maxX = max(maxX, ll(points[i].x));
        maxY = max(maxY, ll(points[i].y));
    }

    vector<Pii> extremes;
    each(p, points) if (p.x == minX || p.x == maxX || p.y == minY || p.y == maxY) {
        extremes.pb(p);
    }

    ll three = 0;

    rep(i, 0, sz(extremes)) rep(j, i+1, sz(extremes)) each(p, points) {
        Pii q = extremes[i], r = extremes[j];
        ll alt = dist(p, q) + dist(p, r) + dist(q, r);
        three = max(three, alt);
    }

    cout << three << ' ';
    rep(i, 4, n+1) cout << four << ' ';
    cout << endl;
}