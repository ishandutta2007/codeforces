#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxk = 250 + 5;
int nxt[maxn][26], pos[26];
int dp[maxk][maxk][maxk], ln[4];
char s[maxn], d[2], e[2];
char a[maxk], b[maxk], c[maxk];

int main() {
    int n, q; scanf("%d%d", &n, &q);
    scanf("%s", s + 1);

    for (int i = 0; i < 26; ++i) pos[i] = n + 1;
    for (int i = n; i >= 0; --i) {
        for (int j = 0; j < 26; ++j)
            nxt[i][j] = pos[j];
        if (i > 0)
            pos[s[i] - 'a'] = i;
    }

    for (int i = 0; i < maxk; ++i) {
        for (int j = 0; j < maxk; ++j) {
            for (int k = 0; k < maxk; ++k)
                dp[i][j][k] = n + 1;
        }
    }
    dp[0][0][0] = 0;

    while (q--) {
        int p; scanf("%s%d", d, &p);
        if (d[0] == '+') {
            scanf("%s", e);
            if (p == 1) {
                a[++ln[p]] = e[0];
                for (int i = 0; i <= ln[2]; ++i) {
                    for (int j = 0; j <= ln[3]; ++j) {
                        if (dp[ln[p] - 1][i][j] <= n) 
                            dp[ln[p]][i][j] = min(dp[ln[p]][i][j], nxt[dp[ln[p] - 1][i][j]][a[ln[p]] - 'a']);
                        if (i + 1 <= ln[2] && dp[ln[p]][i][j] <= n)
                            dp[ln[p]][i + 1][j] = min(dp[ln[p]][i + 1][j], nxt[dp[ln[p]][i][j]][b[i + 1] - 'a']);
                        if (j + 1 <= ln[3] && dp[ln[p]][i][j] <= n)
                            dp[ln[p]][i][j + 1] = min(dp[ln[p]][i][j + 1], nxt[dp[ln[p]][i][j]][c[j + 1] - 'a']);

                    }
                }
            }
            if (p == 2) {
                b[++ln[p]] = e[0];
                for (int i = 0; i <= ln[1]; ++i) {
                    for (int j = 0; j <= ln[3]; ++j) {
                        if (dp[i][ln[p] - 1][j] <= n) 
                            dp[i][ln[p]][j] = min(dp[i][ln[p]][j], nxt[dp[i][ln[p] - 1][j]][b[ln[p]] - 'a']);
                        if (i + 1 <= ln[1] && dp[i][ln[p]][j] <= n)
                            dp[i + 1][ln[p]][j] = min(dp[i + 1][ln[p]][j], nxt[dp[i][ln[p]][j]][a[i + 1] - 'a']);
                        if (j + 1 <= ln[3] && dp[i][ln[p]][j] <= n)
                            dp[i][ln[p]][j + 1] = min(dp[i][ln[p]][j + 1], nxt[dp[i][ln[p]][j]][c[j + 1] - 'a']);
                    }
                }
            }
            if (p == 3) {
                c[++ln[p]] = e[0];
                for (int i = 0; i <= ln[1]; ++i) {
                    for (int j = 0; j <= ln[2]; ++j) {
                        if (dp[i][j][ln[p] - 1] <= n) 
                            dp[i][j][ln[p]] = min(dp[i][j][ln[p]], nxt[dp[i][j][ln[p] - 1]][c[ln[p]] - 'a']);
                        if (i + 1 <= ln[1] && dp[i][j][ln[p]] <= n)
                            dp[i + 1][j][ln[p]] = min(dp[i + 1][j][ln[p]], nxt[dp[i][j][ln[p]]][a[i + 1] - 'a']);
                        if (j + 1 <= ln[2] && dp[i][j][ln[p]] <= n)
                            dp[i][j + 1][ln[p]] = min(dp[i][j + 1][ln[p]], nxt[dp[i][j][ln[p]]][b[j + 1] - 'a']);
                    }
                }
            }
        } else {
            if (p == 1) {
                for (int i = 0; i <= ln[2]; ++i) {
                    for (int j = 0; j <= ln[3]; ++j)
                        dp[ln[p]][i][j] = n + 1;
                }
            }
            if (p == 2) {
                for (int i = 0; i <= ln[1]; ++i) {
                    for (int j = 0; j <= ln[3]; ++j)
                        dp[i][ln[p]][j] = n + 1;
                }
            }
            if (p == 3) {
                for (int i = 0; i <= ln[1]; ++i) {
                    for (int j = 0; j <= ln[2]; ++j)
                        dp[i][j][ln[p]] = n + 1;
                }
            }
            ln[p]--;
        }

        if (dp[ln[1]][ln[2]][ln[3]] <= n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}