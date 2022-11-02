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

int dp[int(1e6+5)][3];
string v;

int solve() {
    rep(len, 1, sz(v)+1) {
        int c = (v[len-1] == '1');
        dp[len][0] = dp[len-1][0] + c;
        dp[len][1] = min(dp[len-1][0], dp[len-1][1]) + !c;
        dp[len][2] = min(min(dp[len-1][0], dp[len-1][1]), dp[len-1][2]) + c;
    }
    return min(min(dp[sz(v)][0], dp[sz(v)][1]), dp[sz(v)][2]);
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int ones = int(count(all(s), '1'));
        int ans = n+5;

        rep(r, 0, k) {
            v.clear();
            for (int i = r; i < n; i += k) v.pb(s[i]);
            ans = min(ans, solve() + ones - int(count(all(v), '1')));
        }

        cout << ans << '\n';
    }
}