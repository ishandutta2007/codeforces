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
        int N;
        std::cin >> N;
        std::vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            std::cin >> a[i];
        }
        bool good = count_inversions(a) % 2 == 0;
        std::sort(a.begin(), a.end());
        for (int i = 0; i + 1 < N; ++i) {
            if (a[i] == a[i + 1]) {
                good = true;
                break;
            }
        }
        std::cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}