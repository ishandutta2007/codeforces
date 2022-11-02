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
    Vi elems;

    ll ans = 0;
    int odd = 0, even = 0;

    rep(i, 0, n) {
        ll tmp; cin >> tmp;
        int cur = __builtin_popcountll(tmp);
        elems.pb(cur);

        if (cur % 2) {
            swap(even, odd);
            odd++;
        } else {
            even++;
        }

        ans += even;

        ll sum = 0;
        int most = 0;

        rep(j, 0, 64) {
            int k = i-j;
            if (k < 0) break;

            sum += elems[k];
            most = max(most, elems[k]);

            if (sum%2 == 0 && sum-most < most) {
                ans--;
            }
        }
    }

    cout << ans << endl;
}