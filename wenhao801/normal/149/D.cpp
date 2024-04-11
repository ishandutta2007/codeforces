#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

const int mod = 1e9 + 7, MAXN = 707;
int n; char a[MAXN];
int pp[MAXN]; stack <int> s;
int dp[MAXN][MAXN][3][3];
void dfs (int l, int r) {
    if (l == r - 1) {
        dp[l][r][0][1] = dp[l][r][1][0] = dp[l][r][0][2] = dp[l][r][2][0] = 1;
        return;
    }
    int i, j, p, q;
    if (pp[l] == r) {
        dfs(l + 1, r - 1);
        for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) {
            if (i == j) continue; if (i && j) continue;
            for (p = 0; p < 3; p++) for (q = 0; q < 3; q++) {
                if (i && p && i == p) continue;
                if (j && q && j == q) continue;
                dp[l][r][i][j] = (dp[l][r][i][j] + dp[l + 1][r - 1][p][q]) % mod;
            }
        }
    }
    else {
        dfs(l, pp[l]); dfs(pp[l] + 1, r);
        for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) 
            for (p = 0; p < 3; p++) for (q = 0; q < 3; q++) {
                if (p && q && p == q) continue;
                dp[l][r][i][j] = (dp[l][r][i][j] + 1ll * dp[l][pp[l]][i][p] * dp[pp[l] + 1][r][q][j] % mod) % mod;
            }
    }
}

int main () {
    scanf("%s", a + 1); n = strlen(a + 1);
    int i, j;
    for (i = 1; i <= n; i++) {
        if (a[i] == '(') s.push(i);
        else pp[i] = s.top(), pp[s.top()] = i, s.pop();
    }
    int ans = 0; dfs(1, n);
    for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) ans = (ans + dp[1][n][i][j]) % mod;
    printf("%d\n", ans);
    return 0;
}