#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
const long long oo = 1000000000000000007LL;

int nTest, n, a, b;
char s[MAXN];
long long dp[MAXN][2];

int main() {
    scanf("%d", &nTest);
    for(int iTest = 1; iTest <= nTest; ++iTest) {
        scanf("%d%d%d", &n, &a, &b);
        scanf("%s", s);

        dp[0][0] = b;
        dp[0][1] = oo;

        for(int i = 1; i <= n; ++i) {
            if (s[i-1] == '0') {
                dp[i][0] = min(dp[i-1][0] + a, dp[i-1][1] + 2*a);
                dp[i][1] = min(dp[i-1][0] + 2*a, dp[i-1][1] + a);
            } else {
                dp[i][0] = oo;
                dp[i][1] = dp[i-1][1] + a;
            }
            dp[i][0] += b;
            dp[i][1] += 2*b;
        }

//        for(int i = 0; i <= n; ++i)
//            printf("%lld %lld\n", dp[i][0], dp[i][1]);

        printf("%lld\n", dp[n][0]);
    }

    return 0;
}