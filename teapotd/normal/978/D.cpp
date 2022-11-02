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
    int n; cin >> n;
    vector<ll> elems(n);
    each(e, elems) cin >> e;

    if (n <= 2) {
        cout << 0 << endl;
        return;
    }

    auto check = [&](ll start, ll step) {
        int ret = 0;
        rep(i, 0, n) {
            ll diff = start + step*i - elems[i];
            if (abs(diff) > 1) return INT_MAX;
            ret += diff != 0;
        }
        return ret;
    };

    int ans = INT_MAX;

    rep(i, -1, 2) rep(j, -1, 2) {
        ans = min(ans, check(elems[0]+i, elems[1]+j-elems[0]-i));
    }

    if (ans == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}