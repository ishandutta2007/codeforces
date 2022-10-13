#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> a(n * m);
        vector<pair<int, int>> pos(n * m);
        for (int i = 0; i < n * m; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        a.push_back({0, 0});
        int lst = a[0].first;
        vector<int> in;
        int curr_row = 0, curr_col = 0;
        for (int i = 0; i <= n * m; i++) {
            if (a[i].first != lst) {
                reverse(in.begin(), in.end());
                while (in.size() >= m - curr_col) {
                    for (int i = 0; i < m - curr_col; i++) {
                        pos[in.back()] = {curr_row, m - i - 1};
                        in.pop_back();
                    }
                    curr_row++;
                    curr_col = 0;
                }
                int tmp = in.size();
                curr_col += in.size();
                while (in.size()) {
                    --curr_col;
                    pos[in.back()] = {curr_row, curr_col};
                    in.pop_back();
                }
                curr_col += tmp;
                if (curr_col == m) {
                    ++curr_row, curr_col = 0;
                }
                in.clear();  
            }
            in.push_back(a[i].second);
            lst = a[i].first;
        }
        int ans = 0;
        vector<vector<int>> fill(n, vector<int>(m));
        for (int i = 0; i < n * m; i++) {
            //cout << pos[i].first << " " << pos[i].second << "\n";
            for (int j = 0; j < pos[i].second; j++) {
                ans += fill[pos[i].first][j];
            }
            fill[pos[i].first][pos[i].second]++;
        }
        cout << ans << "\n";
    }
}