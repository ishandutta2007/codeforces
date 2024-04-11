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

string s;
Vi prefs[26];

void run() {
    cin >> s;
    int q; cin >> q;

    rep(c, 0, 26) {
        prefs[c].pb(0);
        rep(i, 0, sz(s)) {
            prefs[c].pb(prefs[c].back() + (s[i]-'a' == c));
        }
    }

    rep(t, 0, q) {
        int l, r; cin >> l >> r;
        l--;

        bool ok = (r-l <= 1 || s[l] != s[r-1]);

        if (!ok) {
            int cnt = 0;
            rep(i, 0, 26) {
                cnt += prefs[i][r]-prefs[i][l] > 0;
            }
            ok = (cnt >= 3);
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
}