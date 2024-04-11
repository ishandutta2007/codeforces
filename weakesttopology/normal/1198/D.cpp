#include <iostream>
#include <string>
#include <cstring>
constexpr int Nmax = 50, inf = 0x3f3f3f3f;
int dp[Nmax + 1][Nmax + 1][Nmax + 1][Nmax + 1];
int solve(int xl, int xr, int yl, int yr) {
    int &cost = dp[xl][xr][yl][yr];
    if (cost != inf) {
        return cost;
    }
    cost = std::max(xr - xl, yr - yl);
    for (int x = xl; x < xr; ++x) {
        if (solve(x, x + 1, yl, yr) != 0) continue;
        cost = std::min(cost, solve(xl, x, yl, yr) + solve(x + 1, xr, yl, yr));
    }
    for (int y = yl; y < yr; ++y) {
        if (solve(xl, xr, y, y + 1) != 0) continue;
        cost = std::min(cost, solve(xl, xr, yl, y) + solve(xl, xr, y + 1, yr));
    }
    return cost;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::memset(dp, 0x3f, sizeof(dp));
    int N;
    std::cin >> N;
    for (int x = 0; x <= N; ++x) {
        for (int yl = 0; yl <= N; ++yl) {
            for (int yr = 0; yr <= N; ++yr) {
                dp[x][x][yl][yr] = 0;
                dp[yl][yr][x][x] = 0;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < N; ++j) {
            dp[i][i + 1][j][j + 1] = (s[j] == '.' ? 0 : 1);
        }
    }
    std::cout << solve(0, N, 0, N) << '\n';
    exit(0);
}