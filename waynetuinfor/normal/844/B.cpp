#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 50 + 10;
int mp[maxn][maxn];

int32_t main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> mp[i][j];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt[2] = { 0, 0 };
        for (int j = 1; j <= m; ++j) cnt[mp[i][j]]++;
        ans += (1ll << cnt[0]) - 1;
        ans += (1ll << cnt[1]) - 1;
    }
    for (int j = 1; j <= m; ++j) {
        int cnt[2] = { 0, 0 };
        for (int i = 1; i <= n; ++i) cnt[mp[i][j]]++;
        ans += (1ll << cnt[0]) - 1;
        ans += (1ll << cnt[1]) - 1;
    }
    ans -= n * m;
    cout << ans << endl;
    return 0;
}