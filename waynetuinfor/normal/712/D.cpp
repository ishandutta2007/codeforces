#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxk = 4e5 + 1000, mod = 1e9 + 7;
int dpa[2][maxk], dpb[2][maxk];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }


int partial(int *dp, int l, int r) {
    l += 200010; r += 200010;
    if (l <= 0) l = 1;
    if (r > 200000 + 200010) r = 200000 + 200010;
    return sub(dp[r], dp[l - 1]);
}

void cal(int dp[2][maxk], int p, int k, int t) {
    for (int i = p + 200010; i <= 200000 + 200010; ++i) dp[0][i] = 1;
    for (int i = 1; i <= t; ++i) {
        int cur = i & 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        // cout << "t = " << i << endl;
        for (int pt = -200000; pt <= 200000; ++pt) {
            dp[cur][pt + 200010] = partial(dp[cur ^ 1], pt - k, pt + k);
            dp[cur][pt + 200010] = add(dp[cur][pt + 200010], dp[cur][pt - 1 + 200010]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, k, t; cin >> a >> b >> k >> t;
    cal(dpa, a, k, t); cal(dpb, b, k, t); 
    int pb = 0, ans = 0;
    for (int i = -200000; i <= 200000; ++i) {
        int da = sub(dpa[t & 1][i + 200010], dpa[t & 1][i - 1 + 200010]), db = sub(dpb[t & 1][i + 200010], dpb[t & 1][i - 1 + 200010]);
            // cout << "pb = " << pb << " da = " << da << " db = " << db << endl;
            // cout << "ans = " << ans << endl;
        ans = add(ans, mul(pb, da));
        pb = add(pb, db);
    }
    cout << ans << endl;
    return 0;
}