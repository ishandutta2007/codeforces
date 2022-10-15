#include <bits/stdc++.h>
bool dominates(std::pair<int, int> p, std::pair<int, int> q) {
    return p.first >= q.first && p.second >= q.second;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, Q;
    std::cin >> N >> M >> Q;
    std::map<std::pair<int, int>, int> add;
    for (int q = 0; q < Q; ++q) {
        int a, b;
        std::cin >> a >> b;
        add[std::pair(a, b)] = 1;
    }
    std::set<std::pair<int, int>> q, nq;
    auto insert = [&](int a, int b) {
        std::pair<int, int> p(a, b);
        auto iter = nq.insert(p).first;
        if (std::next(iter) != nq.end() && dominates(*std::next(iter), p)) {
            nq.erase(iter);
        } else {
            while (iter != nq.begin() && dominates(p, *std::prev(iter))) {
                nq.erase(std::prev(iter));
            }
        }
    };
    std::pair<int, int> s(1, 1), t(N, M);
    q.insert(s);
    int ans = 0;
    while (!q.count(t)) {
        ++ans;
        for (auto p : q) {
            auto [a, b] = p;
            int s = a + b + add[p];
            insert(std::min(N, s), b);
            insert(a, std::min(M, s));
        }
        q.clear();
        std::swap(q, nq);
    }
    std::cout << ans << '\n';
    exit(0);
}