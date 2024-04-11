#include <bits/stdc++.h>
template<typename T>
std::vector<T> operator*(const std::vector<T>& da, const std::vector<T>& db) {
    std::vector<T> dc(da.size() + db.size() - 1);
    std::merge(da.begin() + 1, da.end(), db.begin() + 1, db.end(), dc.begin() + 1, std::greater<T>());
    return dc;
}
constexpr int Nmax = 1e6;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, K;
    std::cin >> N >> K;
    std::vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> p[i];
        --p[i];
    }
    std::vector<int> f(N + 1);
    std::vector<bool> dead(N);
    for (int i = 0; i < N; ++i) {
        if (dead[i]) continue;
        int sz = 0;
        for (int j = i; !dead[j]; dead[j] = true, j = p[j], ++sz);
        ++f[sz];
    }
    std::bitset<Nmax> can;
    can[0] = 1;
    std::vector<std::vector<int>> dpmax;
    std::priority_queue<std::pair<int, int>> pq;
    for (int k = 1; k <= N; ++k) {
        if (f[k] == 0) continue;
        int sum = 0;
        for (int x = 1; sum + x <= f[k]; sum += x, x *= 2) {
            can |= can << (x * k);
        }
        can |= can << ((f[k] - sum) * k);
        std::vector<int> d(k + 1);
        for (int l = 1; 2 * l <= k; ++l) {
            d[l] = 2;
        }
        if (k % 2) {
            d[(k + 1) / 2] = 1;
        }
        std::vector<int> pow = {0};
        for (int p = f[k]; p > 0; p >>= 1) {
            if (p & 1) {
                pow = pow * d;
            }
            d = d * d;
        }
        pq.emplace(-k * f[k], dpmax.size());
        dpmax.push_back(std::move(pow));
    }
    while (pq.size() > 1) {
        auto [x, i] = pq.top();
        pq.pop();
        auto [y, j] = pq.top();
        pq.pop();
        dpmax[i] = dpmax[i] * dpmax[j];
        pq.emplace(x + y, i);
    }
    auto& resmax = dpmax[pq.top().second];
    std::partial_sum(resmax.begin(), resmax.end(), resmax.begin());
    std::cout << (can[K] ? K : K + 1) << ' ' << resmax[K] << '\n';
    exit(0);
}