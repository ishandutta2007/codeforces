#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, x, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, d, r1, r2, r3;
ll dp[1005005][2], a[1005000], b[1005000], pb[1005000];
vector<pii> ans;
ll diff(string x, string y) {
    ll ans = 0;
    for (int i = 0; i < x.size(); i++) {
        ans += (x[i] != y[i]);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(0));
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = min(a[i] * r1 + r3, r1 + min(r2, r1 * (a[i] + 1)));
        pb[i + 1] = pb[i] + b[i];
    }
    ll ans = 1LL * MOD * MOD;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = 1LL * MOD * MOD;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i+1][1] = min(dp[i+1][1], dp[i][0] + r1 + min(r2, r1 * (a[i] + 1)) + 2 * d);
        dp[i+1][0] = min(dp[i+1][0], dp[i][0] + a[i] * r1 + r3);
        dp[i+1][0] = min(dp[i+1][0], dp[i][1] + min(r1 + min(r2, r1 * (a[i] + 1)), a[i] * r1 + r3));
        if (i == n - 2) {
            ans = min(ans, dp[i][0] + r1 + min(r2, r1 * (a[i] + 1)) + d + min(a[n-1] * r1 + r3, r1 + min(r2, r1 * (a[n-1] + 1)) + d));
        }
        if (i < n - 2) {
            ans = min(ans, dp[i][0] + r1 + min(r2, r1 * (a[i] + 1)) + (n - 1 - i) * d + pb[n-1] - pb[i+1] + min(a[n-1] * r1 + r3, r1 + min(r2, r1 * (a[n-1] + 1)) + 2 * d));
        }
    }
    ans = min(ans, min(dp[n][0], dp[n][1]));
    /*for (int i = 0; i <= n; i++) {
        cout << dp[i][0] << " " << dp[i][1] << "\n";
    }*/
    cout << ans + (n-1) * d << "\n";
    return 0;
}