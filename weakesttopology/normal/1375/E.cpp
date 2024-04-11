#include "bits/stdc++.h"
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> I(N);
    std::iota(I.begin(), I.end(), 0);
    std::stable_sort(I.begin(), I.end(), [&](int i, int j) { return a[i] < a[j]; });
    std::vector<int> p(N), pos(N);
    for (int i = 0; i < N; ++i) {
        p[I[i]] = i;
        pos[i] = I[i];
    }
    int M = 0;
    std::vector<int> u, v;
    auto apply = [&](int i, int j) {
        if (i > j) std::swap(i, j);
        ++M;
        u.push_back(i);
        v.push_back(j);
        std::swap(p[i], p[j]);
        std::swap(pos[p[i]], pos[p[j]]);
    };
    for (int i = N - 1; i >= 0; --i) {
        if (p[i] == i) continue;
        for (int j = p[i] + 1; j <= i; ++j) {
            apply(pos[j], i);
        }
    }
    assert(std::is_sorted(p.begin(), p.end()));
    std::cout << M << '\n';
    for (int j = 0; j < M; ++j) {
        std::cout << u[j] + 1 << ' ' << v[j] + 1 << '\n';
    }
    exit(0);
}