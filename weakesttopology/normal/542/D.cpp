#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
template<typename T>
struct VectorCmp {
    bool operator()(const std::vector<T>& a, const std::vector<T>& b) const {
        return a.size() > b.size();
    }
};
int main() {
    int64_t A;
    std::cin >> A;
    if (A == 1) {
        std::cout << "1\n";
        exit(0);
    }
    using pii = std::pair<int64_t, int64_t>;
    std::unordered_map<int64_t, std::vector<pii>> P;
    auto test = [&](int64_t x) {
        if (x <= 1) return;
        int64_t p = 2;
        while (p * p <= x && x % p) ++p;
        if (p * p > x) {
            P[x].emplace_back(x + 1, 1);
        } else {
            int64_t w = p;
            while (w < x) w *= p;
            if (w == x) {
                P[p].emplace_back(w + 1, 1);
            }
        }
    };
    for (int64_t d = 1; d * d <= A; ++d) {
        if (A % d == 0) {
            test(d - 1);
            test(A / d - 1);
        }
    }
    std::priority_queue<std::vector<pii>, std::vector<std::vector<pii>>, VectorCmp<pii>> pq;
    for (auto& [p, W] : P) {
        std::sort(W.begin(), W.end());
        W.erase(std::unique(W.begin(), W.end()), W.end());
        pq.emplace(move(W));
    }
    int64_t ans = 0;
    if (!pq.empty()) {
        while (pq.size() > 1) {
            auto U = move(pq.top());
            pq.pop();
            auto V = move(pq.top());
            pq.pop();
            std::vector<std::pair<int64_t, int64_t>> W;
            W.insert(W.end(), U.begin(), U.end());
            W.insert(W.end(), V.begin(), V.end());
            for (auto [x, k] : U) {
                for (auto [y, l] : V) {
                    if ((A / x) % y == 0) {
                        W.emplace_back(x * y, k * l);
                    }
                }
            }
            std::sort(W.begin(), W.end());
            for (auto iter = W.begin(); iter != W.end();) {
                auto niter = iter + 1;
                while (niter != W.end() && niter->first == iter->first) {
                    iter->second += niter->second;
                    niter->second = 0;
                    ++niter;
                }
                iter = niter;
            }
            W.erase(std::remove_if(W.begin(), W.end(), [](auto p) { return p.second == 0; }), W.end());
            pq.push(move(W));
        }
        for (auto [x, k] : pq.top()) {
            if (x == A) {
                ans = k;
                break;
            }
        }
    }
    std::cout << ans << '\n';
    exit(0);
}