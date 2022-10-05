#include <bits/stdc++.h>

const int N = 2010;
const int M = 10;

char s[N][M];
char basic[N][M] = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};
int a[N];
int bin_basic[N];
int trans[N][M];
bool dp[N][N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < 7; ++ j){
            a[i] = a[i] << 1 | (s[i][j] - '0');
        }
    }
    for (int i = 0; i < M; ++ i){
        for (int j = 0; j < 7; ++ j){
            bin_basic[i] = bin_basic[i] << 1 | (basic[i][j] - '0');
        }
    }
    for (int i = 0; i < 1 << 7; ++ i){
        memset(trans[i], -1, sizeof(trans[i]));
        for (int j = 0; j < M; ++ j){
            if ((bin_basic[j] & i) == i){
                auto &u = trans[i][__builtin_popcount(i ^ bin_basic[j])];
                u = std::max(u, j);
            }
        }
    }
    dp[n][0] = true;
    for (int i = n - 1; i >= 0; -- i){
        for (int kk = 0; kk < N; ++ kk){
            if (!dp[i + 1][kk]){
                continue;
            }
            for (int j = 0; j <= 7; ++ j){
                if (kk + j > k){
                    continue;
                }
                int to = trans[a[i]][j];
                if (to == -1){
                    continue;
                }
                dp[i][j + kk] = true;
            }
        }
    }
    if (!dp[0][k]){
        puts("-1");
        return 0;
    }
    int now = k;
    for (int i = 0; i < n; ++ i){
        for (int j = M - 1; j >= 0; -- j){
            if ((bin_basic[j] & a[i]) != a[i]){
                continue;
            }
            int diff = __builtin_popcount(a[i] ^ bin_basic[j]);
            if (now < diff){
                continue;
            }
            if (dp[i + 1][now - diff]){
                now -= diff;
                putchar(j + '0');
                break;
            }
        }
    }
    puts("");
    return 0;
}