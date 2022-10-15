#include <bits/stdc++.h>
template<typename T>
using pqmin = std::priority_queue<T, std::vector<T>, std::greater<T>>;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, T;
    std::cin >> N >> T;
    std::vector<int> a(N), t(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i] >> t[i];
    }
    std::vector<int> I(N);
    std::iota(I.begin(), I.end(), 0);
    std::sort(I.begin(), I.end(), [&](int i, int j) { return t[i] < t[j]; });
    pqmin<std::tuple<int, int, int>> pqmin;
    int cost = 0;
    for (auto i : I) {
        cost += t[i];
        if (cost > T) break;
        pqmin.emplace(a[i], -t[i], i);
        if (!pqmin.empty() && pqmin.size() > std::get<0>(pqmin.top())) {
            cost += std::get<1>(pqmin.top());
            pqmin.pop();
        }
    }
    std::cout << pqmin.size() << '\n';
    std::cout << pqmin.size() << '\n';
    while (!pqmin.empty()) {
        std::cout << std::get<2>(pqmin.top()) + 1 << ' ';
        pqmin.pop();
    }
    std::cout << '\n';
    exit(0);
}