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
        vector<int> a(n);
        vector<int> cnt(31, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int bit = 0;
            while (a[i] > 0) {
                bit++;
                a[i] /= 2;
            }
            cnt[bit]++;
        }
        long long ans = 0;
        for (int i = 0; i < 31; i++) {
            ans += (long long) cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}