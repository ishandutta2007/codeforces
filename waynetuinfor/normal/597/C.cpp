#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];
long long dp[12][maxn];

struct Fenwick {
#define lowbit(x) (x & -x)
    long long bit[maxn];
    void init() {
        memset(bit, 0, sizeof(bit));
    }
    void add(int x, long long v) {
        for (int i = x; i < maxn; i += lowbit(i)) bit[i] += v;
    }
    long long qry(int x) {
        long long ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += bit[i];
        return ret;
    }
#undef lowbit
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) dp[1][i] = 1;
    for (int i = 2; i <= k + 1; ++i) {
        bit.init();
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = bit.qry(a[j] - 1);
            bit.add(a[j], dp[i - 1][j]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += dp[k + 1][i];
    cout << ans << endl;
    return 0;
}