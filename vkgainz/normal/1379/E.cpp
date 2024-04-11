#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto ok = [&](int n, int k) {
        if (n % 2 == 0)
            return false;
        if (n == 1)
            return k == 0;
        bool pw2 = ((n + 1) & n) == 0;
        if (pw2 && k == 1)
            return false;
        if (!pw2 && k == 0)
            return false;
        if (k > (n - 3) / 2)
            return false;
        if (n == 9 && k == 2)
            return false;
        return true;
    };
    int n, k;
    std::cin >> n >> k;
    if (!ok(n, k)) {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    int cnt = 0;
    auto range = [&](int n) {
        std::vector<std::pair<int, int>> a;
        bool pw2 = ((n + 1) & n) == 0;
        if (n == 9) {
            a.emplace_back(1, 1);
            a.emplace_back(3, 3);
        } else if (pw2) {
            a.emplace_back(0, 0);
            if (n > 3)
                a.emplace_back(2, (n - 3) / 2);
        } else {
            a.emplace_back(1, (n - 3) / 2);
        }
        return a;
    };
    auto get = [&](int n, int l, int k) {
        int r = n - l - 1;
        int g = (2 * l <= r);
        k -= g;
        auto a = range(l);
        auto b = range(r);
        int x = -1, y = -1;
        for (auto [l1, r1] : a) {
            for (auto [l2, r2] : b) {
                if (l1 + l2 <= k && k <= r1 + r2) {
                    if (k <= r1 + l2) {
                        y = l2;
                        x = k - y;
                    } else {
                        x = r1;
                        y = k - x;
                    }
                }
            }
        }
        return std::make_pair(x, y);
    };
    int res = 0;
    std::function<void(int, int, int)> build = [&](int n, int k, int p) {
        std::cout << p << " ";
        int x = ++cnt;
        if (n == 1)
            return;
        for (int l = 1; ; l += 2) {
            auto [a, b] = get(n, l, k);
            if (a == -1)
                continue;
            assert(l <= n - l - 1);
            res += (2 * l <= n - l - 1);
            build(l, a, x);
            build(n - l - 1, b, x);
            return;
        }
    };
    build(n, k, 0);
    assert(res == k);
    std::cout << "\n";
    return 0;
}