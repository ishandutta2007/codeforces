#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
double p[maxn], u[maxn];

pair<double, int> operator+(const pair<double, int> &a, const pair<double, int> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

pair<double, int> cmp(const pair<double, int> &a, const pair<double, int> &b) {
    if (fabs(a.first - b.first) < 1e-9) return a.second < b.second ? a : b;
    return a.first > b.first ? a : b;
}

pair<double, int> dp[maxn][maxn];

pair<double, int> check(int n, double c, int a) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= a; ++j) {
            dp[i][j] = make_pair(0.0, 0);
            dp[i][j] = cmp(dp[i][j], dp[i - 1][j] + make_pair(u[i] - c, 1));
            dp[i][j] = cmp(dp[i][j], dp[i - 1][j]);
            if (j > 0) dp[i][j] = cmp(dp[i][j], dp[i - 1][j - 1] + make_pair(p[i], 0));
            if (j > 0) dp[i][j] = cmp(dp[i][j], dp[i - 1][j - 1] + make_pair(p[i] + u[i] - p[i] * u[i] - c, 1));
        }
    }
    return dp[n][a];
}

int main() {
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) scanf("%lf", &p[i]);
    for (int i = 1; i <= n; ++i) scanf("%lf", &u[i]);
    double l = 0.0, r = 2.0;
    for (int it = 0; it < 30; ++it) {
        double m = 0.5 * (l + r);
        pair<double, int> res = check(n, m, a);
        if (res.second == b) {
            printf("%.20lf\n", res.first + m * b);
            return 0;
        }
        if (res.second < b) r = m;
        else l = m;
    }
    pair<double, int> res = check(n, l, a);
    printf("%.20lf\n", res.first + l * b);
    return 0;
}