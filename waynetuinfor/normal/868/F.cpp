#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18 + 1;
long long dp[2][maxn], ans;
int cnt[maxn], a[maxn], t[2][maxn], nl = 1, nr = 0;

void add(int now) {
    ans += cnt[a[now]];
    ++cnt[a[now]];
}

void sub(int now) {
    --cnt[a[now]];
    ans -= cnt[a[now]];
}

long long query(int l, int r) {
    while (nr < r) add(++nr);
    while (nr > r) sub(nr--);
    while (nl > l) add(--nl);
    while (nl < l) sub(nl++);
    return ans;
}

void go(int cur, int l, int r, int tl, int tr) {
    if (l > r) return;
    int m = (l + r) >> 1;
    dp[cur][m] = inf;
    for (int i = tl; i <= min(tr, m - 1); ++i) {
        long long tmp = dp[cur ^ 1][i] + query(i + 1, m);
        if (tmp < dp[cur][m]) {
            dp[cur][m] = tmp;
            t[cur][m] = i;
        }
    }
    go(cur, l, m - 1, tl, t[cur][m]); go(cur, m + 1, r, t[cur][m], tr);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    fill(dp[0], dp[0] + maxn, inf);
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) go(i & 1, 1, n, 0, n - 1);
    cout << dp[k & 1][n] << endl;
    return 0;
}