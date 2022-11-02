#include <iostream>
#include <set>

void solve() {
    int n, r;
    std::cin >> n >> r;

    std::set<int> s;
    while (n--) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    int ans = 0;
    int d = 0;

    while (!s.empty()) {
        ++ans;
        s.erase(--s.end());
        d += r;

        while (!s.empty() &&
               *s.begin() <= d) {
            s.erase(s.begin());
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}