#include <iostream>
#include <vector>
#include <set>
#include <bitset>

using lint = long long;

void brute() {
    int n;
    std::cin >> n;

    std::set<int> s;
    for (int i = 0; i < n; ++i) {
        int l;
        for (l = 1; s.count(l); ++l) {}

        int r;
        for (r = l + 1; s.count(r) || s.count(l ^ r); ++r) {}

        std::cout << l << "\n"
                  << r << "\n"
                  << (l ^ r) << "\n";

        s.insert(l);
        s.insert(r);
        s.insert(l ^ r);
    }
}

const std::vector<std::vector<int>>
    ord{{0, 1, 2, 3},
        {0, 2, 3, 1},
        {0, 3, 1, 2}};

void solve() {
    lint n;
    std::cin >> n;
    --n;

    int k;
    for (k = 0;; ++k) {
        if (n < (1LL << (k * 2)) * 3) break;
        n -= (1LL << (k * 2)) * 3;
    }

    int pat = n % 3;
    lint ans = lint(pat + 1) << (k * 2);

    n /= 3;
    for (int i = 0; i < k; ++i) {
        ans += lint(ord[pat][n % 4]) << (i * 2);
        n /= 4;
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    // brute();

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}