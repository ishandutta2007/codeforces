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
        vector<string> s(n + 2, string(n + 2, '.'));
        int k = n * n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] = "." + s[i] + ".";
            for (int j = 1; j <= n; j++) {
                if (s[i][j] == '.') {
                    k--;
                }
            }
        }
        k /= 3;
        vector<string> ans = s;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i][j] == 'X') {
                    vector<int> c(3);
                    vector<vector<int>> px(3), py(3);
                    function<void(int, int)> dfs = [&](int x, int y) {
                        int p = (600 + x - y) % 3;
                        c[p]++;
                        s[x][y] = '.';
                        px[p].emplace_back(x);
                        py[p].emplace_back(y);
                        if (s[x + 1][y] == 'X') {
                            dfs(x + 1, y);
                        }
                        if (s[x - 1][y] == 'X') {
                            dfs(x - 1, y);
                        }
                        if (s[x][y + 1] == 'X') {
                            dfs(x, y + 1);
                        }
                        if (s[x][y - 1] == 'X') {
                            dfs(x, y - 1);
                        }
                    };
                    dfs(i, j);
                    int b = *min_element(c.begin(), c.end());
                    for (int p = 0; p < 3; p++) {
                        if (c[p] == b) {
                            for (int l = 0; l < b; l++) {
                                ans[px[p][l]][py[p][l]] = 'O';
                            }
                            k -= b;
                            break;
                        }
                    }
                }
            }
        }
        debug(k);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}