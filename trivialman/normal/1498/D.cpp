#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 5;

int ans[N], dp[N];
LL x;
int n, m, y, t;

inline int get_next(int t, int k, LL x) {
    LL res;
    if (t == 1)
        res = (100000ll * k + x + 99999) / 100000;
    else
        res = (1ll * k * x + 99999) / 100000;
    return res;
}

int main() {
    cin >> n >> m;
    memset(ans, -1, sizeof ans);
    ans[0] = 0;
    rep(i, 1, n) {
        cin >> t >> x >> y;
        rep(j, 0, m) dp[j] = ans[j] >= 0 ? 0 : m + 1;
        rep(j, 0, m) {
            int nxt = get_next(t, j, x);
            if (nxt > m)
                break;
            dp[nxt] = min(dp[nxt], dp[j] + 1);
        }
        rep(j, 0, m) if (ans[j] == -1 && dp[j] <= y) ans[j] = i;
    }
    rep(j, 1, m) printf("%d ", ans[j]);
    return 0;
}