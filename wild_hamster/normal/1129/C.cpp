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
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, sz;
ll a[200500], b[200500];
vector<ll> g[100500];
ll bor[5005000][2], dp[5005], ans[5005];
int main() {
    for (int i = 0; i < 5000000; i++)
        for (int j = 0; j < 2; j++)
            bor[i][j] = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    sz = 1;
    for (int i = 0; i < n; i++) {
        int ver = 0;
        int was = 1;
        for (int j = i; j <= n; j++) {
            dp[j] = 0;
        }
        dp[i] = 1;
        for (int j = i; j < n; j++) {
            if (bor[ver][a[j]] == -1) {
                was = 0;
                ver = bor[ver][a[j]] = sz++;
            } else {
                ver = bor[ver][a[j]];
            }
            for (int k = 1; k <= 4; k++) {
                if (j - k + 1 < i) {
                    break;
                }
                int num = 0;
                for (int l = j-k+1; l <= j; l++) {
                    num = num * 2 + a[l];
                }
                if (k < 4 || (num != 3 && num != 5 && num != 14 && num != 15)) {
                    dp[j+1] = (dp[j+1] + dp[j-k+1]) % MOD;
                }
            }
            if (!was) {
                ans[j] = (ans[j] + dp[j+1]) % MOD;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            ans[i] = (ans[i] + ans[i-1]) % MOD;
        }
        cout << ans[i] << endl;
    }
    return 0;
}