#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    {
        int v;
        std::cin >> v;
        --n;
    }

    int prev = n + 1, cnt = 0, pcnt = 1, ans = 0;
    while (n--) {
        int v;
        std::cin >> v;
        --v;
        ++cnt;

        if (v < prev) {
            if (--pcnt == 0) {
                ++ans;
                pcnt = cnt;
                cnt = 0;
            }
        }
        prev = v;
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