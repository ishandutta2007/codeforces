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

int n, m, s, k;
Vi elems, reach;

bool check(int lim) {
    Vi prefs = {0};
    each(e, elems) prefs.pb(prefs.back() + (e <= lim));

    Vi cur(n+1), prev(n+1);

    rep(i, 1, m+1) {
        prev.swap(cur);
        rep(j, 1, n+1) {
            cur[j] = max(cur[j-1], prev[reach[j-1]] + prefs[j] - prefs[reach[j-1]]);
            if (cur[j] >= k) return true;
        }
    }

    return false;
}

void run() {
    cin >> n >> s >> m >> k;

    elems.resize(n);
    each(e, elems) cin >> e;

    reach.resize(n);
    iota(all(reach), 1);

    rep(i, 0, s) {
        int a, b; cin >> a >> b;
        rep(j, a-1, b) reach[j] = min(reach[j], a-1);
    }

    if (!check(INT_MAX)) {
        cout << -1 << endl;
        return;
    }

    Vi sorted = elems;
    sort(all(sorted));
    int begin = 0, end = n;

    while (begin+1 < end) {
        int mid = (begin+end) / 2;

        if (check(sorted[mid-1])) {
            end = mid;
        } else {
            begin = mid;
        }
    }

    cout << sorted[begin] << endl;
}