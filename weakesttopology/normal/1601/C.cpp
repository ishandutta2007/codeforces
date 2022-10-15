#include <bits/stdc++.h>
template<typename T>
int64_t merge_sort(T *v, T *aux, int l, int r) {
    if (r <= l + 1) return 0;
    int m = (l + r) / 2;
    int64_t res = merge_sort(v, aux, l, m) + merge_sort(v, aux, m, r);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        aux[k++] = v[i] <= v[j] ? v[i++] : (res += m - i, v[j++]);
    }
    while (i < m) aux[k++] = v[i++];
    while (j < r) aux[k++] = v[j++];
    while (l < r) {
        v[l] = aux[l];
        ++l;
    }
    return res;
}
template<typename T>
int64_t count_inversions(std::vector<T> v) {
    std::vector<T> aux(v.size());
    return merge_sort(v.data(), aux.data(), 0, v.size());
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        std::cin >> N >> M;
        std::vector<int> a(N), b(M);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        for (int j = 0; j < M; ++j) {
            std::cin >> b[j];
        }
        a.insert(a.begin(), 0);
        ++N;
        std::sort(b.begin(), b.end());
        std::vector<std::vector<int>> J(N);
        auto solve = [&](auto &self, int lb, int rb, int la, int ra) -> void {
            if (rb <= lb) return;
            int m = (lb + rb) / 2;
            int sum = 0, min = std::numeric_limits<int>::max(), opt;
            for (int i = la; i < ra; ++i) {
                sum += a[i] < b[m] ? -1 : a[i] > b[m] ? +1 : 0;
                if (sum < min) {
                    min = sum;
                    opt = i;
                }
            }
            J[opt].push_back(m);
            self(self, lb, m, la, opt + 1);
            self(self, m + 1, rb, opt, ra);
        };
        solve(solve, 0, M, 0, N);
        std::vector<int> c;
        for (int i = 0; i < N; ++i) {
            std::sort(J[i].begin(), J[i].end());
            c.push_back(a[i]);
            for (auto j : J[i]) {
                c.push_back(b[j]);
            }
        }
        std::cout << count_inversions(c) << '\n';
    }
    exit(0);
}