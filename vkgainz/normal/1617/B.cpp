#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <numeric>

using namespace std;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void solve(int n) {
    if (n % 2 == 0) {
        cout << (n - 1) / 2 << " " << n / 2 << " " << 1 << "\n";
    } else {
        for (int i = 3; i <= n; i += 2) {
            if (gcd(i, n - 1 - i) == 1) {
                cout << i << " " << n - 1 - i << " " << 1 << "\n";
                break;
            }
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        solve(n);
    }
}