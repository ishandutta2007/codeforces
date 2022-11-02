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
        ll n, g, b; cin >> n >> g >> b;

        ll begin = n, end = 2e18+50;

        while (begin+1 < end) {
            ll m = (begin+end-1) / 2;

            ll full = m / (g+b);
            ll part = m % (g+b);
            ll good = full*g + min(part, g);

            if (good >= (n+1)/2) {
                end = m+1;
            } else {
                begin = m+1;
            }
        }

        cout << begin << '\n';
    }
}