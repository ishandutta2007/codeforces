#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const double inf = 1e15;
double dp[2][maxn];
double t[maxn], s[maxn], tinv[maxn], st[maxn];
double a[maxn], b[maxn];

double calc(int i, double x) {
    return a[i] * x + b[i];
}

double cross(int i, int j) {
    return (b[i] - b[j]) / (a[j] - a[i]);
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &t[i]);
        s[i] = s[i - 1] + t[i];
        tinv[i] = tinv[i - 1] + 1. / t[i];
        st[i] = st[i - 1] + s[i] / t[i];
    }
    for (int i = 0; i < maxn; ++i) dp[0][i] = inf;
    dp[0][0] = 0;
    int z = 0;
    for (int p = 1; p <= k; ++p) {
        z ^= 1;
        a[0] = dp[z ^ 1][0];
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i <= n; ++i) {
            double x = tinv[i];
            while (dq.size() >= 2 && calc(dq[1], x) <= calc(dq[0], x)) dq.pop_front();
            dp[z][i] = calc(dq[0], x) + st[i];
            a[i] = -s[i], b[i] = dp[z ^ 1][i] + s[i] * tinv[i] - st[i];
            while (dq.size() >= 2 && cross(i, dq[dq.size() - 2]) <= cross(dq[dq.size() - 1], dq[dq.size() - 2])) dq.pop_back();
            dq.push_back(i);
        }
    }
    printf("%.20lf\n", dp[z][n]);
}