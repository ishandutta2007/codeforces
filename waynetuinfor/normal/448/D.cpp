#include <bits/stdc++.h>
using namespace std;

int n, m;
long long k;

bool check(long long t) {
    long long smeq = 0;
    for (int i = 1; i <= n; ++i) {
        long long add = t / i;
        if (t % i == 0) --add;
        smeq += min(1ll * m, add);
    }
    return smeq <= k - 1;
}

int main() {
    cin >> n >> m >> k;
    long long d = 1, ans = 0;
    while (d <= n * 1ll * m) d <<= 1;
    while (d >>= 1) if (check(ans + d)) ans += d;
    cout << ans << endl;
    return 0;
}