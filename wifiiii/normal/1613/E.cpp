#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        vector<int> dx {-1, 1, 0, 0};
        vector<int> dy {0, 0, -1, 1};
        int sx, sy;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
                if(a[i][j] == 'L') {
                    sx = i, sy = j;
                }
            }
        }
        auto check = [&](int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < m;
        };
        vector<vector<int>> deg(n, vector<int>(m)), vis(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                for(int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if(check(x, y) && a[x][y] != '#') {
                        deg[i][j] += 1;
                    }
                }
            }
        }
        queue<pair<int,int>> q;
        vis[sx][sy] = 1, q.push({sx, sy});
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if(a[x][y] != 'L') a[x][y] = '+';
            for(int k = 0; k < 4; ++k) {
                int xx = x + dx[k], yy = y + dy[k];
                if(check(xx, yy) && a[xx][yy] != '#') {
                    --deg[xx][yy];
                    if(deg[xx][yy] <= 1 && !vis[xx][yy]) {
                        vis[xx][yy] = 1;
                        q.push({xx, yy});
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
}