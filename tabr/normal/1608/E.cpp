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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(3);
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        c--;
        a[c].emplace_back(x, y);
    }
    int ans = 0;
    const int bound = 1;
    const vector<array<int, 3>> perms = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for (int rot = 0; rot < 4; rot++) {
        debug(rot);
        {
            vector<int> xs, ys;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < n / 3; j++) {
                    auto [x, y] = a[i][j];
                    a[i][j] = make_pair(y, -x);
                    xs.emplace_back(y);
                    ys.emplace_back(-x);
                }
            }
            sort(xs.begin(), xs.end());
            xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
            sort(ys.begin(), ys.end());
            ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < n / 3; j++) {
                    auto [x, y] = a[i][j];
                    x = (int) (lower_bound(xs.begin(), xs.end(), x) - xs.begin());
                    y = (int) (lower_bound(ys.begin(), ys.end(), y) - ys.begin());
                    a[i][j] = make_pair(x, y);
                }
            }
            for (int i = 0; i < 3; i++) {
                sort(a[i].begin(), a[i].end());
            }
        }
        if (rot < 2) {
            int lo = 0;
            int hi = n / 3 + 1;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                int ok = 0;
                for (const auto &p : perms) {
                    int beg = 0;
                    for (int i : p) {
                        int cnt = 0;
                        for (int j = 0; j < n / 3; j++) {
                            if (a[i][j].first < beg) {
                                continue;
                            } else {
                                cnt++;
                                if (cnt == mid) {
                                    beg = a[i][j].first + bound;
                                    break;
                                }
                            }
                        }
                        if (cnt < mid) {
                            break;
                        } else if (i == p[2]) {
                            ok = 1;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
                if (ok) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            ans = max(ans, lo);
        }
        {
            int lo = 0;
            int hi = n / 3 + 1;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                int ok = 0;
                for (const auto &p : perms) {
                    if (p[1] > p[2]) {
                        continue;
                    }
                    int beg = a[p[0]][mid - 1].first + bound;
                    vector<vector<int>> ys;
                    for (int i : p) {
                        if (i == p[0]) {
                            continue;
                        }
                        ys.emplace_back();
                        for (int j = 0; j < n / 3; j++) {
                            if (a[i][j].first >= beg) {
                                ys.back().emplace_back(a[i][j].second);
                            }
                        }
                        sort(ys.back().begin(), ys.back().end());
                    }
                    if ((int) min(ys[0].size(), ys[1].size()) < mid) {
                        continue;
                    }
                    if (ys[0][mid - 1] + bound <= ys[1][ys[1].size() - mid]) {
                        ok = 1;
                        break;
                    }
                    if (ys[1][mid - 1] + bound <= ys[0][ys[0].size() - mid]) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            ans = max(ans, lo);
        }
    }
    ans *= 3;
    cout << ans << '\n';
    return 0;
}