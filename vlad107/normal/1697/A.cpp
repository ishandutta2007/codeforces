#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>
#include <limits>
#include <stack>
#include <type_traits>
#include <exception>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n, m;
        std::cin >> n >> m;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            sum += x;
        }
        std::cout << std::max(sum - m, 0) << "\n";
    }
    return 0;
}