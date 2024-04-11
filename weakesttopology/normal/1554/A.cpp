#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            ans = max(ans, 1LL * a[i] * a[i + 1]);
        }
        cout << ans << '\n';
    }
    exit(0);
}