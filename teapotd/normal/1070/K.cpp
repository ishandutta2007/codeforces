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
    int n, k; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;

    ll sum = 0;
    each(e, elems) sum += e;

    if (sum % k) {
        cout << "No\n";
        return;
    }

    ll per = sum / k;
    Vi ans;
    ll last = 0;
    int ind = 0;

    rep(i, 0, n) {
        last += elems[i];
        
        if (last > per) {
            cout << "No\n";
            return;
        }

        if (last == per) {
            ans.pb(i-ind+1);
            ind = i+1;
            last = 0;
        }
    }

    if (sz(ans) != k || last > 0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        each(e, ans) cout << e << ' ';
        cout << endl;
    }
}