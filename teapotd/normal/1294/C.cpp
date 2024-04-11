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

ll findDiv(ll n, ll k) {
    for (ll d = 2; d*d <= n; d++) {
        if (d != k && n%d == 0) {
            return d;
        }
    }
    return -1;
}

void run() {
    int t; cin >> t;

    while (t--) {
        ll n; cin >> n;
        ll d1 = findDiv(n, -1);

        if (d1 == -1) {
            cout << "NO\n";
            continue;
        }

        n /= d1;
        ll d2 = findDiv(n, d1);

        if (d2 == -1) {
            cout << "NO\n";
            continue;
        }

        n /= d2;
        if (n != d1 && n != d2 && n > 1) {
            cout << "YES\n";
            cout << d1 << ' ' << d2 << ' ' << n << '\n';
        } else {
            cout << "NO\n";
        }
    }
}