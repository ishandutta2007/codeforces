#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int odd = 0, even = 0, parity = 0, power = 1;
        while (n > 0) {
            (parity == 0 ? odd : even) += n % 10 * power;
            n /= 10;
            
            parity ^= 1;
            if (parity == 0) {
                power *= 10;
            }
        }

        if (odd == 0) {
            cout << even - 1 << "\n";
        } else if (even == 0) {
            cout << odd - 1 << "\n";
        } else {
            cout << (long long) (odd + 1) * (even + 1) - 2 << "\n";
        }
    }
}