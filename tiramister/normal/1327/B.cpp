#include <iostream>
#include <set>

void solve() {
    int n;
    std::cin >> n;

    int ans = -1;
    std::set<int> chosen;
    for (int i = 1; i <= n; ++i) {
        int m;
        std::cin >> m;

        bool match = false;
        while (m--) {
            int x;
            std::cin >> x;

            if (!match && !chosen.count(x)) {
                match = true;
                chosen.insert(x);
            }
        }

        if (!match && ans == -1) ans = i;
    }

    if (ans == -1) {
        std::cout << "OPTIMAL\n";
    } else {
        std::cout << "IMPROVE\n";

        int x = 1;
        while (chosen.count(x)) ++x;
        std::cout << ans << " " << x << "\n";
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