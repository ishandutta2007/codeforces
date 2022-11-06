#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r, x, y; cin >> l >> r >> x >> y;
    if (y % x != 0) {
        cout << "0" << endl;
        return 0;
    }
    y /= x;
    long long ans = 0;
    for (int i = 1; i * i <= y; ++i) if (y % i == 0) {
        long long a = x * 1ll * i, b = x * 1ll * (y / i);
        if (__gcd(a, b) == x) {
            if (l <= a && a <= r && l <= b && b <= r) ++ans;
            if (l <= a && a <= r && l <= b && b <= r && a != b) ++ans;
        }
    }
    cout << ans << endl;
}