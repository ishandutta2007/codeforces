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
constexpr int magic = 350;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    int B = (N + magic - 1) / magic;
    std::vector bit(B, BIT<int64_t>(N));
    std::vector<std::set<int>> occ(N, {-1, N});
    std::vector<int> a(N), prev(N + 1, -1);
    auto update = [&](int i, int sgn) {
        int x = a[i];
        auto iter = occ[x].insert(i).first;
        int l = *std::prev(iter), r = *std::next(iter);
        int bi = i / magic;
        if (l != -1) {
            bit[bi].update(l, sgn * (i - l));
        }
        if (r != N) {
            int br = r / magic;
            bit[br].update(i, sgn * (r - i));
            if (l != -1) {
                bit[br].update(l, -sgn * (r - l));
            }
        }
        if (sgn == -1) {
            prev[r] = l;
            occ[x].erase(iter);
        } else {
            prev[i] = l;
            prev[r] = i;
        }
    };
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
        --a[i];
        update(i, +1);
    }
    for (int j = 0; j < M; ++j) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int i;
            std::cin >> i;
            --i;
            update(i, -1);
            std::cin >> a[i];
            --a[i];
            update(i, +1);
        } else {
            int l, r;
            std::cin >> l >> r;
            --l;
            int bl = l / magic, br = r / magic;
            int64_t ans = 0;
            for (int b = bl + 1; b < br; ++b) {
                ans += bit[b].query(l, r);
            }
            for (int i = l; i / magic == bl && i < r; ++i) {
                if (prev[i] >= l) {
                    ans += i - prev[i];
                }
            }
            if (bl != br) {
                for (int i = magic * br; i < r; ++i) {
                    if (prev[i] >= l) {
                        ans += i - prev[i];
                    }
                }
            }
            std::cout << ans << '\n';
        }
    }
    exit(0);
}