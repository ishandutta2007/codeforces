#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxh = 30 + 5, mod = 1e9 + 9;

int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
void cadd(int &a, int b) { a = add(a, b); }

int dp[maxn][2][maxh][maxh][maxh];

int main() {
    int n, h; scanf("%d %d", &n, &h);
    dp[0][0][0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int a = 0; a <= h + 1; ++a) {
            for (int b = 0; b <= h + 1; ++b) {
                for (int c = 0; c <= h + 1; ++c) {
                    int ato = (a + 1 <= h ? a + 1 : h + 1), bto = (b + 1 <= h ? b + 1 : h + 1), cto = (c + 1 <= h ? c + 1 : h + 1);
                    cadd(dp[i + 1][0][ato][bto][cto], dp[i][0][a][b][c]);
                    cadd(dp[i + 1][1][ato][bto][cto], dp[i][1][a][b][c]);
                    ato = (a + 1 <= h ? 0 : 1);
                    cadd(dp[i + 1][ato][bto][cto][h + 1], dp[i][1][a][b][c]);
                    cadd(dp[i + 1][ato][bto][cto][1], dp[i][0][a][b][c]);
                    ato = (a + 1 <= h ? a + 1 : h + 1); bto = (b + 1 <= h ? 0 : 1);
                    cadd(dp[i + 1][bto][cto][h + 1][ato], dp[i][1][a][b][c]);
                    cadd(dp[i + 1][bto][cto][1][ato], dp[i][0][a][b][c]);
                    bto = (b + 1 <= h ? b + 1 : h + 1); cto = (c + 1 <= h ? 0 : 1);
                    cadd(dp[i + 1][cto][h + 1][ato][bto], dp[i][1][a][b][c]);
                    cadd(dp[i + 1][cto][1][ato][bto], dp[i][0][a][b][c]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= h + 1; ++i) {
        for (int j = 0; j <= h + 1; ++j) {
            for (int k = 0; k <= h + 1; ++k) {
                if (i < h || j < h || k < h) cadd(ans, dp[n][1][i][j][k]);
                cadd(ans, dp[n][0][i][j][k]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}