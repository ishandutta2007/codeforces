#include <iostream>
#include <numeric>
#include <vector>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> xs;
    xs.reserve(n);
    for (char c : s) xs.push_back(c - '0');

    while (!xs.empty() && xs.back() % 2 == 0) xs.pop_back();
    while (!xs.empty() && std::accumulate(xs.begin(), xs.end(), 0) % 2 != 0) xs.erase(xs.begin());
    while (!xs.empty() && xs.front() == 0) xs.erase(xs.begin());

    if (xs.empty()) {
        std::cout << -1 << std::endl;
    } else {
        for (auto x : xs) std::cout << x;
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}