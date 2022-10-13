#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'W') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }
    vector<vector<int>> mark(n, vector<int>(m));
    int ans = 0;
    bool redOne = false;
    bool markEnd = false;
    set<pair<int, int>> use;
    vector<int> h, u;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            mark[i][j] = 0;
            if (i < n - 1) mark[i][j] ^= mark[i + 1][j];
            if (j < m - 1) mark[i][j] ^= mark[i][j + 1];
            if (i < n - 1 and j < m - 1) mark[i][j] ^= mark[i + 1][j + 1];
            if (mark[i][j]) g[i][j] = 1 - g[i][j];
            if (g[i][j]) {
                mark[i][j] ^= 1, ++ans;
                if (i == n - 1 and j == m - 1) {
                    markEnd = true;
                } else if (i == n - 1) {
                    u.push_back(j);
                } else if (j == m - 1) {
                    h.push_back(i);
                }
                use.insert({i, j});
            }
        }
    }
    for (int x : h) 
        for (int y : u)
            if (use.count({x, y}))
                redOne = true;
    redOne &= markEnd;
    cout << ans - redOne << "\n";
}