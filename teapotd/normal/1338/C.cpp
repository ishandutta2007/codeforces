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

ll solve(ll n) {
    ll num = n/3;

    for (ll base = 0;; base += 2) {
        ll cnt = 1ll << base;

        if (num >= cnt) {
            num -= cnt;
            continue;
        }

        ll a = cnt + num;
        ll b = cnt*2;
        b ^= ((num & 0b01010101010101010101010101010101010101010101010101010101010101) << 1);
        b ^= ((num & 0b10101010101010101010101010101010101010101010101010101010101010) >> 1) * 3;

        if (n%3 == 0) return a;
        if (n%3 == 1) return b;
        return a^b;
    }
}

void run() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << solve(n-1) << '\n';
    }
}