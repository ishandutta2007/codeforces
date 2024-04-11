#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <class It>
std::vector<std::pair<typename It::value_type, int>> runlength(
    It begin, It end) {
    using T = typename It::value_type;

    std::vector<std::pair<T, int>> res;
    while (begin != end) {
        const T& c = *(begin++);
        if (res.empty() || c != res.back().first) {
            res.emplace_back(c, 1);
        } else {
            ++res.back().second;
        }
    }

    return res;
}

void solve() {
    std::string s;
    std::cin >> s;

    auto ps = runlength(s.begin(), s.end());

    std::vector<int> xs;
    for (auto [c, l] : ps) {
        if (c == '1') xs.push_back(l);
    }

    std::sort(xs.rbegin(), xs.rend());
    int ans = 0;
    for (int i = 0; i < (int)xs.size(); i += 2) ans += xs[i];

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}