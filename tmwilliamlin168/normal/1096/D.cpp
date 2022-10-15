#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string s;
int n, a[100000];
long long dp[100001][4];
string r = "hard";

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (s[i-1] == r[0] ? dp[i-1][0] + a[i-1] : dp[i-1][0]);
        for (int j = 1; j < 4; j++) {
            if (s[i-1] == r[j])
                dp[i][j] = min(dp[i-1][j]+a[i-1], dp[i-1][j-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][3] << endl;

    return 0;
}