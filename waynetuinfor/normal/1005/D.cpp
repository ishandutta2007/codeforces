#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int dp[maxn], s[maxn], z[3];
char a[maxn];

int main() {
    scanf("%s", a + 1);
    int n = strlen(a + 1);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i] - '0';
    z[0] = 0;
    z[1] = z[2] = -1;
    for (int i = 1; i <= n; ++i) {
        if (~z[s[i] % 3]) dp[i] = max(dp[i], dp[z[s[i] % 3]] + 1);
        for (int j = 0; j < 3; ++j) dp[i] = max(dp[i], dp[z[j]]);
        if (z[s[i] % 3] == -1 || dp[i] > dp[z[s[i] % 3]]) z[s[i] % 3] = i;
    }
    printf("%d\n", dp[n]);
}