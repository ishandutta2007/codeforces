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

char get_sym(int pos) {
    std::cout << "? 1 " << pos << std::endl;
    char c;
    std::cin >> c;
    return c;
}

int get_uniq_count(int l, int r) {
    std::cout << "? 2 " << l << " " << r << std::endl;
    int cnt;
    std::cin >> cnt;
    return cnt;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, char>> elems;

    char first_sym = get_sym(1);
    elems.push_back({0, first_sym});

    std::string res;
    res += first_sym;

    for (int i = 1; i < n; i++) {
        int cnt = get_uniq_count(1, i + 1);
        if (cnt > (int)elems.size()) {
            char cur_sym = get_sym(i + 1);
            elems.push_back({i, cur_sym});
            res += cur_sym;
        } else {
            sort(elems.begin(), elems.end());
            int l = 0, r = elems.size();
            while (l < r - 1) {
                int mid = (l + r) / 2;
                int cur_cnt = get_uniq_count(elems[mid].first + 1, i + 1);
                // [mid; elems.size()) + cur_sym
                int size = (int)elems.size() - mid;
                if (size == cur_cnt) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            res += elems[l].second;
            elems[l].first = i;
        }
    }
    std::cout << "! " << res << std::endl;

    return 0;
}