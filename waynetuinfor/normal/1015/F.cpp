#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 5, mod = 1e9 + 7;
char s[maxn];
int dp[maxn][maxn][maxn][2];
int dp2[maxn][2];
bool v[maxn][2];
int n, m;

int match(int k, char c) {
    if (v[k][c == '(']) return dp2[k][c == '('];
    v[k][c == '('] = true;
    for (int i = min(m, k + 1); i >= 1; --i) {
        bool f = s[i] == c;
        for (int j = k, t = i - 1; t >= 1; --j, --t) f &= (s[j] == s[t]);
        if (f) return dp2[k][c == '('] = i;
    }
    return 0;
}

int main() {
    scanf("%d", &n); n *= 2;
    scanf("%s", s + 1);
    m = strlen(s + 1);
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= m; ++k) for (int z = 0; z < 2; ++z) {
                if (j) {
                    int l = match(k, ')');
                    (dp[i + 1][j - 1][l][z || (l == m)] += dp[i][j][k][z]) %= mod; 
                }
                int l = match(k, '(');
                (dp[i + 1][j + 1][l][z || (l == m)] += dp[i][j][k][z]) %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i) (ans += dp[n][0][i][1]) %= mod;
    printf("%d\n", ans);
    return 0; 
}