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

void run() {
    int t; cin >> t;

    while (t--) {
        int m; cin >> m;
        vector<ll> A(m), B(m);
        each(k, B) cin >> k;
        each(k, A) cin >> k;
        rep(i, 1, m) A[i] += A[i-1];
        for (int i = m-2; i >= 0; i--) B[i] += B[i+1];

        ll ans = 1e18;

        rep(i, 0, m) {
            ll alt = (i > 0 ? A[i-1] : 0);
            alt = max(alt, (i < m-1 ? B[i+1] : 0));
            ans = min(ans, alt);
        }

        cout << ans << '\n';
    }
}