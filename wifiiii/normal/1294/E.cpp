#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(2 * n, vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
            --a[i][j];
            a[i + n][j] = a[i][j];
        }
    }
    /*
    0 1 2 ...
    m ...
    ..
    */
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        // column i
        for(int j = 0; j < 2 * n; ++j) {
            a[j][i] -= j * m;
        }
        int tmp = 1e9;
        unordered_map<int, int> cnt;
        for(int j = 0; j < 2 * n; ++j) {
            // row [j - n + 1, j]
            cnt[a[j][i]] += 1;
            if(j >= n - 1) {
                tmp = min(tmp, j - (n - 1) + (n - cnt[i - (j - n + 1) * m]));
                cnt[a[j - n + 1][i]] -= 1;
            }
        }
        ans += tmp;
    }
    cout << ans << '\n';
}