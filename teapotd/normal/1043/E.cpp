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
    int n, m; cin >> n >> m;
    vector<ll> x(n), y(n);

    rep(i, 0, n) {
        cin >> x[i] >> y[i];
    }

    vector<ll> ans(n);

    ll ySum = 0;
    each(a, y) ySum += a;

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        a--; b--;

        ll d = min(x[a]+y[b], x[b]+y[a]);
        ans[a] -= d;
        ans[b] -= d;
    }

    rep(i, 0, n) {
        ans[i] += ySum + y[i]*(n-2);
    }

    vector<ll> z(n);
    rep(i, 0, n) z[i] = x[i]-y[i];

    Vi sorted(n);
    iota(all(sorted), 0);
    sort(all(sorted), [&](int i, int j) { return z[i] < z[j]; });

    ll pref = 0;
    ll k = n-1;
    each(i, sorted) {
        ans[i] += pref;
        ans[i] += k*z[i];
        pref += z[i];
        k--;
    }

    each(a, ans) cout << a << ' ';
    cout << endl;
}