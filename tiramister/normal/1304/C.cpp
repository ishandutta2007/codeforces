#include <iostream>
#include <vector>

void solve() {
    int n, m;
    std::cin >> n >> m;

    int ml = m, mr = m, mt = 0;
    bool judge = true;
    while (n--) {
        int t, l, r;
        std::cin >> t >> l >> r;

        int dt = t - mt;
        ml -= dt, mr += dt;
        ml = std::max(ml, l);
        mr = std::min(mr, r);
        mt = t;

        if (mr < ml) judge = false;
    }

    std::cout << (judge ? "YES" : "NO") << std::endl;
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