#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000][1000];
int dis[40][1000][1000];
bool vis[40][1000][1000];
queue<pair<int,int>> q;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }
    int dir1[4] = {-1, 1, 0, 0};
    int dir2[4] = {0, 0, 1, -1};
    for(int c = 0; c < k; ++c) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == c) {
                    q.push({i, j});
                    vis[c][i][j] = 1;
                }
            }
        }
        vector<int> vis_color(k);
        vis_color[c] = 1;
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            for(int r = 0; r < 4; ++r) {
                int x = p.first + dir1[r], y = p.second + dir2[r];
                if(x < 0 || y < 0 || x >= n || y >= m || vis[c][x][y]) continue;
                vis[c][x][y] = 1;
                dis[c][x][y] = dis[c][p.first][p.second] + 1;
                q.push({x, y});
            }
            if(!vis_color[a[p.first][p.second]]) {
                vis_color[a[p.first][p.second]] = 1;
                int color = a[p.first][p.second];
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        if(a[i][j] == color && !vis[c][i][j]) {
                            vis[c][i][j] = 1;
                            dis[c][i][j] = dis[c][p.first][p.second] + 1;
                            q.push({i, j});
                        }
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    vector<vector<int>> checked(n, vector<int>(m));
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        if(x1 == x2 && y1 == y2) {
            cout << 0 << '\n';
            continue;
        }
        int d = abs(x1 - x2) + abs(y1 - y2);
        for(int i = 0; i < k; ++i) {
            d = min(d, dis[i][x1][y1] + dis[i][x2][y2] + 1);
        }
        cout << d << '\n';
    }
}