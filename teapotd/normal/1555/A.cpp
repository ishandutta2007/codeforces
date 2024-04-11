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

bool can[1000];
int kek[1000];

void run() {
    can[0] = 1;
    rep(i, 1, 1000) {
        if (i >= 3) can[i] = can[i] || can[i-3];
        if (i >= 4) can[i] = can[i] || can[i-4];
        if (i >= 5) can[i] = can[i] || can[i-5];
    }

    kek[999] = 999;
    for (int i = 998; i >= 0; i--) {
        kek[i] = (can[i] ? i : kek[i+1]);
    }

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        n = (n+1) / 2;
        ll ans = (n < 1000 ? kek[n] : n) * 5;
        cout << ans << '\n';
    }
}