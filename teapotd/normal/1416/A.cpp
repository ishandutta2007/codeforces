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
    int n; cin >> n;
    Vi elems(n);

    each(e, elems) {
        cin >> e;
        e--;
    }

    Vi last(n, -1);
    Vi inter(n, -1);

    rep(i, 0, n) {
        int e = elems[i];
        int dist = i - last[e];
        last[e] = i;
        inter[e] = max(inter[e], dist);
    }

    rep(i, 0, n) {
        inter[i] = max(inter[i], n - last[i]);
    }

    Vi ans(n+2, INT_MAX);
    rep(i, 0, n) {
        ans[inter[i]] = min(ans[inter[i]], i+1);
    }

    rep(i, 1, n+1) {
        ans[i] = min(ans[i], ans[i-1]);
        cout << (ans[i] == INT_MAX ? -1 : ans[i]) << ' ';
    }
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}