#include "bits/stdc++.h"
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    int64_t L;
    std::cin >> N >> L;
    std::vector<int64_t> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::vector<int64_t> as;
    for (int k = 0; k < 5; ++k) {
        for (int i = 0; i < N; ++i) {
            as.emplace_back(a[i] + k * L);
        }
    }
    std::sort(as.begin(), as.end());
    std::vector<std::tuple<int64_t, int, int>> bs;
    for (int k : {0, 1}) {
        for (int i = 0; i < N; ++i) {
            bs.emplace_back(b[i] + (k + 1) * L, k, i);
        }
    }
    std::sort(bs.begin(), bs.end());
    auto check = [&](int64_t d) {
        int ptr[2] = {0, 0};
        int64_t add[2] = {L, 2 * L};
        std::vector<std::array<int, 2>> l(N), r(N);
        int e = 0;
        while (std::max(ptr[0], ptr[1]) < N) {
            int k = b[ptr[0]] + add[0] <= b[ptr[1]] + add[1] ? 0 : 1;
            int &i = ptr[k];
            while (as[e] < b[i] + add[k] - d) ++e;
            l[i][k] = e;
            ++i;
        }
        for (int k : {0, 1}) {
            int &i = ptr[k];
            while (i < N) {
                int &i = ptr[k];
                while (as[e] < b[i] + add[k] - d) ++e;
                l[i][k] = e;
                ++i;
            }
        }
        e = ptr[0] = ptr[1] = 0;
        while (std::max(ptr[0], ptr[1]) < N) {
            int k = b[ptr[0]] + add[0] <= b[ptr[1]] + add[1] ? 0 : 1;
            int &i = ptr[k];
            while (as[e] <= b[i] + add[k] + d) ++e;
            r[i][k] = e;
            ++i;
        }
        for (int k : {0, 1}) {
            int &i = ptr[k];
            while (i < N) {
                while (as[e] <= b[i] + add[k] + d) ++e;
                r[i][k] = e;
                ++i;
            }
        }
        int prefmin = 0, num_brides = 0;
        for (auto [x, k, i] : bs) {
            ++num_brides;
            prefmin = std::min(prefmin, -l[i][k] + (num_brides - 1));
            if (r[i][k] + prefmin - num_brides < 0) return false;
        }
        return true;
    };
    int64_t l = -1, r = L;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        check(m) ? r = m : l = m;
    }
    std::cout << r << '\n';
    exit(0);
}