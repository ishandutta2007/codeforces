#include <iostream>
#include <vector>
#include <set>

void solve() {
    int n, s, k;
    std::cin >> n >> s >> k;

    std::set<int> xs;
    while (k--) {
        int x;
        std::cin >> x;
        xs.insert(x);
    }

    int ans = n;
    for (int x = s; x >= 1; --x) {
        if (!xs.count(x)) {
            ans = std::min(ans, s - x);
            break;
        }
    }
    for (int x = s; x <= n; ++x) {
        if (!xs.count(x)) {
            ans = std::min(ans, x - s);
            break;
        }
    }

    std::cout << ans << std::endl;
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