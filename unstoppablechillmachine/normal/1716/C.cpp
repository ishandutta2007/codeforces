#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (a[i][j]) {
                    a[i][j]++;
                }
            }
        }
        vector<vector<int>> kek(2, vector<int>(n));
        kek[0][0] = 0;
        kek[1][0] = max(1ll, a[1][0]);
        for (int j = 1; j < n; j++) {
            if (j & 1) {
                kek[1][j] = max(kek[1][j - 1] + 1, a[1][j]);
                kek[0][j] = max(kek[1][j] + 1, a[0][j]);
            } else {
                kek[0][j] = max(kek[0][j - 1] + 1, a[0][j]);
                kek[1][j] = max(kek[0][j] + 1, a[1][j]);
            }
        }

        vector<vector<int>> r(2, vector<int>(n)), l(2, vector<int>(n));
        r[0].back() = a[0].back();
        r[1].back() = a[1].back();
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < 2; i++) {
                r[i][j] = max(r[i][j + 1], a[i][j] + n - j - 1);
            }
        }
        l[0].back() = a[0].back();
        l[1].back() = a[1].back();
        for (int j = n - 2; j >= 0; j--) {
            for (int i = 0; i < 2; i++) {
                l[i][j] = max(l[i][j + 1] + 1, a[i][j]);
            }
        }

        int answer = max(kek[0].back(), kek[1].back());

        for (int i = 0; i < n - 1; i++) {
            if (kek[0][i] < kek[1][i]) {
                int cur = kek[0][i];
                cur = max(kek[0][i] + n - i - 1, r[0][i]);
                cur = max(cur + 1, a[1].back());
                cur = max(l[1][i], cur + n - i - 1);
                answer = min(answer, cur);
            } else {
                int cur = kek[1][i];
                cur = max(kek[1][i] + n - i - 1, r[1][i]);
                cur = max(cur + 1, a[0].back());
                cur = max(l[0][i], cur + n - i - 1);
                answer = min(answer, cur);
            }
        }

        cout << answer << '\n';
    }
    return 0;
}