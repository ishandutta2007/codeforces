#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        int ans = 0;
        if (x % 2050 == 0) {
            x /= 2050;
            while (x > 0) {
                ans += x % 10;
                x /= 10;
            }
        } else {
            ans = -1;
        }

        cout << ans << "\n";
    }
}