#include <iostream>

using lint = long long;

lint calc(lint n) {
    return n * (n + 1) / 2 * 3 - n;
}

void solve() {
    lint n;
    std::cin >> n;

    int ans = 0;
    while (true) {
        lint ok = 0, ng = n;

        while (ng - ok > 1) {
            lint mid = (ok + ng) / 2;
            if (calc(mid) <= n) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        if (ok == 0) break;

        ++ans;
        n -= calc(ok);
    }

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