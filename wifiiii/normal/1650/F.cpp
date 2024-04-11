#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[100005][101], pre[100005][101];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> b(n);
        for(int i = 0; i < n; ++i) cin >> b[i];
        vector<vector<tuple<int,int,int>>> a(n);
        for(int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            --x;
            a[x].push_back({y, z, i});
        }
        vector<int> ans;
        int ok = 1;
        for(int i = 0, cur = 0; i < n; ++i) {
            int q = a[i].size();
            for(int j = 0; j <= q; ++j) {
                for(int k = 0; k <= 100; ++k) {
                    dp[j][k] = 1e9 + 7;
                    pre[j][k] = -1;
                }
            }
            dp[0][0] = 0;
            for(int k = 0; k < q; ++k) {
                auto [x, y, id] = a[i][k];
                for(int j = 0; j <= 100; ++j) {
                    if(dp[k][j] <= 1e9) {
                        if(dp[k][j] + x < dp[k + 1][min(j + y, 100)]) {
                            dp[k + 1][min(j + y, 100)] = dp[k][j] + x;
                            pre[k + 1][min(j + y, 100)] = k * 1000 + j;
                        }
                        if(dp[k][j] < dp[k + 1][j]) {
                            dp[k + 1][j] = dp[k][j];
                            pre[k + 1][j] = k * 1000 + j;
                        }
                    }
                }
            }
            if(cur + dp[q][100] > b[i]) {
                ok = 0;
                break;
            }
            cur += dp[q][100];
            int x = q, y = 100;
            while(y) {
                int px = pre[x][y] / 1000, py = pre[x][y] % 1000;
                if(y != py) ans.push_back(get<2>(a[i][px]));
                x = px, y = py;
            }
        }
        if(ok == 0) {
            cout << -1 << '\n';
        } else {
            cout << ans.size() << '\n';
            for(int i : ans) cout << i + 1 << ' ';
            cout << '\n';
        }
    }
}