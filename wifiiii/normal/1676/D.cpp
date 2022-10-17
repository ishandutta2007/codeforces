#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                ll sum = 0;
                {
                    int x = i, y = j;
                    while(x >= 0 && y < m) {
                        x -= 1;
                        y += 1;
                    }
                    x += 1;
                    y -= 1;
                    while(x < n && y >= 0) {
                        sum += a[x][y];
                        x += 1;
                        y -= 1;
                    }
                }
                {
                    int x = i, y = j;
                    while(x >= 0 && y >= 0) {
                        x -= 1;
                        y -= 1;
                    }
                    x += 1;
                    y += 1;
                    while(x < n && y < m) {
                        sum += a[x][y];
                        x += 1;
                        y += 1;
                    }
                }
                sum -= a[i][j];
                ans = max(ans, sum);
            }
        }
        cout << ans << '\n';
    }
}