#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
long long s[maxn], dp[maxn];

struct sparse {
    int dat[20][maxn], lgt[maxn];
    void init(int n) {
        lgt[1] = 0;
        for (int i = 2; i <= n; ++i) lgt[i] = lgt[i >> 1] + 1;
        for (int i = 0; i < n; ++i) dat[0][i] = a[i + 1];
        for (int i = 1; (1 << i) <= n; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) dat[i][j] = min(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
        }
    }
    int query(int l, int r) {
        --l; --r;
        int p = lgt[r - l + 1];
        return min(dat[p][l], dat[p][r - (1 << p) + 1]);
    }
} sp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c; cin >> n >> c;
    for (int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] + a[i];
    dp[0] = 0;
    sp.init(n);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a[i];
        if (i - c >= 0) dp[i] = min(dp[i], dp[i - c] + s[i] - s[i - c] - sp.query(i - c + 1, i));
    }
    cout << dp[n] << endl;
    return 0;
}