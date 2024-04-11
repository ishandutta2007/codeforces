#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int x, p, k;
    std::cin >> x >> p >> k;

    std::vector<int> ps;
    for (int i = 2; i * i <= p; ++i) {
        if (p % i != 0) continue;
        ps.push_back(i);
        while (p % i == 0) p /= i;
    }
    if (p > 1) ps.push_back(p);
    int m = ps.size();

    auto count = [&](int y) {
        int ret = 0;
        for (int b = 0; b < (1 << m); ++b) {
            int q = 1, sign = 1;
            for (int i = 0; i < m; ++i) {
                if ((b >> i) & 1) {
                    q *= ps[i];
                    sign = -sign;
                }
            }
            ret += sign * y / q;
        }
        return ret;
    };

    k += count(x);

    int ok = 1 << 30, ng = 0;
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (count(mid) >= k) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    std::cout << ok << "\n";
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