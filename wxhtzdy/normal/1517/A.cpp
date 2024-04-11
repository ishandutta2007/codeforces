#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        if (n % 2050 != 0) {
            cout << "-1\n";
            continue;
        }
        long long x = n / 2050, sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        cout << sum << "\n";
    }
    return 0;
}