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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int cnt[32] = {};

        rep(i, 0, n) {
            int a; cin >> a;
            rep(bit, 0, 30) {
                cnt[bit] += ((a >> bit) & 1);
            }
        }

        int g = 0;
        each(c, cnt) g = gcd(g, c);
        Vi ans;

        if (g != 0) {
            for (int d = 1; d*d <= g; d++) {
                if (g%d == 0) {
                    ans.pb(d);
                    if (d*d != g) ans.pb(g/d);
                }
            }
        } else {
            rep(i, 1, n+1) ans.pb(i);
        }

        sort(all(ans));
        each(a, ans) cout << a << ' ';
        cout << '\n';
    }
}