#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> as(n);
    for (auto& a : as) {
        std::cin >> a;
        --a;
    }
    std::reverse(as.begin(), as.end());

    std::vector<std::pair<int, int>> ranges(x, std::pair(x, -1));
    std::set<int> app;
    for (auto a : as) {
        app.insert(a);
        if (app.lower_bound(a) == app.begin()) {
            continue;
        }

        int l = *app.begin();
        int r = *(--app.lower_bound(a));
        ranges[a].first = std::min(ranges[a].first, l);
        ranges[a].second = std::max(ranges[a].second, r);
    }

    int cont = 0;
    while (cont < x) {
        if (ranges[cont].first <= ranges[cont].second) {
            break;
        }
        ++cont;
    }

    lint ans = 0;
    int left = x, right = -1;
    for (int a = x - 1; a >= 0; --a) {
        // when r = a
        ans += std::min({cont, left, a}) + 1;

        // a is already deleted
        if (right >= a) break;

        // leave a
        left = std::min(left, ranges[a].first);
        right = std::max(right, ranges[a].second);
    }

    std::cout << ans << std::endl;
    return 0;
}