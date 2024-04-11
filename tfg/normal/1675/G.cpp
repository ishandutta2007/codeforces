#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 255;
const int INF = 1e9;

int n, m;
int a[ms];
int memo[ms][ms][2*ms];

int dp(int on, int val, int bal) {
    if(std::abs(bal) > m || (n-on) * val > m) {
        return INF;
    }
    if(on == n) {
        return bal == 0 ? 0 : INF;
    }
    int &ans = memo[on][val][bal+ms];
    if(ans != -1) return ans;
    // try with these values
    int curVal = a[on] + bal;
    ans = dp(on+1, val, curVal - val) + std::abs(curVal - val);
    // try increasing value
    ans = std::min(ans, dp(on, val+1, bal));
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        std::cin >> a[n-i-1];
    }
    memset(memo, -1, sizeof memo);
    std::cout << dp(0, 0, 0) << '\n';
}