#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n)), vis(n, vector<int>(n));
        vector<int> dx {-1, 1, 0, 0};
        vector<int> dy {0, 0, -1, 1};
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int ok = 1;
                for(int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0 || y < 0 || x == n || y == n) continue;
                    if(vis[x][y]) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    a[i][j] = 1;
                    for(int k = 0; k < 4; ++k) {
                        int x = i + dx[k], y = j + dy[k];
                        if(x < 0 || y < 0 || x == n || y == n) continue;
                        vis[x][y] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                if(a[i][j]) ans ^= x;
            }
        }
        cout << ans << '\n';
    }
}