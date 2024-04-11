#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

template <class T>
struct SegmentTree {
    int length;
    std::vector<T> dat;
    T unit;

    explicit SegmentTree(int n, T unit)
        : length(1), unit(unit) {
        while (length < n) length <<= 1;
        dat.assign(length + 1, unit);
    }

    T query(int idx) {
        T sum = 0;
        ++idx;
        idx = std::min(idx, length);
        while (idx > 0) {
            sum ^= dat[idx];
            idx -= (idx & (-idx));
        }
        return sum;
    }

    void update(int idx, T elem) {
        ++idx;
        idx = std::max(idx, 1);
        while (idx <= length) {
            dat[idx] ^= elem;
            idx += (idx & (-idx));
        }
    }
};

constexpr int X = 1 << 25;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    SegmentTree<char> seg(X, 0);

    std::vector<int> idxs;
    int ans = 0;
    for (int k = 0; k < 25; ++k) {
        int b = 1 << k;
        char cnt = 0;
        for (auto x : xs) {
            auto y = x % (1 << (k + 1));

            for (int i = 1; i <= 4; ++i) {
                cnt ^= seg.query(b * i - y - 1);
            }

            seg.update(y, 1);
            idxs.push_back(y);
        }
        ans |= (cnt << k);

        for (auto i : idxs) seg.update(i, 1);
        idxs.clear();
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}