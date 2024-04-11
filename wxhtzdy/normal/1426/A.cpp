#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        if (n <= 2) {
            cout << 1 << '\n';
            continue;
        }
        int ans = (n - 2 + x - 1) / x + 1;
        cout << ans << '\n';
    }
    return 0;
}