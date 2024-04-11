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
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                a[i][j] = s[j] - '0';
            }
        }
        vector<vector<pair<int, int>>> ans;
        for (int i = 0; i < h - 1; i++) {
            for (int j = 0; j < w - 1; j++) {
                if (a[i][j]) {
                    if (a[i][j + 1]) {
                        vector<pair<int, int>> p;
                        p.emplace_back(i, j);
                        p.emplace_back(i, j + 1);
                        p.emplace_back(i + 1, j);
                        a[i][j] ^= 1;
                        a[i][j + 1] ^= 1;
                        a[i + 1][j] ^= 1;
                        ans.emplace_back(p);
                    } else {
                        vector<pair<int, int>> p;
                        p.emplace_back(i, j);
                        p.emplace_back(i + 1, j);
                        p.emplace_back(i + 1, j + 1);
                        a[i][j] ^= 1;
                        a[i + 1][j] ^= 1;
                        a[i + 1][j + 1] ^= 1;
                        ans.emplace_back(p);
                    }
                }
            }
            if (a[i][w - 1]) {
                vector<pair<int, int>> p;
                p.emplace_back(i, w - 1);
                p.emplace_back(i + 1, w - 1);
                p.emplace_back(i + 1, w - 2);
                a[i][w - 1] ^= 1;
                a[i + 1][w - 1] ^= 1;
                a[i + 1][w - 2] ^= 1;
                ans.emplace_back(p);
            }
        }
        for (int j = 0; j < w - 1; j++) {
            if (a[h - 1][j] && a[h - 2][j]) {
                vector<pair<int, int>> p;
                p.emplace_back(h - 1, j);
                p.emplace_back(h - 2, j);
                p.emplace_back(h - 1, j + 1);
                a[h - 1][j] ^= 1;
                a[h - 2][j] ^= 1;
                a[h - 1][j + 1] ^= 1;
                ans.emplace_back(p);
            } else if (a[h - 1][j]) {
                vector<pair<int, int>> p;
                p.emplace_back(h - 1, j);
                p.emplace_back(h - 1, j + 1);
                p.emplace_back(h - 2, j + 1);
                a[h - 1][j] ^= 1;
                a[h - 1][j + 1] ^= 1;
                a[h - 2][j + 1] ^= 1;
                ans.emplace_back(p);
            } else if (a[h - 2][j]) {
                vector<pair<int, int>> p;
                p.emplace_back(h - 2, j);
                p.emplace_back(h - 2, j + 1);
                p.emplace_back(h - 1, j + 1);
                a[h - 2][j] ^= 1;
                a[h - 2][j + 1] ^= 1;
                a[h - 1][j + 1] ^= 1;
                ans.emplace_back(p);
            }
        }
        if (a[h - 1][w - 1] && a[h - 2][w - 1]) {
            vector<pair<int, int>> p;
            p.emplace_back(h - 1, w - 2);
            p.emplace_back(h - 2, w - 1);
            p.emplace_back(h - 2, w - 2);
            ans.emplace_back(p);
            p.clear();
            p.emplace_back(h - 2, w - 2);
            p.emplace_back(h - 1, w - 2);
            p.emplace_back(h - 1, w - 1);
            ans.emplace_back(p);
        } else if (a[h - 2][w - 1]) {
            vector<pair<int, int>> p;
            p.emplace_back(h - 2, w - 1);
            p.emplace_back(h - 1, w - 1);
            p.emplace_back(h - 1, w - 2);
            ans.emplace_back(p);
            p.clear();
            p.emplace_back(h - 2, w - 2);
            p.emplace_back(h - 2, w - 1);
            p.emplace_back(h - 1, w - 1);
            ans.emplace_back(p);
            p.clear();
            p.emplace_back(h - 1, w - 2);
            p.emplace_back(h - 2, w - 1);
            p.emplace_back(h - 2, w - 2);
            ans.emplace_back(p);
        } else if (a[h - 1][w - 1]) {
            vector<pair<int, int>> p;
            p.emplace_back(h - 2, w - 2);
            p.emplace_back(h - 1, w - 1);
            p.emplace_back(h - 1, w - 2);
            ans.emplace_back(p);
            p.clear();
            p.emplace_back(h - 2, w - 2);
            p.emplace_back(h - 2, w - 1);
            p.emplace_back(h - 1, w - 1);
            ans.emplace_back(p);
            p.clear();
            p.emplace_back(h - 1, w - 2);
            p.emplace_back(h - 2, w - 1);
            p.emplace_back(h - 1, w - 1);
            ans.emplace_back(p);
        }
        debug(a);
        // assert((int)ans.size() <= n * m);
        cout << ans.size() << '\n';
        for (auto v : ans) {
            for (auto p : v) {
                cout << p.first + 1 << " " << p.second + 1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}