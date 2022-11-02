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

Vi shared(Pii a, Pii b) {
    Vi ret;
    if (a.x == b.x || a.x == b.y) ret.pb(a.x);
    if (a.y == b.x || a.y == b.y) ret.pb(a.y);
    assert(sz(ret) <= 2);
    return ret;
}

void run() {
    int n, m; cin >> n >> m;
    vector<Pii> A(n), B(m);

    each(p, A) cin >> p.x >> p.y;
    each(p, B) cin >> p.x >> p.y;

    Vi cnt1, cnt2;

    each(p, A) {
        Vi opt;
        each(q, B) {
            Vi tmp = shared(p, q);
            if (sz(tmp) == 1) opt.pb(tmp[0]);
        }

        if (opt.empty()) continue;
        sort(all(opt));

        if (opt[0] != opt.back()) {
            cout << -1 << endl;
            return;
        }
        cnt1.pb(opt[0]);
    }

    each(p, B) {
        Vi opt;
        each(q, A) {
            Vi tmp = shared(p, q);
            if (sz(tmp) == 1) opt.pb(tmp[0]);
        }

        if (opt.empty()) continue;
        sort(all(opt));

        if (opt[0] != opt.back()) {
            cout << -1 << endl;
            return;
        }
        cnt2.pb(opt[0]);
    }

    sort(all(cnt1));
    sort(all(cnt2));
    assert(sz(cnt1) > 0 && sz(cnt2) > 0);

    if (cnt1[0] != cnt2[0] || cnt1[0] != cnt1.back() || cnt2[0] != cnt2.back()) {
        cout << 0 << endl;
    } else {
        cout << cnt1[0] << endl;
    }
}