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
    int n, tt;
    std::cin >> n >> tt;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    sort(p.begin(), p.end(), std::greater<int>());
    std::vector<long long> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + p[i - 1];
    }
    while (tt--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << pref[x] - pref[x - y] << "\n";
    }
    return 0;
}