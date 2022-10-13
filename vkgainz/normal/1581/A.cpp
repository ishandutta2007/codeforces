#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long MOD = 1e9 + 7, ans = 1LL;
        int n; cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            if (i == 2) continue;
            ans *= i;
            ans %= MOD;
        }
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
}