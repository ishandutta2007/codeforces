#ifndef tabr
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

constexpr int mod = 998244353;

int dp[2][1 << 3][1 << 6][1 << 3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    // s = string((int) 200000, '0');
    // for (int i = 0; i < (int) s.size(); i++) {
    //     s[i] += rand_int(0, 1);
    // }
    dp[0][(1 << 3) - 1][0][0] = 1;
    for (char c : s) {
        memset(dp[1], 0, sizeof dp[1]);
        for (int x = 0; x < (1 << 3); x++) {
            for (int y = 0; y < (1 << 6); y++) {
                for (int z = 0; z < (1 << 3); z++) {
                    if (dp[0][x][y][z] == 0) {
                        continue;
                    }
                    for (int nxt = 0; nxt < 8; nxt++) {
                        bool bad = false;
                        int nx = x;
                        for (int i = 0; i < 3; i++) {
                            if (x & (1 << i)) {
                                if (c == '0') {
                                    if (nxt & (1 << i)) {
                                        bad = true;
                                    }
                                } else {
                                    if (~nxt & (1 << i)) {
                                        nx &= ~(1 << i);
                                    }
                                }
                            }
                        }
                        if (bad) {
                            continue;
                        }
                        int ny = y;
                        if (1 <= nxt && nxt <= 6) {
                            ny |= 1 << (nxt - 1);
                        }
                        int nz = z;
                        for (int i = 0; i < 3; i++) {
                            if (!!(nxt & (1 << i)) != !!(nxt & (1 << ((i + 1) % 3)))) {
                                nz |= 1 << i;
                            }
                        }
                        dp[1][nx][ny][nz] += dp[0][x][y][z];
                        if (dp[1][nx][ny][nz] >= mod) {
                            dp[1][nx][ny][nz] -= mod;
                        }
                    }
                }
            }
        }
        swap(dp[0], dp[1]);
    }
    long long ans = 0;
    for (int y = 0; y < (1 << 6); y++) {
        int t = 0;
        if ((y & (1 << 0)) || (y & (1 << 5))) {
            t |= 1;
        }
        if ((y & (1 << 1)) || (y & (1 << 4))) {
            t |= 2;
        }
        if ((y & (1 << 2)) || (y & (1 << 3))) {
            t |= 4;
        }
        if (t == 7) {
            for (int x = 0; x < (1 << 3); x++) {
                ans += dp[0][x][y][7];
            }
        }
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}