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
    Vi elems(n*2);
    each(e, elems) cin >> e;

    Vi kek;
    int pos = 0;

    while (pos < n*2) {
        int end = pos+1;
        while (end < n*2 && elems[end] < elems[pos]) {
            end++;
        }
        kek.pb(end-pos);
        pos = end;
    }

    vector<bool> dp(n+1);
    dp[0] = 1;

    each(e, kek) {
        for (int i = n; i >= e; i--) {
            dp[i] = dp[i] || dp[i-e];
        }
    }

    cout << (dp[n] ? "YES\n" : "NO\n");
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}