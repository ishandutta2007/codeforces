#include <iostream>
#include <set>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::set<int> s;
    while (n--) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    int ans = -1;
    while (m--) {
        int x;
        std::cin >> x;
        if (s.count(x)) ans = x;
    }

    if (ans == -1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n1 " << ans << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}