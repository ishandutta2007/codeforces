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

ll countInversions(Vi perm) {
    ll ret = 0, cont = 1;
    Vi odd;

    while (cont) {
        odd.assign(sz(perm)+1, 0);
        cont = 0;

        rep(i, 0, sz(perm)) {
            if (perm[i] % 2) odd[perm[i]]++;
            else ret += odd[perm[i]+1];
            cont += perm[i] /= 2;
        }
    }
    return ret;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        Vi a(n), b(n);
        int cnt[2] = {};

        rep(i, 0, n) {
            int e; cin >> e;
            if (e % 2) {
                a[i] = cnt[1]*2;
                b[i] = cnt[1]*2 + 1;
            } else {
                a[i] = cnt[0]*2 + 1;
                b[i] = cnt[0]*2;
            }
            cnt[e%2]++;
        }

        ll ans = INT64_MAX;

        if (cnt[0] == cnt[1] || cnt[0] == cnt[1]+1) {
            ans = min(ans, countInversions(b));
        }

        if (cnt[0] == cnt[1] || cnt[0]+1 == cnt[1]) {
            ans = min(ans, countInversions(a));
        }

        if (ans == INT64_MAX) ans = -1;
        cout << ans << '\n';
    }
}