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

#define double long double

using vec2 = pair<double, double>;

vector<vec2> points;
int n;

bool check(double r) {
    double low = -1e50, high = 1e50;
    double rSqr = r*r;

    each(p, points) {
        double b = fabs(r-p.y);
        double aSqr = rSqr - b*b;
        if (aSqr < 0) return 0;

        double a = sqrtl(aSqr);
        low = max(low, p.x-a);
        high = min(high, p.x+a);
    }

    return low <= high;
}

void run() {
    cin >> n;
    bool neg = 0, pos = 0;

    points.resize(n);
    each(p, points) {
        cin >> p.x >> p.y;
        if (p.y < 0) neg = 1;
        else pos = 1;
    }

    if (pos && neg) {
        cout << -1 << endl;
        return;
    }

    if (neg) {
        each(p, points) p.y = -p.y;
    }

    double begin = 0.1, end = 2e14;

    rep(i, 0, 128) {
        double mid = (begin+end)/2;
        if (check(mid)) {
            end = mid;
        } else {
            begin = mid;
        }
    }

    cout << (begin+end)/2 << endl;
}