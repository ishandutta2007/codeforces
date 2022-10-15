#include <bits/stdc++.h>
using namespace std;
constexpr int K = 31;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        if (n <= m) {
            int pref = 0;
            for (int k = K - 1; k >= 0; --k) {
                int b = n >> k & 1;
                if ((ans ^ pref) + (1 << k) - 1 <= m) {
                    ans ^= (b ^ 1) << k;
                }
                pref ^= b << k;
            }
        }
        cout << ans << '\n';
    }
    exit(0);
}