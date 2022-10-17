#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(a[0][0] == '1') {
            cout << -1 << '\n';
            continue;
        }
        vector<array<int, 4>> ans;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == '1') {
                    if(i) {
                        ans.push_back({i - 1, j, i, j});
                    } else if(j) {
                        ans.push_back({i, j - 1, i, j});
                    }
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i) {
            for(int j = 0; j < 4; ++j) {
                cout << ans[i][j] + 1 << ' ';
            }
            cout << '\n';
        }
    }
}