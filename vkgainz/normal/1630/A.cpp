#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k == n - 1) {
            if (n == 4) cout << - 1 << "\n";
            else {
                cout << 1 << " " << 3 << "\n";
                cout << n - 2 << " " << n - 1 << "\n";
                cout << 0 << " " << n - 4 << "\n";
                for (int i = 0; i < n / 2; i++) {
                    if (i == 2 || i >= 4) {
                        cout << i << " " << n - 1 - i << "\n";
                    }
                }
            }
            continue;
        }
        for (int i = 0; i < n / 2; i++) {
            if (i == 0) {
                cout << i << " " << n - 1 - k << "\n";
            } else if (i == k) {
                cout << i << " " << n - 1 << "\n";
            } else if (i != n - 1 - k) {
                cout << i << " " << n - 1 - i << "\n";
            }
        }
        if (k >= (n + 1) / 2) {
            cout << k << " " << n - 1 << "\n";
        }
    }
}