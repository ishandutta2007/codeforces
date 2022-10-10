#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 110;

bool dp[ms][ms][2][2];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    for(int i = 0; i < ms; i++) for(int j = 0; j < ms; j++) for(int p = 0; p < 2; p++) for(int s = 0; s < 2; s++) {
        if(i == 0 && j == 0) {
            dp[i][j][p][s] = s == 0;
        } else {
            if(p == 1) {
                dp[i][j][p][s] = true;
            }
            if(i) {
                int v = s ^ (p == 0 ? 1 : 0);
                bool got = dp[i-1][j][1-p][v];
                if(p == 0 && got) {
                    dp[i][j][p][s] = true;
                } else if(p == 1 && !got) {
                    dp[i][j][p][s] = false;
                }
            }
            if(j) {
                int v = s;
                bool got = dp[i][j-1][1-p][v];
                if(p == 0 && got) {
                    dp[i][j][p][s] = true;
                } else if(p == 1 && !got) {
                    dp[i][j][p][s] = false;
                }
            }
        }
    }
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        int f[2] = {0, 0};
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            f[x & 1]++;
        }
        std::cout << (dp[f[1]][f[0]][0][0] ? "Alice\n" : "Bob\n");
    }
}