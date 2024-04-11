#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> s(3);
        for (int i = 0; i < 3; i++) {
            cin >> s[i];
        }
        string ans;
        vector<int> cnt(3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cnt[i] += s[i][j] - '0';
            }
        }
        vector<int> order(3);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) { return cnt[i] > cnt[j]; });
        char c = '0';
        char d = '1';
        string x;
        string y = s[order[1]];
        if (cnt[order[1]] >= n) {
            x = s[order[0]];
        } else {
            x = s[order[2]];
            swap(c, d);
        }
        vector<int> a;
        for (int i = 0, j = -1; i <= 2 * n; i++) {
            if (i == 2 * n || x[i] == d) {
                a.emplace_back(i - j - 1);
                j = i;
            }
        }
        vector<int> b;
        for (int i = 0, j = -1; i <= 2 * n; i++) {
            if (i == 2 * n || y[i] == d) {
                b.emplace_back(i - j - 1);
                j = i;
            }
        }
        debug(a, b);
        for (int i = 0; i < (int)b.size(); i++) {
            a[i] = max(a[i], b[i]);
        }
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = 0; j < a[i]; j++) {
                ans += c;
            }
            if (i != (int)a.size() - 1) {
                ans += d;
            }
        }
        for (int i = (int)ans.size(); i < 3 * n; i++) {
            ans += '0';
        }
        cout << ans << '\n';
    }
    return 0;
}