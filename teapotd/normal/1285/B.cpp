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
        int n; cin >> n;
        vector<ll> elems(n);
        each(e, elems) cin >> e;

        ll tot = accumulate(all(elems), 0LL);
        ll cur1 = 0, cur2 = 0;
        ll best = 0;

        rep(i, 0, n-1) {
            ll k = elems[i];
            cur1 = max(cur1+k, 0LL);
            best = max(best, cur1);
        }

        rep(i, 1, n) {
            ll k = elems[i];
            cur2 = max(cur2+k, 0LL);
            best = max(best, cur2);
        }

        cout << (tot > best ? "YES\n" : "NO\n");
    }
}