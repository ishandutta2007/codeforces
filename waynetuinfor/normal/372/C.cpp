#include <bits/stdc++.h>
using namespace std;

const int maxn = 15e4 + 10, maxm = 300 + 10;
const long long inf = 1e18 + 1;
int a[maxn], b[maxn], t[maxn];
long long dp[2][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, d; cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) cin >> a[i] >> b[i] >> t[i];
    t[0] = 1;
    int cur = 1;
    for (int i = 1; i <= m; ++i) {
        deque<int> dq;
        int ptr = 1;
        for (int j = 1; j <= n; ++j) {
            int l = max(1ll, j - (t[i] - t[i - 1]) * 1ll * d), r = min(1ll * n, j + (t[i] - t[i - 1]) * 1ll *  d);
            while (ptr <= r) {
                while (dq.size() && dp[cur ^ 1][dq.back()] < dp[cur ^ 1][ptr]) dq.pop_back();
                dq.push_back(ptr);
                ++ptr;
            }
            while (dq.size() && dq.front() < l) dq.pop_front();
            dp[cur][j] = dp[cur ^ 1][dq.front()] + b[i] - abs(a[i] - j);
        }
        cur ^= 1;
    }
    long long ans = -inf;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[cur ^ 1][i]);
    cout << ans << endl;
    return 0;
}