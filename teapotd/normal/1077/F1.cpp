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

constexpr ll INF = 1e18;

struct MaxQueue {
    using T = ll;
    deque<T> Q;

    void push(T v) {
        while (!Q.empty() && Q.front() < v) Q.pop_front();
        Q.push_front(v);
    }

    void pop(T v) { if (Q.back() == v) Q.pop_back(); }
    T max() const { return Q.back(); }
};

void run() {
    int n, k, x; cin >> n >> k >> x;
    Vi a(n);
    each(b, a) cin >> b;

    vector<ll> dp(n+1, -INF);
    dp[0] = 0;

    rep(j, 1, x+1) {
        MaxQueue Q;
        for (int i = n; i >= n-k+1; i--) Q.push(dp[i]);

        for (int i = n; i >= 1; i--) {
            Q.pop(dp[i]);
            if (i-k >= 0) Q.push(dp[i-k]);
            dp[i] = a[i-1] + Q.max();
        }

        dp[0] = -INF;
    }

    ll ans = -1;
    rep(i, n-k+1, n+1) ans = max(ans, dp[i]);
    cout << ans << endl;
}