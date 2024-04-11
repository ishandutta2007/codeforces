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

vector<pair<ll, int>> dp;

pair<ll, int> paramSolve(const Vi& vec, int n, int l, ll cost) {
    dp.resize(n+1);
    dp[0] = {0, 0};

    rep(pref, 1, n+1) {
        dp[pref] = dp[pref-1];
        dp[pref].x += vec[pref-1];

        auto alt = (pref >= l ? dp[pref-l] : mp(0LL, 0));
        alt.x += cost;
        alt.y++;
        dp[pref] = min(dp[pref], alt);
    }

    return dp.back();
}

int solve(const Vi& vec, int n, int k, int l) {
    ll begin = 0, end = 1e7;

    while (begin+1 < end) {
        ll mid = (begin+end) / 2;
        auto tmp = paramSolve(vec, n, l, mid);
        if (tmp.y >= k) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    while (1) {
        auto tmp = paramSolve(vec, n, l, begin);
        if (tmp.y <= k) {
            return int(tmp.x - begin*k);
        }
        begin++;
    }
}

void run() {
    int n, k, l; cin >> n >> k >> l;
    string s; cin >> s;

    Vi vec;
    each(c, s) vec.pb(c >= 'A' && c <= 'Z');

    int ans = solve(vec, n, k, l);
    each(e, vec) e = !e;
    ans = min(ans, solve(vec, n, k, l));

    cout << ans << endl;
}