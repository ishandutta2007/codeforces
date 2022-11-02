#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 30005, K = 205;

int n, k;

int a[N], s[N];

const int INF = 2147483647;

int dp[N][K][2][2][2];

inline void update(int &a, int b) {
    a = max(a, b);
}

inline int sign(int i, int s) {
    return 1 < i && i <= k ? (s ? -1 : 1) : 0;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            for (int s0 = 0; s0 < 2; ++s0) {
                for (int s1 = 0; s1 < 2; ++s1) {
                    for (int s2 = 0; s2 < 2; ++s2) {
                        dp[i][j][s0][s1][s2] = -INF;
                    }
                }
            }
        }
    }
    dp[0][0][0][0][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int s0 = 0; s0 < 2; ++s0) {
                for (int s1 = 0; s1 < 2; ++s1) {
                    for (int t = 0; t < 2; ++t) {
                        if (dp[i][j][s0][s1][t] == -INF) {
                            continue;
                        }
//cout << i << ' ' << j << ' ' << s0 << ' ' << s1 << ' ' << t << ' ' << dp[i][j][s0][s1][t] << endl;
                        if (t == 0) {
                            //take this 
                            int coef = sign(j, s0) + sign(j + 1, s1);
                            update(dp[i + 1][j][s0][s1][t], dp[i][j][s0][s1][t] + coef * a[i]);
                            //do not take this
                            update(dp[i + 1][j][s0][s1][1], dp[i][j][s0][s1][t]);
                            if (j < k) {
                                //take this start a new block
                                for (int ns = 0; ns <= 1; ++ns) {
                                    int coef = sign(j + 1, s1 ^ 1) + sign(j + 2, ns);
                                    update(dp[i + 1][j + 1][s1 ^ 1][ns][0], dp[i][j][s0][s1][t] + coef * a[i]);
                                }
                            }
                        } else {
                            //do not take this
                            update(dp[i + 1][j][s0][s1][t], dp[i][j][s0][s1][t]);
                            if (j < k) {
                                //take this start a new block
                                for (int ns = 0; ns <= 1; ++ns) {
                                    int coef = sign(j + 1, s1 ^ 1) + sign(j + 2, ns);
                                    update(dp[i + 1][j + 1][s1 ^ 1][ns][0], dp[i][j][s0][s1][t] + coef * a[i]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = -INF;
    for (int s0 = 0; s0 < 2; ++s0) {
        for (int s1 = 0; s1 < 2; ++s1) {
            ans = max(ans, dp[n][k][s0][s1][0]);
            ans = max(ans, dp[n][k][s0][s1][1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}