#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < m; i += 2) ans[0][i] = 1;
        for(int i = 0; i < m; i += 2) ans[n-1][i] = 1;
        for(int i = 2; i+2 < n; i += 2) {
            ans[i][0] = ans[i][m-1] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}