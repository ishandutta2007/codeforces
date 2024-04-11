#include <bits/stdc++.h>
template<typename T>
struct BIT {
    static int lsb(int b) { return b & -b; }
    int N, h;
    std::vector<T> ft;
    BIT(int N) : N(N), h(std::__lg(N)), ft(N + 1, T()) { }
    template<typename Iterator>
    BIT(Iterator first, Iterator last) : BIT(last - first) {
        for (int i = 1; i <= N; ++i) {
            ft[i] = first[i - 1] + ft[i - 1];
        }
        for (int i = N; i >= 1; --i) {
            ft[i] = ft[i] - ft[i - lsb(i)];
        }
    }
    T query(int p) const {
        T res = T();
        for (; p >= 1; p -= lsb(p)) {
            res = res + ft[p];
        }
        return res;
    }
    T query(int l, int r) const {
        return query(r) - query(l);
    }
    void update(int p, T value) {
        for (++p; p <= N; p += lsb(p)) {
            ft[p] = ft[p] + value;
        }
    }
    // returns first r such that pred(query(0, r + 1)) == false (N if no such r exists)
    template<typename Pred>
    int find_right(Pred&& pred) const {
        T prefix = T();
        int pos = 0;
        for (int x = h; x >= 0; --x) {
            int npos = pos + (1 << x);
            if (npos > N) continue;
            T nprefix = prefix + ft[npos];
            if (pred(nprefix)) {
                pos = npos;
                prefix = nprefix;
            }
        }
        return pos;
    }
    int lower_bound(T value) const {
        return find_right([value](T x) { return x < value; });
    }
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, Q;
        std::cin >> N >> Q;
        std::vector<int> a(N);
        for (int u = 0; u < N; ++u) {
            std::cin >> a[u];
            --a[u];
        }
        std::vector<std::vector<int>> E(N);
        for (int u = 1; u < N; ++u) {
            int p;
            std::cin >> p;
            --p;
            E[p].push_back(u);
        }
        std::vector<std::vector<int>> qs(N);
        std::vector<int> l(Q), k(Q);
        for (int q = 0; q < Q; ++q) {
            int v;
            std::cin >> v >> l[q] >> k[q];
            --v;
            qs[v].push_back(q);
        }
        std::vector<int> freq(N), cntfreq(N + 1);
        BIT<int> bit(N + 1);
        auto update = [&](int& f, int d) {
            --cntfreq[f];
            bit.update(f, -1);
            f += d;
            ++cntfreq[f];
            bit.update(f, +1);
        };
        std::vector<std::set<int>> S(N + 1);
        for (int u = 0; u < N; ++u) {
            S[0].insert(a[u]);
        }
        cntfreq[0] = N;
        std::vector<int> ans(Q);
        auto dfs = [&](auto &self, int u) -> void {
            int x = a[u];
            S[freq[x]].erase(x);
            update(freq[x], +1);
            auto iter = S[freq[x]].insert(x).first;
            for (auto q : qs[u]) {
                if (bit.query(l[q], N + 1) < k[q]) {
                    ans[q] = -1;
                    continue;
                }
                int f = bit.lower_bound(bit.query(l[q]) + k[q]);
                assert(!S[f].empty());
                ans[q] = *S[f].begin() + 1;
            }
            for (auto v : E[u]) {
                self(self, v);
            }
            S[freq[x]].erase(iter);
            update(freq[x], -1);
            S[freq[x]].insert(x);
        };
        dfs(dfs, 0);
        for (int q = 0; q < Q; ++q) {
            std::cout << ans[q] << "\n "[q + 1 < Q];
        }
    }
    exit(0);
}