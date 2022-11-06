#include <bits/stdc++.h>
using namespace std;

bool check(long long c, long long n) {
    long long v = 0, p = 0;
    while (n) {
        v += min(n, c);
        n -= min(n, c);
        p += n / 10;
        n -= n / 10;
    }
    return v >= p;
}

int main() {
    long long n; cin >> n;
    long long ans = 1e18;
    int d = 62;
    while (d--) if (ans - (1ll << d) > 0) if (check(ans - (1ll << d), n)) ans -= (1ll << d);
    cout << ans << endl;
    return 0;
}