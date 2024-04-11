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
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<pair<int, int>>> left(h, vector<pair<int, int>>(w));
        vector<vector<pair<int, int>>> right(h, vector<pair<int, int>>(w));
        for (int i = 0; i < h; i++) {
            left[i][0] = make_pair(a[i][0], a[i][0]);
            for (int j = 1; j < w; j++) {
                left[i][j] = left[i][j - 1];
                left[i][j].first = min(left[i][j].first, a[i][j]);
                left[i][j].second = max(left[i][j].second, a[i][j]);
            }
            right[i][w - 1] = make_pair(a[i][w - 1], a[i][w - 1]);
            for (int j = w - 2; j >= 0; j--) {
                right[i][j] = right[i][j + 1];
                right[i][j].first = min(right[i][j].first, a[i][j]);
                right[i][j].second = max(right[i][j].second, a[i][j]);
            }
        }
        for (int k = 1; k < w; k++) {
            vector<pair<int, int>> b(h), c(h);
            for (int i = 0; i < h; i++) {
                b[i] = left[i][k - 1];
                c[i] = right[i][k];
            }
            // b[red].first > b[blue].second
            // c[blue].first > c[red].second
            string ans(h, 'B');
            vector<int> lo(h);
            iota(lo.begin(), lo.end(), 0);
            vector<int> ro = lo;
            sort(lo.begin(), lo.end(), [&](int i, int j) {
                return b[i].second > b[j].second;
            });
            sort(ro.begin(), ro.end(), [&](int i, int j) {
                return c[i].first < c[j].first;
            });
            int lit = 0;
            int rit = 0;
            int left_min = (int) 1e9;
            int right_max = (int) -1e9;
            int left_max = -1;
            for (int i = 0; i < h; i++) {
                left_max = max(left_max, b[i].second);
            }
            for (int i = 0; i < h; i++) {
                if (b[i].second == left_max) {
                    ans[i] = 'R';
                    left_min = min(left_min, b[i].first);
                    right_max = max(right_max, c[i].second);
                }
            }
            while (lit < h && rit < h) {
                int ok = 1;
                while (lit < h && b[lo[lit]].second >= left_min) {
                    ok = 0;
                    ans[lo[lit]] = 'R';
                    left_min = min(left_min, b[lo[lit]].first);
                    right_max = max(right_max, c[lo[lit]].second);
                    lit++;
                }
                while (rit < h && c[ro[rit]].first <= right_max) {
                    ok = 0;
                    ans[ro[rit]] = 'R';
                    left_min = min(left_min, b[ro[rit]].first);
                    right_max = max(right_max, c[ro[rit]].second);
                    rit++;
                }
                if (ok) {
                    break;
                }
            }
            if (ans != string(h, 'R')) {
                cout << "YES" << '\n';
                cout << ans << " " << k << '\n';
                break;
            } else if (k == w - 1) {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}