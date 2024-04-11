#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int dir1[4] = {-1,0,0,1};
int dir2[4] = {0,-1,1,0};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    int ans = 0;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2)));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i) {
                dp[i][j][0] += dp[i-1][j][1];
            }
            if(j) {
                dp[i][j][1] += dp[i][j-1][0];
            }
            dp[i][j][0] += 1;
            dp[i][j][1] += 1;
            ans += dp[i][j][0] + dp[i][j][1] - 1;
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        {
            int f = 0;
            int xx = x + dir1[f], yy = y + dir2[f];
            while(xx >= 0 && yy >= 0 && xx < n && yy < m && a[xx][yy] == 0) {
                l1 += 1;
                f ^= 1;
                xx = xx + dir1[f], yy = yy + dir2[f];
            }
        }
        {
            int f = 1;
            int xx = x + dir1[f], yy = y + dir2[f];
            while(xx >= 0 && yy >= 0 && xx < n && yy < m && a[xx][yy] == 0) {
                l2 += 1;
                f ^= 1;
                xx = xx + dir1[f], yy = yy + dir2[f];
            }
        }
        {
            int f = 1;
            int xx = x - dir1[f], yy = y - dir2[f];
            while(xx >= 0 && yy >= 0 && xx < n && yy < m && a[xx][yy] == 0) {
                r1 += 1;
                f ^= 1;
                xx = xx - dir1[f], yy = yy - dir2[f];
            }
        }
        {
            int f = 0;
            int xx = x - dir1[f], yy = y - dir2[f];
            while(xx >= 0 && yy >= 0 && xx < n && yy < m && a[xx][yy] == 0) {
                r2 += 1;
                f ^= 1;
                xx = xx - dir1[f], yy = yy - dir2[f];
            }
        }
        int d = (l1 + 1) * (r1 + 1) + (l2 + 1) * (r2 + 1) - 1;
        if(a[x][y]) ans += d;
        else ans -= d;
        a[x][y] ^= 1;
        cout << ans << '\n';
    }
}