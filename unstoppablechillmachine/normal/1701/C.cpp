#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

bool cmp(int a, int b) {
    int a2 = a, b2 = b;
    while (a2 % 2 == 0) {
        a2 /= 2;
    }
    while (b2 % 2 == 0) {
        b2 /= 2;
    }
    return a2 < b2 || (a2 == b2 && a < b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(n);
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            x--;
            cnt[x]++;
        }
        int l = -1, r = 2 * m;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int rem = 0, can = 0;
            for (int i = 0; i < n; i++) {
                if (cnt[i] <= mid) {
                    can += (mid - cnt[i]) / 2;
                } else {
                    rem += cnt[i] - mid;
                }
            }
            if (can >= rem) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << '\n';
    }
    return 0;
}