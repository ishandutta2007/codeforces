#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
    vector<vector<int>> ans(n, vector<int>(n, -1));
    vector<int> cnt(n);
    for(int i = 0; i < n; ++i) ans[i][i] = a[i], cnt[i] = i;
    for(int i = 1; i < n; ++i) {
        vector<int> vis(n);
        for(int j = 0; j + i < n; ++j) {
            // ans[i + j][j]
            if(cnt[ans[i + j - 1][j]] && !vis[ans[i + j - 1][j]]) ans[i + j][j] = ans[i + j - 1][j];
            else ans[i + j][j] = ans[i + j][j + 1];
            --cnt[ans[i + j][j]];
            vis[ans[i + j][j]] = 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            cout << ans[i][j] + 1 << " ";
        }
        cout << '\n';
    }
}