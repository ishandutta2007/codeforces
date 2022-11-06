#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <vector>
#include <string>
#define x first
#define y second
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define point pair<int, int>

using namespace std;

typedef long long base;

base n, a, b;
base arr[1000002];
base dp[1000002][3];
set <int> prime;


int main() {
    //freopen("trains.in", "r", stdin);
    //freopen("trains.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    For(i, 0, n) cin >> arr[i];
    For(i, 0, 2) {
        For(j, 0, 3) {
            int k = arr[i * (n - 1)] + j - 1;
            For(j, 2, 1e9) {
                if (j * j > k) break;
                while (k % j == 0) {
                    prime.insert(j);
                    k /= j;
                }
            }
            if (k != 1 && k != 0) prime.insert(k);
        }
    }
    base ans = 1e18;
    for(int p: prime) {
        For(i, 0, n + 1) For(j, 0, 3) dp[i][j] = 1e18;
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        For(i, 0, n) {
            if (arr[i] % p == 0) {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][2]);
            } else {
                if ((arr[i] + 1) % p == 0 || (arr[i] - 1) % p == 0) {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + b);
                    dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + b);
                }
            }
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a);
            dp[i + 1][1] = min(dp[i + 1][0], dp[i + 1][1]);
            dp[i + 1][2] = min(dp[i + 1][2], dp[i + 1][1]);
        }
        ans = min(ans, dp[n][2]);
        //cout << p << ' ' << dp[n][2] << ' ' << dp[n][1] << ' ' << dp[n][2] << endl;
    }
    cout << ans << endl;
}