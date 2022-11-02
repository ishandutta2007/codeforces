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

vector<ll> elems;
int n;
ll k;

int middle(Pii range, int bit) {
    int m = range.x;
    while (m < range.y && !((elems[m] >> bit) & 1)) {
        m++;
    }
    return m;
}

void run() {
    cin >> n >> k;
    elems.resize(n);

    rep(i, 1, n) {
        int j; cin >> j >> elems[i];
        elems[i] ^= elems[j-1];
    }

    ll ans = 0;
    sort(all(elems));

    vector<pair<Pii, Pii>> cur, prev;
    cur.pb({ {0,n}, {0,n} });

    auto addPair = [&cur](int a, int b, int c, int d) {
        if (a < b && c < d) cur.pb({ {a,b}, {c,d} });
    };

    for (int bit = 61; bit >= 0; bit--) {
        ll smaller = 0;
        prev.swap(cur);
        cur.clear();

        each(e, prev) {
            int mx = middle(e.x, bit), my = middle(e.y, bit);
            smaller += ll(mx-e.x.x)*ll(my-e.y.x) + ll(e.x.y-mx)*ll(e.y.y-my);
        }

        each(e, prev) {
            int mx = middle(e.x, bit), my = middle(e.y, bit);

            if (smaller >= k) {
                addPair(e.x.x, mx, e.y.x, my);
                addPair(mx, e.x.y, my, e.y.y);
            } else {
                addPair(e.x.x, mx, my, e.y.y);
                addPair(mx, e.x.y, e.y.x, my);
            }
        }

        if (smaller < k) {
            ans |= 1LL << bit;
            k -= smaller;
        }
    }

    cout << ans << endl;
}