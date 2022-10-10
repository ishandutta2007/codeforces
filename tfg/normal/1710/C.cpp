#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

int n;
std::string str;
int memo[200200][1 << 3][3][3][3];

void fix(int &x) {
    x = std::max(x, -2);
    x = std::min(x, 2);
}

int dp(int on, int mask, int b0, int b1, int b2) {
    fix(b0);
    fix(b1);
    fix(b2);
    assert(b0 % 2 == 0 && b1 % 2 == 0 && b2 % 2 == 0);
    int &ans = memo[on][mask][b0/2+1][b1/2+1][b2/2+1];
    if(ans != -1) return ans;
    ans = 0;
    if(on == n) {
        if(b0 < 0 && b1 < 0 && b2 < 0) {
            ans = 1;
        }
    } else {
        int lim[3] = {0, 0, 0};
        for(int i = 0; i < 3; i++) {
            lim[i] = (mask & (1 << i)) ? 1 : str[on] - '0';
        }
        for(int i = 0; i <= lim[0]; i++) for(int j = 0; j <= lim[1]; j++) for(int k = 0; k <= lim[2]; k++) {
            int nxtMask = mask | (i < lim[0] ? 1 : 0) | (j < lim[1] ? 2 : 0) | (k < lim[2] ? 4 : 0);
            int a = (i^j), b = (i^k), c = (j^k);
            int sum = a + b + c;
            ans = (ans + dp(on+1, nxtMask, (b0 + a * 2 - sum) * 2, (b1 + b * 2 - sum) * 2, (b2 + c * 2 - sum) * 2)) % MOD;
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::cin >> str;
    n = (int) str.size();
    memset(memo, -1, sizeof memo);
    std::cout << dp(0, 0, 0, 0, 0) << '\n';
}