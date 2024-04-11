#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int lb = max(0, n - 1000);
        long long ans = -inf;
        for (int i = lb; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, 1LL * (i + 1) * (j + 1) - 1LL * k * (a[i] | a[j]));
            }
        }
        cout << ans << '\n';
    }
    exit(0);
}