#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& i : grid) {
        cin >> i;
    }

    vector<vector<int>> ps(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ps[i][j] = (grid[i][j] == 'X');
            if (i) {
                ps[i][j] += ps[i - 1][j];
            }
            if (j) {
                ps[i][j] += ps[i][j - 1];
            }
            if (i && j) {
                ps[i][j] -= ps[i - 1][j - 1];
            }
        }
    }

    int lo = 0, hi = min(m - 1, n - 1) / 2;
    vector<string> fire(n, string(m, '.')), ans;
    vector<vector<int>> res(n + 1, vector<int>(m + 1));
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int len = mi * 2 + 1;
        for (auto& i : res) {
            fill(i.begin(), i.end(), 0);
        }
        for (auto& i : fire) {
            i = string(m, '.');
        }

        for (int i = 0; i + len - 1 < n; ++i) {
            for (int j = 0; j + len - 1 < m; ++j) {
                int ct = ps[i + len - 1][j + len - 1];
                if (i) {
                    ct -= ps[i - 1][j + len - 1];
                }
                if (j) {
                    ct -= ps[i + len - 1][j - 1];
                }
                if (i && j) {
                    ct += ps[i - 1][j - 1];
                }

                if (ct == len * len) {
                    fire[i + mi][j + mi] = 'X';
                    ++res[i][j];
                    ++res[i + len][j + len];
                    --res[i + len][j];
                    --res[i][j + len];
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n && ok; ++i) {
            for (int j = 0; j < m && ok; ++j) {
                if (i) {
                    res[i][j] += res[i - 1][j];
                }
                if (j) {
                    res[i][j] += res[i][j - 1];
                }
                if (i && j) {
                    res[i][j] -= res[i - 1][j - 1];
                }

                if (grid[i][j] == 'X' && !res[i][j]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            lo = mi + 1;
            ans = fire;
        } else {
            hi = mi - 1;
        }
    }
    cout << hi << '\n';
    for (auto& i : ans) {
        cout << i << '\n';
    }
}