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
        each(e, elems) {
            cin >> e;
            e--;
        }

        Vi cnt(205);
        each(e, elems) cnt[e]++;

        int ans = 0;
        each(c, cnt) ans = max(ans, c);

        rep(a, 0, 205) {
            Vi cp = cnt;
            int pref = 0, suf = n-1;

            for (int x = 1;; x++) {
                while (pref < n && elems[pref] != a) {
                    cp[elems[pref]]--; pref++;
                }
                cp[a]--; pref++;
                while (suf >= 0 && elems[suf] != a) {
                    cp[elems[suf]]--; suf--;
                }
                cp[a]--; suf--;
                if (pref > suf) break;
                each(c, cp) ans = max(ans, x*2 + c);
            }
        }

        cout << ans << '\n';
    }
}