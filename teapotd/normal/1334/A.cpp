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
        vector<Pii> stats(n);
        each(k, stats) cin >> k.x >> k.y;

        bool ans = 1;

        if (stats[0].x < stats[0].y) {
            ans = 0;
        } else {
            rep(i, 1, n) {
                int a = stats[i].x - stats[i-1].x;
                int b = stats[i].y - stats[i-1].y;
                if (a < 0 || b < 0 || a < b) {
                    ans = 0;
                    break;
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
}