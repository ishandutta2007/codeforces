#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int64_t ans = 0;
    for (int64_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans = __gcd(ans, i);
        }
    }
    if (n > 1) ans = __gcd(ans, n);
    cout << ans << endl;
    return 0;
}