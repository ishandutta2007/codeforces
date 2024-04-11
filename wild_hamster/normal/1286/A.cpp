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
#define MAXN 300500
#define OFF 200001
#define MOD 1000000007
ll N;
ll n, x, k, z, m, pos, q, ans_v, y;
ll a[205000], b[200500];
ll f[2];
ll dp[105][105][105][2];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            b[a[i]] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            f[i%2]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                for (int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = MOD;
                }
            }
        }
    }
    if (a[0] == 0) {
        dp[1][1][0][0] = 0;
        dp[1][0][1][1] = 0;
    } else {
        if (a[0] % 2) {
            dp[1][0][1][1] = 0;
        } else {
            dp[1][1][0][0] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i+1][j+1][k][0] = min(dp[i+1][j+1][k][0], min(dp[i][j][k][0], dp[i][j][k][1] + 1));
                    dp[i+1][j][k+1][1] = min(dp[i+1][j][k+1][1], min(dp[i][j][k][1], dp[i][j][k][0] + 1));
                }
            }
        } else {
            if (a[i] % 2) {
                for (int j = 0; j <= n; j++) {
                    for (int k = 0; k <= n; k++) {
                        dp[i+1][j][k+1][1] = min(dp[i+1][j][k+1][1], min(dp[i][j][k][1], dp[i][j][k][0] + 1));
                    }
                }
            } else {
                for (int j = 0; j <= n; j++) {
                    for (int k = 0; k <= n; k++) {
                        dp[i+1][j+1][k][0] = min(dp[i+1][j+1][k][0], min(dp[i][j][k][0], dp[i][j][k][1] + 1));
                    }
                }
            }
        }
    }
    cout << min(dp[n][n/2][n-n/2][0], dp[n][n/2][n-n/2][1]) << endl;
    return 0;

}