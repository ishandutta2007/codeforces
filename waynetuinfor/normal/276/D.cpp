#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l, r; cin >> l >> r;
    long long a = 0, b = 0, ans = 0;
    for (int i = 59; i >= 0; --i) {
        if (b + (1LL << i) - 1 >= l && a + (1LL << i) <= r) {
            ans += (1LL << i);
            a += (1LL << i);
        } else if (a + (1LL << i) > r) {
            if (b + (1LL << i) <= r) {
                ans += (1LL << i);
                b += (1LL << i);
            }
        } else if (b + (1LL << i) - 1 < l) {
            if (a + (1LL << i) - 1 >= l) {
                ans += (1LL << i);
                b += (1LL << i);
            } else {
                a += (1LL << i);
                b += (1LL << i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}