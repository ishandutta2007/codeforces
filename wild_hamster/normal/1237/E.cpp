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
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;

ll b[600500], p[600500];
struct hyu {
    ll x;
    ll y;
    ll z;
    ll num;
};

ll a[500500];
ll mn[300500][20], mx[300500][20], pr[3005000];

ll find_min(ll l, ll r) {
    if (l > r) {
        return MOD;
    }
    ll p = pr[r-l+1];
    return min(mn[l][p], mn[r-(1<<p)+1][p]);
}


ll find_max(ll l, ll r) {
    ll p = pr[r-l+1];
    return max(mx[l][p], mx[r-(1<<p)+1][p]);
}

ll dp[1005000][2][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 20; i++) {
        pr[(1<<i)] = i;
    }
    for (int i = 1; i <= 1000000; i++) {
        pr[i] = max(pr[i], pr[i-1]);
    }
    dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 1;
    dp[1][0][0] = dp[1][1][1] = 1;
    for (int i = 2; i <= 1000; i++) {
        ll sz = pr[i];
        for (int j = 0; j <= i-1; j++) {
            if ((pr[j] + 1 == sz || pr[j+1] + 1 == sz) && (pr[i - j - 1] + 1 == sz || pr[i-j] + 1 == sz)) {
                dp[i][1][(j+1)%2] += dp[j][1][j%2] * dp[i-j-1][j%2][(j+1)%2];
                dp[i][0][j%2] += dp[j][0][(j+1)%2] * dp[i-j-1][(j+1)%2][j%2];
            }
        }
    }
    for (int i = 1; i <= 1000; i++) {
        if (dp[i][1][0] + dp[i][1][1] != 0) {
            //cout << i << " " << dp[i][1][0] << " " << dp[i][1][1] << endl;
        }
    }
    cin >> n;
    ll x = 1, y = 2;
    while (x < 10000000) {
        if (x == n || y == n) {
            cout << 1 << endl;
            return 0;
        }
        ll z;
        if (x % 2) {
            z = x + y + 1;
        } else {
            z = x + y;
        }
        x = z;
        y = z + 1;
    }
    cout << 0 << endl;

    return 0;
}