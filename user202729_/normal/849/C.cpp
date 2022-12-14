#include <iostream>
#include <vector>
#include <array>
#include <limits>
#include <algorithm>

typedef long long ll;

const int MAX = 2001;
std::array<int, MAX> dp;

int main() {
    dp[0] = dp[1] = 0;
    for (int n = 2; n < MAX; ++n) {
        dp[n] = std::numeric_limits<int>::max();
        for (int i = 1; i + i <= n; ++i) {
            dp[n] = std::min(dp[n], dp[i] + dp[n-i] + i*(n-i));
        }
    }
    // it happens that dp[i] = triangular number [i]
//    for (int i = 0; i < 20; ++i) std::cout << i << '\t' << dp[i] << '\n';

    int n;
    std::cin >> n;
    char ch = 'a';
    if (n == 0) std::cout << ch; // a single 'a'
    else
    do {
        int cnt = (std::upper_bound(dp.begin(), dp.end(), n) - dp.begin()) - 1;
        n -= dp[cnt];
        if (n < 0) return -1;
        while (cnt --> 0) std::cout << ch;
        ++ch;
    } while (n != 0);
    std::cout << '\n';
}