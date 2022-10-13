#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (2 * k > n + 1) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && i < 2 * k && i % 2 == 0)
                    cout << 'R';
                else
                    cout << '.';
            }
            cout << "\n";
        }
    }
}