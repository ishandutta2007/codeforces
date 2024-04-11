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
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int ans = 0, k = 0;
        for (int i = 0; i <= 101; i++) {
            if (cnt[i] == 0) {
                if (k == 1) {
                    ans += i;
                    k++;
                } else {
                    if (k == 0) {
                        ans = i * 2;
                        k = 2;
                    }
                }
            } else {
                if (cnt[i] == 1 && k == 0) {
                    k++;
                    ans += i;
                }
            }
            if (k == 2) {
                break;
            }
        }
        for (int i = 0; i <= 101; i++) {
            if (cnt[i] == 0) {
                ans = max(ans, i);
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}