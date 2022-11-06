#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
const double pi = acos(-1), inf = 1e9, eps = 1e-9;
double dp[1 << maxn];
bool v[1 << maxn];
double x[maxn], y[maxn], a[maxn], l, r;
int n;

double dfs(int s) {
    if (s == 0) return l;
    if (v[s]) return dp[s];
    dp[s] = -inf;
    for (int i = 0; i < n; ++i) if ((1 << i) & s) {
        double pos = dfs(s ^ (1 << i));
        // cout << "pos = " << pos << endl;
        double b = atan2(fabs(y[i]), (x[i] - pos));
        // cout << "b = " << b << endl;
        double ang = min(a[i], pi - b);
        ang -= eps;
        double c = pi - ang - b;
        // cout << "c = " << c << endl;
        double l = sqrt(y[i] * y[i] + (x[i] - pos) * (x[i] - pos));
        // cout << "l = " << l << endl;
        double d = l * sin(ang) / sin(c);
        // cout << "d = " << d << endl;
        dp[s] = max(dp[s], pos + d);
    }
    v[s] = true;
    // cout << "dp[" << s << "] = " << dp[s] << endl;
    return dp[s];
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> a[i], a[i] /= 180, a[i] *= pi, a[i] -= eps;
    double ans = 0.0;
    cout << fixed << setprecision(20) << min(r - l, dfs((1 << n) - 1) - l) << endl;
    return 0;
}