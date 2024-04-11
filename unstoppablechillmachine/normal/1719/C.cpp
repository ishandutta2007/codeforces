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
        int n, q;
        cin >> n >> q;
        vector<vector<int>> wins(n);
        vector<int> a(n), pos(n);
        for (int i = 0; i < n; i++) {
            cin >> a[n - i - 1];
            a[n - i - 1]--;
            pos[a[n - i - 1]] = i;
        }
        vector<int> a_orig = a;
        reverse(a_orig.begin(), a_orig.end());
        int pref_len = 0;
        while (a.back() != n - 1) {
            pref_len++;
            int x = a.back();
            a.pop_back();
            int y = a.back();
            a.pop_back();
            if (x > y) {
                wins[x].push_back(pref_len);
                a.push_back(x);
            } else {
                wins[y].push_back(pref_len);
                a.push_back(y);
            }
        }
        for (int i = 0; i < q; i++) {
            int id, len;
            cin >> id >> len;
            int val = a_orig[id - 1];
            int result = upper_bound(wins[val].begin(), wins[val].end(), len) - wins[val].begin();
            if (val == n - 1 && len > pref_len) {
                result += len - pref_len;
            }
            cout << result << '\n';
        }
    }
    return 0;
}