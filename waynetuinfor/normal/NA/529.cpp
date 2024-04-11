#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int x[maxn], y[maxn];
long long dp[maxn], a[maxn];

long long f(int i, int q) {
    int a = -x[i];
    long long b = dp[i];
    return a * 1ll * q + b;
}

bool g(int i, int j, int k) {
    int ai = -x[i], aj = -x[j], ak = -x[k];
    long long bi = dp[i], bj = dp[j], bk = dp[k];
    assert(aj - aj >= 0);
    assert(ai - ak >= 0);
    return (bk - bj) * 1.0 * (aj - ai) >= (bi - bj) * 1.0 * (aj - ak);
} 

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d%lld", &x[i], &y[i], &a[i]);
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        return x[i] < x[j];
    });
    deque<int> dq;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        dp[v[i]] = x[v[i]] * 1ll * y[v[i]] - a[v[i]];
        while (dq.size() >= 2 && f(dq[0], y[v[i]]) <= f(dq[1], y[v[i]]))
            dq.pop_front();
        if (dq.size()) dp[v[i]] = max(dp[v[i]], dp[v[i]] + f(dq[0], y[v[i]]));
        while (dq.size() >= 2 && g(dq[dq.size() - 1], dq[dq.size() - 2], v[i]))
            dq.pop_back();
        dq.push_back(v[i]);
        ans = max(ans, dp[v[i]]);
    }
    printf("%lld\n", ans);
    return 0;
}