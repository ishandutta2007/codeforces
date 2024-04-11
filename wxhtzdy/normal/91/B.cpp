#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> suf(n);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = (i == n - 1 ? a[i] : min(a[i], suf[i + 1]));
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << -1 << ' ';
            break;
        }
        int low = i - 1, high = n - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (suf[mid] < a[i]) {
                ans = max(ans, mid - i - 1);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << ' ';
    }
    return 0;
}