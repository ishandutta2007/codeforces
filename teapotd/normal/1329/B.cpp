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
        ll d, m; cin >> d >> m;

        int lead = 0;
        while ((1<<lead)-1 < d) lead++;
        lead--;

        ll ways = 2;

        rep(bit, 1, lead) {
            ways *= (1 << bit) + 1;
            ways %= m;
        }

        if (lead > 0) {
            ways *= d - (1<<lead) + 2;
            ways %= m;
        }

        ways--;
        ways %= m;
        if (ways < 0) ways += m;

        cout << ways << '\n';
    }
}