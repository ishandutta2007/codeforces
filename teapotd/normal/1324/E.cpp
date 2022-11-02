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

int dp[2005][2005];

void run() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    Vi elems(n);
    each(e, elems) cin >> e;

    auto get = [&](int i, int j) {
        j %= h;
        return dp[i][j] + (j >= l && j <= r);
    };

    for (int i = n-1; i >= 0; i--) {
        rep(j, 0, h) {
            dp[i][j] = max(get(i+1, j+elems[i]), get(i+1, j+elems[i]-1));
        }
    }

    cout << dp[0][0] << '\n';
}