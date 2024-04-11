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
        string a, b; cin >> a >> b;

        auto mex = [&](int x, int y) {
            int cnt[2] = {};
            rep(i, x, y) {
                cnt[a[i]-'0']++;
                cnt[b[i]-'0']++;
            }
            return (cnt[0] > 0 ? (cnt[1] > 0 ? 2 : 1) : 0);
        };

        Vi dp(n+1);

        rep(i, 1, n+1) {
            rep(j, max(0, i-5), i) {
                dp[i] = max(dp[i], dp[j] + mex(j, i));
            }
        }

        cout << dp.back() << '\n';
    }
}