#include <bits/stdc++.h>
using namespace std;

const int kN = 1'000'000 + 5;
const long long kInf = 1'000'000'000'000'000;
int a[kN], b[kN];
char s[kN];

using Data = pair<long long, int>;
Data dp[kN];

Data operator+(const Data &lhs, const Data &rhs) {
    return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

int Solve(int n, int k, int l) {
    auto Calc = [&](int p) {
        dp[0] = make_pair(0, 0);
        Data pf = make_pair(-kInf, 0);
        for (int i = 1, j = 0; i <= n; ++i) {
            if (j == i - l) {
                pf = max(pf, dp[j]);
                ++j;
            }
            dp[i] = dp[i - 1];
            if (i >= l) dp[i] = max(dp[i], pf + make_pair(-p + b[i] - b[i - l], 1));
        }
        // printf("Calc p = %d dp[n] = %lld tr = %d\n", p, dp[n].first, dp[n].second);
        return dp[n];
    };
    int p = 0;
    for (int d = 30; d >= 0; --d) {
        int pv = p + (1 << d);
        auto res = Calc(pv);
        if (res.second == k) return res.first + 1LL * k * pv;
        if (res.second > k) p = pv;
    }
    auto res = Calc(p);
    return res.first + 1LL * k * p;
}

int main() {
    int n, k, l; scanf("%d%d%d", &n, &k, &l);
    if (1LL * k * l >= n) {
        puts("0");
        return 0;
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = (s[i] >= 'A' && s[i] <= 'Z');
        b[i] = b[i - 1] + a[i];
    }
    int ans = (n - b[n]) + Solve(n, k, l);
    // int ans = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = (s[i] >= 'a' && s[i] <= 'z');
        b[i] = b[i - 1] + a[i];
    }
    // printf("Solve = %d\n", Solve(n, k, l));
    ans = max(ans, (n - b[n]) + Solve(n, k, l));
    printf("%d\n", n - ans);
}