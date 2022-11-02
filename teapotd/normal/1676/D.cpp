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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

void run() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<Vi> elems(n, Vi(m));
        each(r, elems) each(e, r) cin >> e;
        ll ans = 0;
        rep(i, 0, n) rep(j, 0, m) {
            ll alt = 0;
            for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) alt += elems[x][y];
            for (int x = i, y = j; x < n && y < m; x++, y++) alt += elems[x][y];
            for (int x = i, y = j; x >= 0 && y < m; x--, y++) alt += elems[x][y];
            for (int x = i, y = j; x < n && y >= 0; x++, y--) alt += elems[x][y];
            alt -= elems[i][j]*3;
            ans = max(ans, alt);
        }
        cout << ans << '\n';
    }
}