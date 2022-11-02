#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

ll delta(ll a, ll x) {
    return a - 3*x*x - 3*x - 1;
}

ll taken(ll a, ll minDelta) {
    ll begin = -1, end = 2e9+50;
    while (begin+1 < end) {
        ll m = (begin+end) / 2;
        if (delta(a, m) >= minDelta) {
            begin = m;
        } else {
            end = m;
        }
    }
    return min(end, a);
}

void run() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> elems(n);
    each(e, elems) cin >> e;

    ll begin = -4e18, end = 4e18;

    while (begin+1 < end) {
        ll m = begin+end-1;
        if (m%2) m--;
        m /= 2;
        ll tot = 0;
        each(e, elems) tot += taken(e, m);
        if (tot > k) {
            begin = m+1;
        } else {
            end = m+1;
        }
    }

    vector<ll> ans;
    ll tot = 0;

    each(e, elems) {
        ans.pb(taken(e, begin));
        tot += ans.back();
    }

    rep(i, 0, n) {
        ll can = taken(elems[i], begin-1) - ans[i];
        can = min(can, k-tot);
        ans[i] += can;
        tot += can;
    }

    each(e, ans) cout << e << ' ';
    cout << '\n';
}