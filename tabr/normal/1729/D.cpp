#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] -= x;
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] += x;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int l = 0;
        int r = n - 1;
        while (l < r) {
            if (a[l] + a[r] < 0) {
                l++;
            } else {
                r--;
                l++;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}