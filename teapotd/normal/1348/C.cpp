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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        sort(all(s));

        vector<string> ans(k);
        rep(i, 0, k) ans[i].pb(s[i]);

        if (s[k-1] != s[0]) {
            cout << ans[k-1] << '\n';
        } else if (s[k] != s[n-1]) {
            rep(i, k, n) ans[0].pb(s[i]);
            cout << ans[0] << '\n';
        } else {
            rep(i, k, n) ans[i%k].pb(s[i]);
            cout << ans[0] << '\n';
        }
    }
}