#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll a[55][55], pa[55][55], dp[51][51][51][51];
ll get(ll x1, ll y1, ll x2, ll y2) {
    return pa[x2+1][y2+1] + pa[x1][y1] - pa[x2+1][y1] - pa[x1][y2+1];
}
ll get_dp(ll x1, ll y1, ll x2, ll y2) {
    if (dp[x1][y1][x2][y2] != -1) {
        return dp[x1][y1][x2][y2];
    }
    if (get(x1,y1,x2,y2) == 0) {
        return dp[x1][y1][x2][y2] = 0;
    }
    dp[x1][y1][x2][y2] = max(x2-x1+1, y2-y1+1);
    for (int i = x1; i < x2; i++) {
        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2],
                get_dp(x1,y1,i,y2) + get_dp(i+1,y1,x2,y2));
    }

    for (int i = y1; i < y2; i++) {
        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2],
                                 get_dp(x1,y1,x2,i) + get_dp(x1,i+1,x2,y2));
    }
    return dp[x1][y1][x2][y2];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pa[i+1][j+1] = pa[i][j+1] + pa[i+1][j] + a[i][j] - pa[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }

    cout << get_dp(0, 0, n-1, n-1) << endl;
    return 0;
}