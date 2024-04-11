#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    queue<tuple<int,int,int>> q;
    vector<vector<int>> paint(n, vector<int>(m)), vis(n, vector<int>(m));
    for(int i = 0; i + 1 < n; ++i) {
        for(int j = 0; j + 1 < m; ++j) {
            if(a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 1][j + 1]) {
                paint[i][j] = paint[i][j + 1] = paint[i + 1][j] = paint[i + 1][j + 1] = 1;
                q.push({i, j, a[i][j]});
                vis[i][j] = 1;
            }
        }
    }
    vector<int> dx {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<tuple<int,int,int>> ans;
    while(!q.empty()) {
        auto [x, y, v] = q.front(); q.pop();
        ans.push_back({x, y, v});
        for(int i = 0; i < 8; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx + 1 == n || yy + 1 == m || vis[xx][yy]) {
                continue;
            }
            int p = -1;
            if(!paint[xx][yy]) p = a[xx][yy];
            else if(!paint[xx + 1][yy]) p = a[xx + 1][yy];
            else if(!paint[xx][yy + 1]) p = a[xx][yy + 1];
            else if(!paint[xx + 1][yy + 1]) p = a[xx + 1][yy + 1];
            if(p != -1) {
                int ok = 1;
                if(!paint[xx][yy] && p != a[xx][yy]) ok = 0;
                else if(!paint[xx + 1][yy] && p != a[xx + 1][yy]) ok = 0;
                else if(!paint[xx][yy + 1] && p != a[xx][yy + 1]) ok = 0;
                else if(!paint[xx + 1][yy + 1] && p != a[xx + 1][yy + 1]) ok = 0;
                if(ok) {
                    paint[xx][yy] = paint[xx + 1][yy] = paint[xx][yy + 1] = paint[xx + 1][yy + 1] = 1;
                    q.push({xx, yy, p});
                    vis[xx][yy] = 1;
                }
            }
        }
    }
    int ok = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!paint[i][j]) {
                ok = 0;
            }
        }
    }
    if(ok) {
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto [x, y, v] : ans) {
            cout << x + 1 << " " << y + 1 << " " << v << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}