#include <bits/stdc++.h>
template<typename Iterator>
std::vector<int> prefix_function(Iterator first, Iterator last) {
    int N = last - first;
    std::vector<int> p(N + 1, 0);
    for (int len = 2; len <= N; ++len) {
        int x = p[len - 1];
        while (x && first[len - 1] != first[x]) x = p[x];
        if (first[len - 1] == first[x]) ++x;
        p[len] = x;
    }
    return p;
}
struct dbf_t {
    int N, K;
    std::vector<int> log;
    std::vector<std::vector<int>> p, rank;
    template<typename Iterator>
    dbf_t(Iterator first, Iterator last) : N(last - first), K(1), log(N + 1), p(1, std::vector<int>(N)), rank(p) {
        for (int n = 2; n <= N; ++n) {
            log[n] = 1 + log[n >> 1];
        }
        std::iota(p[0].begin(), p[0].end(), 0);
        std::sort(p[0].begin(), p[0].end(), [&](int i, int j) { return first[i] < first[j]; });
        for (int i = 1; i < N; ++i) {
            rank[0][p[0][i]] = rank[0][p[0][i - 1]] + (first[p[0][i]] != first[p[0][i - 1]]);
        }
        std::vector<int> cnt(N), tmp(N);
        for (int k = 0; (1 << k) < N; ++k, ++K) {
            p.emplace_back(N);
            rank.emplace_back(N);
            for (int i = 0; i < N; ++i) {
                tmp[N - 1 - i] = (p[k][i] + N - (1 << k)) % N;
                ++cnt[rank[k][p[k][i]]];
            }
            std::partial_sum(cnt.begin(), cnt.end(), cnt.begin());
            for (auto i : tmp) {
                p[k + 1][--cnt[rank[k][i]]] = i;
            }
            std::fill(cnt.begin(), cnt.end(), 0);
            auto key = [&](int i) {
                return std::pair(rank[k][i], rank[k][(i + (1 << k)) % N]);
            };
            for (int i = 1; i < N; ++i) {
                rank[k + 1][p[k + 1][i]] = rank[k + 1][p[k + 1][i - 1]] + (key(p[k + 1][i]) != key(p[k + 1][i - 1]));
            }
        }
    }
    std::pair<int, int> key(int i, int len) const {
        if (len == 0) return {-1, -1};
        int k = log[len];
        return std::pair(rank[k][i], rank[k][(i + len - (1 << k)) % N]);
    };
    bool cmp(std::array<int, 2> S, std::array<int, 2> T) const {
        int lenS = S[1] - S[0], lenT = T[1] - T[0], min = std::min(lenS, lenT);
        auto keyS = key(S[0], min), keyT = key(T[0], min);
        return keyS != keyT ? keyS < keyT : lenS < lenT;
    }
    // cyclic lcp (assumes cyclic permutations starting from i and j are not equal)
    int lcp_query(int i, int j) const {
        int len = 0;
        for (int k = K - 1; k >= 0; --k) {
            if (rank[k][i] == rank[k][j]) {
                int p = 1 << k;
                len += p;
                i = (i + p) % N;
                j = (j + p) % N;
            }
        }
        return len;
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string S, T;
    std::cin >> S >> T;
    auto R = T + '#' + S;
    auto p = prefix_function(R.begin(), R.end());
    int N = T.size();
    std::vector<std::vector<int>> E(N + 1);
    for (int u = 1; u <= N; ++u) {
        E[p[u]].push_back(u);
    }
    T.push_back(0);
    dbf_t dbf(T.begin(), T.end());
    const auto &sa = dbf.p.back(), &pos = dbf.rank.back();
    std::set<int> set;
    std::vector<int64_t> f(N + 1);
    std::vector<std::array<int64_t, 26>> fc(N + 1);
    auto dfs = [&](auto& self, int u) -> void {
        auto iter = set.insert(pos[u]).first;
        if (u < N) {
            int max = 0;
            if (std::next(iter) != set.end()) {
                max = std::max(max, dbf.lcp_query(u, sa[*std::next(iter)]));
            }
            if (iter != set.begin()) {
                max = std::max(max, dbf.lcp_query(u, sa[*std::prev(iter)]));
            }
            int add = N - u - max;
            f[u] += add;
            fc[u][T[u] - 'a'] += add;
        }
        for (auto v : E[u]) {
            f[v] = f[u];
            fc[v] = fc[u];
            self(self, v);
        }
        set.erase(iter);
    };
    dfs(dfs, 0);
    int64_t ans = 0;
    for (int k = 1; k <= S.size(); ++k) {
        int u = p[N + 1 + k];
        if (u == k) u = p[u];
        ans += f[u] + !!u;
        if (k < S.size()) {
            ans -= fc[u][S[k] - 'a'];
        }
    }
    std::cout << ans << '\n';
    exit(0);
}