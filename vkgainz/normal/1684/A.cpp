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
        int n; cin >> n;
        if (n <= 99) {
            cout << (n % 10) << "\n";
        } else {
            int ans = 10;
            while (n > 0) {
                ans = min(ans, n % 10);
                n /= 10;
            }
            cout << ans << "\n";
        }
    }
}