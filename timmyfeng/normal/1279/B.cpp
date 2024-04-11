#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        int ans = 0, mx = 0;
        long long time = 0;
        for (int i = 1; i <= n; ++i) {
            time += a[i];
            if (a[i] > a[mx]) {
                mx = i;
            }
            if (time <= s) {
                ans = 0;
            } else if (time - a[mx] <= s && mx != i) {
                ans = mx;
            }
        }
        cout << ans << '\n';
    }
}