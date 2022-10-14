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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll a[MAXN], b[MAXN], ans[MAXN];
vector<ll> f;
ll dp[2005][2005][2], dpr[2005][2005];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin >> s;
    ll n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == '(') {
                dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
            } else if (s[i] == ')') {
                dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0] + dp[i][j][1]) % MOD;
            } else {
                dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
                dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0] + dp[i][j][1]) % MOD;
            }
        }
    }

    dpr[n][0] = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= n; j++) {
            if (s[i-1] == '(') {
                dpr[i-1][j] = (dpr[i-1][j] + dpr[i][j]) % MOD;
            } else if (s[i-1] == ')') {
                dpr[i-1][j+1] = (dpr[i-1][j+1] + dpr[i][j]) % MOD;
            } else {
                dpr[i-1][j] = (dpr[i-1][j] + dpr[i][j]) % MOD;
                dpr[i-1][j+1] = (dpr[i-1][j+1] + dpr[i][j]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        for (int j = n; j >= 1; j--) {
            sum = (sum + dpr[i][j]) % MOD;
            ans = (ans + dp[i][j][1] * sum) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}