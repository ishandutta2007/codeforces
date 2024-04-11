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
        string s; cin >> s;
        Vi pref = {0};
        each(c, s) pref.pb(pref.back() + (c == 'R'));

        int begin = 1, end = sz(s)+5;

        while (begin+1 < end) {
            int m = (begin+end-1) / 2;
            bool ok = 1;

            rep(i, 0, sz(s)-m+1) {
                if (pref[i+m]-pref[i] <= 0) {
                    ok = 0;
                    break;
                }
            }

            if (ok) {
                end = m+1;
            } else {
                begin = m+1;
            }
        }

        cout << begin << '\n';
    }
}