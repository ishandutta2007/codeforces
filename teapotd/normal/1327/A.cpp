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

    vector<ll> kek;
    kek.pb(0);

    for (int i = 1; kek.back() < int(2e7); i += 2) {
        kek.pb(kek.back() + i);
    }

    while (t--) {
        ll n, k; cin >> n >> k;
        bool ans = 0;

        if (k < sz(kek)) {
            n -= kek[k];
            ans = n >= 0 && n%2 == 0;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}