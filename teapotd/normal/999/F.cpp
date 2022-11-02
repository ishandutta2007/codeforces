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

ll solve(int k, int cards, int players, Vi& joy) {
    vector<Vi> dp(cards+1, Vi(players+1)); // remaining cards, remaining players -> total joy

    rep(i, 1, cards+1) {
        rep(j, 1, players+1) {
            rep(c, 0, min(i, k)+1) {
                dp[i][j] = max(dp[i][j], dp[i-c][j-1] + joy[c]);
            }
        }
    }

    return dp[cards][players];
}

void run() {
    int n, k; cin >> n >> k;
    Vi cnt(1e5+5);
    Vi want(1e5+5);
    Vi joy(k+1);

    rep(i, 0, n*k) {
        int c; cin >> c;
        cnt[c]++;
    }

    rep(i, 0, n) {
        int c; cin >> c;
        want[c]++;
    }

    rep(i, 0, k) {
        cin >> joy[i+1];
    }

    ll ans = 0;

    rep(i, 0, sz(cnt)) if (cnt[i] > 0 && want[i] > 0) {
        ans += solve(k, cnt[i], want[i], joy);
    }

    cout << ans << endl;
}