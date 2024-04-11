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
        Vi elems(n);
        each(e, elems) cin >> e;

        int base = 0;

        rep(i, 1, n) {
            if (elems[i-1] != -1 && elems[i] != -1) {
                base = max(base, abs(elems[i]-elems[i-1]));
            }
        }

        int begin = base, end = 1e9+5;

        while (begin+1 < end) {
            int m = (begin+end-1) / 2;
            int from = 0, to = INT_MAX;

            rep(i, 0, n) {
                if (elems[i] != -1) continue;

                if (i > 0 && elems[i-1] != -1) {
                    from = max(from, elems[i-1]-m);
                    to = min(to, elems[i-1]+m);
                }
                if (i+1 < n && elems[i+1] != -1) {
                    from = max(from, elems[i+1]-m);
                    to = min(to, elems[i+1]+m);
                }
            }

            if (from <= to) {
                end = m+1;
            } else {
                begin = m+1;
            }
        }

        int m = begin;
        int from = 0, to = INT_MAX;

        rep(i, 0, n) {
            if (elems[i] != -1) continue;

            if (i > 0 && elems[i-1] != -1) {
                from = max(from, elems[i-1]-m);
                to = min(to, elems[i-1]+m);
            }
            if (i+1 < n && elems[i+1] != -1) {
                from = max(from, elems[i+1]-m);
                to = min(to, elems[i+1]+m);
            }
        }

        cout << begin << ' ' << from << '\n';
    }
}