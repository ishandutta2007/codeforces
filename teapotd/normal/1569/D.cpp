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
        int n, m, k; cin >> n >> m >> k;
        Vi x(n), y(m);
        each(e, x) cin >> e;
        each(e, y) cin >> e;

        Vi cnt1(n+1), cnt2(m+1);
        map<Pii, int> kek1, kek2;
        ll ans = 0;

        while (k--) {
            int xp, yp; cin >> xp >> yp;
            int i = int(lower_bound(all(x), xp) - x.begin());
            int j = int(lower_bound(all(y), yp) - y.begin());
            if (i >= sz(x) || x[i] != xp) {
                ans += cnt1[i]++;
                ans -= kek1[{i,j}]++;
            } else if (j >= sz(y) || y[j] != yp) {
                ans += cnt2[j]++;
                ans -= kek2[{i,j}]++;
            }
        }

        cout << ans << '\n';
    }
}