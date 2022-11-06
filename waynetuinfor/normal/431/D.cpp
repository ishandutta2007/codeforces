#include <bits/stdc++.h>
using namespace std;

int k;
long long m, c[70][70];

void init() {
    for (int i = 0; i < 70; ++i) c[i][0] = 1;
    for (int i = 1; i < 70; ++i) c[0][i] = 0;
    for (int i = 1; i < 70; ++i) {
        for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}

long long cnt(long long n) {
    long long ret = 0;
    int cur = 0;
    for (int i = 63; i >= 0; --i) if ((1ll << i) & n) {
        ret += c[i][k - cur];
        ++cur;
    }
    int cc = 0;
    for (int i = 63; i >= 0; --i) if ((1ll << i) & n) ++cc;
    if (cc == k) ++ret;
    return ret;
}

bool check(long long n) {
    // cout << "n = " << n << endl;
    // cout << "cnt = " << cnt(2 * n) - cnt(n) << endl;
    return cnt(2 * n) - cnt(n) >= m;
}

int main() {
    init();
    cin >> m >> k;
    long long d = 1ll, ans = 1e18;
    while (d <= 1e18) d <<= 1ll;
    while (d >>= 1) if (ans - d >= 1) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}