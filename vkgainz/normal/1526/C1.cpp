#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

long long dp[2001][2001];

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= 2000; i++){
        dp[0][i] = -1e15;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0LL;
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1e15;
            dp[i][j] = dp[i - 1][j]; //odnt take
            //take
            if (dp[i - 1][j - 1] >= -a[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i - 1]);
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        if (dp[n][j] >= 0) {
            ans = j;
        }
    }
    cout << ans;
}