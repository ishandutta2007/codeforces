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

int dp[16][16][1<<16];

void run() {
    int n, m;
    cin >> n >> m;

    vector<Vi> mat(n, Vi(m));
    each(v, mat) each(k, v) cin >> k;

    vector<Vi> dist(n, Vi(n)), dist2(n, Vi(n));

    rep(i, 0, n) rep(j, 0, n) {
        dist[i][j] = dist2[i][j] = INT_MAX;
        rep(k, 0, m) {
            dist[i][j] = min(dist[i][j], abs(mat[i][k]-mat[j][k]));
            if (k > 0) {
                dist2[i][j] = min(dist2[i][j], abs(mat[i][k-1]-mat[j][k]));
            }
        }
    }

    if (n == 1) {
        cout << dist2[0][0] << '\n';
        return;
    }

    rep(i, 0, n) {
        dp[i][i][1<<i] = INT_MAX;
    }

    rep(mask, 0, 1<<n) {
        for (int a = mask; a; a &= a-1) {
            int first = __builtin_ctz(a);
            for (int b = mask ^ (1<<first); b; b &= b-1) {
                int last = __builtin_ctz(b);
                int rest = mask ^ (1<<last);
                int tmp = 0;
                for (int c = rest; c; c &= c-1) {
                    int prv = __builtin_ctz(c);
                    tmp = max(tmp, min(dp[first][prv][rest], dist[prv][last]));
                }
                dp[first][last][mask] = tmp;
            }
        }
    }

    int ans = 0;
    rep(i, 0, n) rep(j, 0, n) if (i != j) {
        ans = max(ans, min(dp[i][j][(1<<n)-1], dist2[j][i]));
    }

    cout << ans << endl;
}