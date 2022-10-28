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

        int ans = 0;
        for (int i = 1; i <= n; i = 10 * i + 1) {
            for (int j = 1; j <= 9; ++j) {
                ans += i * j <= n;
            }
        }

        cout << ans << "\n";
    }
}