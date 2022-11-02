#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <cassert>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int INF = 1e9;

void print(int cnt, int i, int j) {
    std::cout << cnt << " " << i + 1 << " " << j + 1 << "\n";
}

void solve() {
    int n, k, v;
    std::cin >> n >> k >> v;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    if (std::accumulate(xs.begin(), xs.end(), 0) < v) {
        std::cout << "NO" << std::endl;
        return;
    }

    // used: 1, unused: 0, impossible: -1
    auto dp = vec(n + 1, vec(k, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        // unused
        for (int j = 0; j < k; ++j) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = 0;
        }

        // used
        int y = xs[i] % k;
        for (int j = 0; j < k; ++j) {
            if (dp[i][j] == -1) continue;
            int nj = (j + y) % k;
            dp[i + 1][nj] = 1;
        }
    }

    if (dp[n][v % k] == -1) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::cout << "YES" << std::endl;

    std::vector<int> idxs;
    {
        int u = v % k;
        for (int i = n; i > 0; --i) {
            if (dp[i][u] == 1) {
                idxs.push_back(i - 1);
                u = (u - xs[i - 1] % k + k) % k;
            }
        }
    }

    std::vector<int> nidxs;
    {
        std::set<int> used(idxs.begin(), idxs.end());
        for (int i = 0; i < n; ++i) {
            if (!used.count(i)) nidxs.push_back(i);
        }
    }

    if (idxs.empty() || nidxs.empty()) {
        for (int i = 0; i < n - 1; ++i) {
            print(INF, i, n - 1);
            xs[n - 1] += xs[i];
            xs[i] = 0;
        }

        // goal and supply
        int i = (idxs.empty() ? 0 : n - 1);
        int j = n - 1 - i;

        int d = (xs[i] - v) / k;
        if (d > 0) {
            print(d, i, j);
        } else if (d < 0) {
            print(-d, j, i);
        }

        return;
    }

    while (idxs.size() > 1) {
        int i = idxs.back();
        idxs.pop_back();

        print(INF, i, idxs.front());

        xs[idxs.front()] += xs[i];
        xs[i] = 0;
    }

    while (nidxs.size() > 1) {
        int i = nidxs.back();
        nidxs.pop_back();

        print(INF, i, nidxs.front());

        xs[nidxs.front()] += xs[i];
        xs[i] = 0;
    }

    int i = idxs.front(), j = nidxs.front();
    int d = (v - xs[i]) / k;

    if (d > 0) {
        print(d, j, i);
    } else if (d < 0) {
        print(-d, i, j);
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}