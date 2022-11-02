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
        int n, x, y;
        cin >> n >> x >> y;

        Vi ans(n), alt;
        int gr = 2e9;

        rep(step, 1, y-x+1) {
            alt.clear();
            alt.pb(x);
            while (alt.back() < y) {
                alt.pb(alt.back()+step);
            }
            int tmp = alt.back();
            if (sz(alt) < n && x-step > 0) {
                alt.pb(x-step);
                while (sz(alt) < n && alt.back()-step > 0) {
                    alt.pb(alt.back()-step);
                }
            }
            if (sz(alt) < n) alt.pb(tmp+step);
            while (sz(alt) < n) {
                alt.pb(alt.back()+step);
            }
            if (sz(alt) == n && count(all(alt), y) == 1) {
                int altGr = *max_element(all(alt));
                if (altGr < gr) {
                    gr = altGr;
                    ans = alt;
                }
            }
        }

        each(a, ans) cout << a << ' ';
        cout << '\n';
    }
}