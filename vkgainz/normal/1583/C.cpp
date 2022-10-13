#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <map>

using namespace std;


int main() {
    int n, m; cin >> n >> m;
    string grid[n];
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    int q; cin >> q;
    vector<pair<int, int>> queries[m];
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        --l, --r;
        queries[r].push_back({l, i});
    }
    int lst = -1;
    vector<string> ans(q);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i && grid[j][i] == 'X' && grid[j + 1][i - 1] == 'X') {
                lst = i;
            }
        }
        for (pair<int, int> x : queries[i]) {
            if (lst > x.first)
                ans[x.second] = "NO";
            else
                ans[x.second] = "YES";
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}