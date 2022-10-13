#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <math.h>
#include <array>
#include <numeric>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string grid[n];
        vector<vector<bool>> vis(n, vector<bool>(m));
        pair<int, int> st;
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L') {
                    st = {i, j};
                } else if (grid[i][j] == '#') {
                    vis[i][j] = true;
                }
            }
        }
        queue<pair<int, int>> q;
        q.push(st);
        vis[st.first][st.second] = true;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int a = 0; a < 4; a++) {
                int nx = curr.first + dx[a];
                int ny = curr.second + dy[a];
                if (nx >= 0 && nx < n
                        && ny >= 0 && ny < m) {
                    if (vis[nx][ny]) continue;
                    int num = 0, tot = 0;
                    for (int j = 0; j < 4; j++) {
                        int tx = nx + dx[j];
                        int ty = ny + dy[j];
                        if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                            ++tot;
                            if (vis[tx][ty]) {
                                ++num;
                            }
                        }
                    }
                    if (num >= tot - 1) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L' || grid[i][j] == '#') {
                    cout << grid[i][j];
                } else if (vis[i][j]) {
                    cout << '+';
                } else {
                    cout << grid[i][j];
                }
            }
            cout << "\n";
        }
    }
}