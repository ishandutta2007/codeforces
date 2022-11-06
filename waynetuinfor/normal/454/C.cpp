#include <bits/stdc++.h>
using namespace std;

long double fpow(long double a, int n) {
    long double ret = 1.0;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

const int maxn = 1e5 + 10;
long double dp[maxn], p[maxn];

int main() {
    int n, m; cin >> m >> n;
    long double expv = 0.0;
    for (int i = 1; i <= m; ++i) {
        expv += i * (fpow(i * 1.0 / m, n) - fpow(1.0 * (i - 1) / m, n));
    }
    cout << fixed << setprecision(20) << expv << endl;
    return 0;
}