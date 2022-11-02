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
        ll w, h; cin >> w >> h;
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        ll a, b; cin >> a >> b;

        constexpr int INF = 1e9;
        ll ans = INF;
        if (a+x2-x1 <= w) ans = min(ans, min(a-x1, x2 - (w-a)));
        if (b+y2-y1 <= h) ans = min(ans, min(b-y1, y2 - (h-b)));
        ans = max(ans, 0ll);
        cout << (ans < INF ? ans : -1) << '\n';
    }
}