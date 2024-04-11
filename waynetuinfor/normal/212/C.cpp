#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
long long dp[maxn][2][2];
char s[maxn], t[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A' && s[(i + 1) % n] == 'B') {
            int p = 0;
            for (int j = i; j < n; ++j) t[p++] = s[j];
            for (int j = 0; j < i; ++j) t[p++] = s[j];
            for (int j = 0; j < n; ++j) s[j] = t[j];
            break;
        }
    }

    bool aa = true, bb = true;
    for (int i = 0; i < n; ++i) {
        aa &= s[i] == 'A';
        bb &= s[i] == 'B';
    }

    if (aa || bb) {
        puts("1");
        return 0;
    }

    long long ans = 0;

    auto bf = [&]() {
        int cnt = 0;
        for (int i = 0; i < (1 << n); ++i) {
            int mask = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 0 && ((i >> ((j + 1) % n) & 1)) == 1) {
                    mask |= (1 << j);
                    mask |= (1 << ((j + 1) % n));
                }
            }
            int ans = i ^ mask;
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (ans >> j & 1) ok &= s[j] == 'B';
                else ok &= s[j] == 'A';
            }
            if (ok) {
                ++cnt;
                cout << bitset<6>(i) << endl;
            }
        }
        return cnt;
    };

    for (int f = 0; f < 2; ++f) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 2; ++i) {
            if (s[0] == 'A' && f == 0 && i == 1) continue;
            dp[1][f][i] = 1;
        }
        // for (int a = 0; a < 2; ++a) {
            // for (int b = 0; b < 2; ++b) {
                // printf("dp[%d][%d][%d] = %lld\n", 1, a, b, dp[1][a][b]);
            // }
        // }
        for (int i = 2; i < n; ++i) {
            for (int a = 0; a < 2; ++a) {
                for (int b = 0; b < 2; ++b) {
                    for (int c = 0; c < 2; ++c) {
                        int x = a, y = b, z = c;
                        if (a == 0 && b == 1) x ^= 1, y ^= 1;
                        if (b == 0 && c == 1) y ^= 1, z ^= 1;
                        if (y == s[i - 1] - 'A') 
                            dp[i][b][c] += dp[i - 1][a][b];
                    }
                }
            }
            // for (int a = 0; a < 2; ++a) {
                // for (int b = 0; b < 2; ++b) {
                    // printf("dp[%d][%d][%d] = %lld\n", i, a, b, dp[i][a][b]);
                // }
            // }
        }
        int inc = 0;
        for (int a = 0; a < 2; ++a) {
            for (int b = 0; b < 2; ++b) {
                int x = a, y = b, z = f;
                if (a == 0 && b == 1) x ^= 1, y ^= 1;
                if (b == 0 && f == 1) y ^= 1, z ^= 1;
                if (z == s[0] - 'A' && y == s[n - 1] - 'A')
                    ans += dp[n - 1][a][b], inc += dp[n - 1][a][b];
            }
        }
        // printf("f = %d inc = %d\n", f, inc);
    }
    printf("%lld\n", ans);
    return 0;
}