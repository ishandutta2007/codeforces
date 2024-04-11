#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        long long ans = 0;
        while (l < r) {
            ans += r - l;
            r /= 10, l /= 10;
        }

        cout << ans << "\n";
    }
}