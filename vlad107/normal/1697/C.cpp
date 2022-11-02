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

bool check(std::string s, std::string t) {
    size_t next_diff = 1;
    size_t pos_s = 0;
    for (size_t pos_t = 0; pos_t < t.size(); pos_t++) {
        while ((pos_s < s.size()) && (s[pos_s] == 'd')) ++pos_s;

        next_diff = std::max(next_diff, pos_s + 1);
        while ((next_diff < s.size()) && (s[next_diff] == s[pos_s])) ++next_diff;

        if (s[pos_s] == t[pos_t]) {
            ++pos_s;
            continue;
        }
        if (s[pos_s] > t[pos_t]) return false;
        if ((s[pos_s] == 'a') && (t[pos_t] == 'c')) return false;
        if ((next_diff == s.size()) || (s[next_diff] != t[pos_t])) return false;

        s[next_diff] = 'd';
        ++next_diff;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int tt;
    std::cin >> tt;
    while (tt--) {
        int n;
        std::cin >> n;
        std::string s, t;
        std::cin >> s >> t;
        if (check(s, t)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}