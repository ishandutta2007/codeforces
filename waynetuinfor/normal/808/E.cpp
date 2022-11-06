#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int w[maxn], c[maxn];
vector<int> v[4];

struct data {
    long long v, l, r;
    bool operator>(const data &rhs) const { return v > rhs.v; }
    bool operator<(const data &rhs) const { return v < rhs.v; }
    data operator+(const data &rhs) const { return data(v + rhs.v, l + rhs.l, r + rhs.r); }
    data() {}
    data(long long a, int b, int c): v(a), l(b), r(c) {}
} dp[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d %d", &w[i], &c[i]), v[w[i]].push_back(c[i]);
    for (int i = 1; i <= 3; ++i) sort(v[i].begin(), v[i].end()), reverse(v[i].begin(), v[i].end());
    dp[0] = data(0, -1, -1);
    for (int i = 0; i < maxn; ++i) {
        if (i + 1 < maxn && dp[i].l + 1 < v[1].size()) dp[i + 1] = max(dp[i + 1], dp[i] + data(v[1][dp[i].l + 1], 1, 0));
        if (i + 2 < maxn && dp[i].r + 1 < v[2].size()) dp[i + 2] = max(dp[i + 2], dp[i] + data(v[2][dp[i].r + 1], 0, 1));
    }
    for (int i = 1; i < maxn; ++i) dp[i] = max(dp[i], dp[i - 1]);
    long long s = 0, ans = 0;
    for (int i = 0; i <= v[3].size(); ++i) {
        if (m - 3 * i < 0) continue;
        ans = max(ans, s + dp[m - 3 * i].v);
        if (i < v[3].size()) s += v[3][i];
    }
    printf("%lld\n", ans);
    return 0;
}