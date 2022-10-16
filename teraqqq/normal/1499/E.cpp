#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <random>

#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())
#define eb emplace_back
#define all(x) begin(x), end(x)

using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;

const int N = 1001;
const int MOD = 998244353;

ll cnt[2][N][N];
ll ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string x, y;
    cin >> x >> y;
    int n = x.size();
    int m = y.size();
    for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
        if (i != 0) {
            if (i > 1 && x[i-1] != x[i-2]) cnt[0][i][j] += cnt[0][i-1][j];
            if (j > 0 && x[i-1] != y[j-1]) cnt[0][i][j] += cnt[1][i-1][j];
        }
        if (j != 0) {
            if (i > 0 && y[j-1] != x[i-1]) cnt[1][i][j] += cnt[0][i][j-1];
            if (j > 1 && y[j-1] != y[j-2]) cnt[1][i][j] += cnt[1][i][j-1];
        }

        cnt[0][i][j] %= MOD;
        cnt[1][i][j] %= MOD;

        cnt[0][i][j] += (i != 0);
        cnt[1][i][j] += (j != 0);

        ans += cnt[0][i][j] + cnt[1][i][j];
        ans %= MOD;
    }

    for (int i = 0, j = 0; i < n; ++i) {
        if (i && x[i] == x[i-1]) j = i;
        ans += MOD - (ll)(i-j+1)*(m+1)%MOD;
    }
    for (int i = 0, j = 0; i < m; ++i) {
        if (i && y[i] == y[i-1]) j = i;
        ans += MOD - (ll)(i-j+1)*(n+1)%MOD;
    }

    ans %= MOD;
    if (ans < 0) ans += MOD;

    cout << ans << '\n';
}