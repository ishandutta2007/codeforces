#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint k;
    std::cin >> n >> k;

    lint l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;

    if (l1 > l2) {
        std::swap(l1, l2);
        std::swap(r1, r2);
    }

    lint ans = 0;

    if (l2 <= r1) {
        lint len = std::max(r1, r2) - std::min(l1, l2),
             com = std::min(r1, r2) - std::max(l1, l2);
        lint gain = len - com;
        k -= com * n;
        k = std::max(k, 0LL);

        while (n--) {
            lint step = std::min(k, gain);
            ans += step;
            k -= step;
        }
        ans += k * 2;

    } else {
        lint gain = r2 - l1,
             cost = l2 - r1;

        {
            ans += cost;
            lint step = std::min(gain, k);
            ans += step;
            k -= step;
            --n;
        }

        lint pcost = k * 2;

        lint ncost = 0;
        while (n--) {
            ncost += cost;
            lint step = std::min(gain, k);
            ncost += step;
            k -= step;
            pcost = std::min(pcost, ncost + k * 2);
        }

        ans += pcost;
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