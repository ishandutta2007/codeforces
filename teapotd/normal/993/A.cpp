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

bool tri(int x, int y, int L) {
    y = abs(y);
    return x >= 0 && x <= L && y <= x && y <= L-x;
}

bool check(array<Pii, 4>& A, array<Pii, 4>& B) {
    int x1 = INT_MAX, x2 = INT_MIN;
    int y1 = INT_MAX, y2 = INT_MIN;

    each(p, A) {
        x1 = min(x1, p.x);
        y1 = min(y1, p.y);
        x2 = max(x2, p.x);
        y2 = max(y2, p.y);
    }

    bool under = 0, over = 0, left = 0, right = 0;

    each(p, B) {
        if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2) {
            return true;
        }

        under = under || tri(p.x-x1, p.y-y1, x2-x1);
        over = over || tri(p.x-x1, p.y-y2, x2-x1);
        left = left || tri(p.y-y1, p.x-x1, y2-y1);
        right = right || tri(p.y-y1, p.x-x2, y2-y1);
    }
    return under && over && left && right;
}

void rotate(array<Pii, 4>& arr) {
    each(p, arr) {
        int x = p.x, y = p.y;
        p.x = x+y;
        p.y = x-y;
    }
}

void run() {
    array<Pii, 4> A, B;
    each(p, A) cin >> p.x >> p.y;
    each(p, B) cin >> p.x >> p.y;

    if (check(A, B)) {
        cout << "YES\n";
        return;
    }

    rotate(A);
    rotate(B);
    cout << (check(B, A) ? "YES\n": "NO\n");
}