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
    int n, m; cin >> n >> m;
    Vi b(n), g(m);

    each(k, b) cin >> k;
    each(k, g) cin >> k;

    sort(all(b));
    sort(all(g));

    if (b[n-1] > g[0]) {
        cout << "-1\n";
        return;
    }

    ll ans = 0;
    rep(i, 0, n-1) ans += b[i];
    ans *= m;
    each(k, g) ans += k;
    if (b[n-1] != g[0]) ans += b[n-1] - b[n-2];

    cout << ans << endl;
}