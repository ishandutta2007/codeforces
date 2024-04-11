#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
double mem[maxn][maxn], p;
bool v[maxn][maxn];

double dp(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, t; cin >> n >> p >> t;
    double ans = 0.0;
    for (int i = 1; i <= n; ++i) ans += dp(i, t);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

double dp(int n, int t) {
    if (n == 0) return 1.0;
    if (t < n) return 0.0;
    if (v[n][t]) return mem[n][t];
    v[n][t] = true;
    return mem[n][t] = p * dp(n - 1, t - 1) + (1 - p) * dp(n, t - 1);
}