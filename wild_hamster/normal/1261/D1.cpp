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
#define MAXN 10000007
#define MOD 998244353
#define OFF 2001
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
ll dp[2005][4005], a[2005];


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll m = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] != a[i+1]) {
            m++;
        }
    }
    if (a[0] != a[n-1]) {
        m++;
    }
    //cout << m << endl;

    dp[0][OFF] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= OFF + m + 1; j++) {
            dp[i+1][j] = (dp[i+1][j] + dp[i][j] * (k - 2)) % MOD;
            dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;

            dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = OFF + 1; i <= OFF + m + 1; i++) {
        ans = (ans + dp[m][i]) % MOD;
    }
    for (int i = 0; i < n-m; i++) {
        ans = ans * k % MOD;
    }
    cout << ans << "\n";


    return 0;
}