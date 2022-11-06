#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5, mod = 1e9 + 7;
int dp[maxn], prv[26];
char s[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    scanf("%s", s);
    int m = strlen(s);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        dp[i] = dp[i - 1] * 2ll % mod;
        // printf("s[%d] = %c\n", i - 1, s[i - 1]);
        if (prv[s[i - 1] - 'a']) dp[i] = (dp[i] - dp[prv[s[i - 1] - 'a'] - 1] + mod) % mod;
        prv[s[i - 1] - 'a'] = i;
        // printf("dp[%d] = %d\n", i, dp[i]);
    }
    for (int i = m + 1; i <= m + n; ++i) {
        char c = 'a';
        for (char j = 'b'; j < 'a' + k; ++j) if (prv[j - 'a'] < prv[c - 'a']) c = j;
        dp[i] = dp[i - 1] * 2ll % mod;
        if (prv[c - 'a']) dp[i] = (dp[i] - dp[prv[c - 'a'] - 1] + mod) % mod;
        prv[c - 'a'] = i;
    }
    printf("%d\n", dp[m + n]);
    return 0;
}