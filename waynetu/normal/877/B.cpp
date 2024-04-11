#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
int cnt[2][maxn];

int main() {
    string s; cin >> s; 
    int n = s.length(); s = "." + s;
    for (int i = 1; i <= n; ++i) {
        cnt[0][i] = cnt[0][i - 1]; cnt[1][i] = cnt[1][i - 1];
        ++cnt[s[i] - 'a'][i];
    }
    int ans = cnt[0][n];
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int now = cnt[1][i - 1] + cnt[0][j] - cnt[0][i - 1] + cnt[1][n] - cnt[1][j];
            ans = max(ans, n - now);
        }
    }
    cout << ans << endl;
    return 0;
}