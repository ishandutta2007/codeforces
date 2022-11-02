#include <iostream>
#include <vector>
#include <string>
#include <chrono>

struct Random {
    using ulint = uint64_t;
    ulint x;

    explicit Random() {
        x = std::chrono::steady_clock::now()
                .time_since_epoch()
                .count();
    }

    ulint next() {
        x ^= (x << 13);
        x ^= (x >> 7);
        x ^= (x << 17);
        return x;
    }
};

const std::vector<std::string> results{"FIRST", "EQUAL", "SECOND"};

int query(const std::vector<int>& xs,
          const std::vector<int>& ys) {
    std::cout << "? " << xs.size() << " " << ys.size() << std::endl;

    for (auto x : xs) std::cout << x + 1 << " ";
    std::cout << std::endl;

    for (auto y : ys) std::cout << y + 1 << " ";
    std::cout << std::endl;

    std::string res;
    std::cin >> res;

    for (int i = 0; i < 3; ++i) {
        if (res == results[i]) return i;
    }
    std::exit(0);
}

void answer(int x) {
    std::cout << "! " << x + 1 << std::endl;
}

constexpr int N = 25;
Random rng;

void solve() {
    int n, k;
    std::cin >> n >> k;

    int x = 0;
    {
        for (int i = 0; i < N; ++i) {
            int nx = x;
            while (nx == x) {
                nx = rng.next() % n;
            }

            int res = query({x}, {nx});
            if (res == 2) x = nx;
        }
    }

    std::vector<int> stones{x};

    std::vector<int> cands;
    cands.reserve(n - 1);
    for (int i = 0; i < n; ++i) {
        if (i != x) cands.push_back(i);
    }

    while ((int)cands.size() > 1) {
        int m = std::min(stones.size(), cands.size() / 2);

        std::vector<int>
            xs(stones.begin(), stones.begin() + m),
            ys(cands.begin(), cands.begin() + m);

        int res = query(xs, ys);

        if (res == 0) {
            cands = ys;
        } else {
            cands.erase(cands.begin(), cands.begin() + m);
            std::copy(ys.begin(), ys.end(), std::back_inserter(stones));
        }
    }

    answer(cands.front());
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}