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

void solve() {
    int n, m; cin >> n >> m;
    vector<Pii> elems(m);
    each(e, elems) cin >> e.x >> e.y;
    sort(all(elems));

    vector<ll> suf(m+1);
    for (int i = m-1; i >= 0; i--) {
        suf[i] = suf[i+1] + elems[i].x;
    }

    ll ans = 0;

    rep(i, 0, m) {
        int j = int(lower_bound(all(elems), mp(elems[i].y, -1)) - elems.begin());
        j = max(j, m-n+1);

        int cnt = n - (m-j);
        ll alt = suf[j];
        if (j > i) alt += elems[i].x, cnt--;
        alt += ll(elems[i].y) * cnt;

        ans = max(ans, alt);
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}