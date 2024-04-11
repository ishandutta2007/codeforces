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
        vector<vector<int>> a(n, vector<int>(m)), ans(n, vector<int>(m, -1)), vis(n, vector<int>(m));
        vector<tuple<int,int,int>> b;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
                b.push_back({a[i][j], i, j});
            }
        }
        sort(b.begin(), b.end());
        for(int i = 0; i < m; ++i) {
            auto [w, x, y] = b[i];
            vis[x][y] = 1;
            ans[x][i] = w;
        }
        for(int i = 0; i < n; ++i) {
            int k = 0;
            for(int j = 0; j < m; ++j) {
                if(vis[i][j]) continue;
                while(k < m && ans[i][k] != -1) ++k;
                ans[i][k] = a[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
}