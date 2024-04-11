#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = -1;
        }
        for (int i = 1; i <= y - x; i++) {
            if ((y - x) % i != 0) {
                continue;
            }
            int k = n;
            vector<int> v;
            for (int j = x; j <= y && n > 0; j += i, n--) {
                v.push_back(j);
            }
            for (int j = x - i; j > 0 && n > 0; j -= i, n--) {
                v.push_back(j);
            }
            for (int j = y + i; n > 0; j += i, n--) {
                v.push_back(j);
            }
            n = k;
            if (v.size() < n) continue;
            sort(v.begin(), v.end());
            bool okx = 0, oky = 0;
            for (int c : v) {
                if (c == x) okx = 1;
                if (c == y) oky = 1;
            }
            if (!okx || !oky) continue;
            if (ans[0] == -1 || ans[n - 1] > v[n - 1]) {
                for (int j = 0; j < n; j++) {
                    ans[j] = v[j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}