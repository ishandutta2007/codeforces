#include <bits/stdc++.h>
std::pair<int, int> solve(std::vector<int> a, int mod) {
    int N = a.size();
    std::vector<bool> dead(N);
    for (int i = 1; i < N; ++i) {
        int d = a[i] - a[0];
        int last = a[0];
        std::vector<int> killed;
        for (int x = a[0], i = 0; i < N; x = (x + mod - d) % mod, ++i) {
            auto iter = std::lower_bound(a.begin(), a.end(), x);
            if (iter == a.end() || *iter != x) break;
            int j = iter - a.begin();
            killed.push_back(j);
            dead[j] = true;
            last = x;
        }
        for (int x = a[0], i = 0; i < N; x = (x + d) % mod, ++i) {
            auto iter = std::lower_bound(a.begin(), a.end(), x);
            if (iter == a.end() || *iter != x) break;
            int j = iter - a.begin();
            killed.push_back(j);
            dead[j] = true;
        }
        int cnt = 0;
        for (auto j : killed) {
            cnt += dead[j];
            dead[j] = false;
        }
        if (cnt == N) {
            return {last, d};
        }
    }
    return {-1, -1};
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int mod, N;
    std::cin >> mod >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    if (N == 1) {
        std::cout << a[0] << " 0\n";
        exit(0);
    }
    int K = mod - N;
    if (2 <= K && K < N) {
        std::vector<bool> on(mod);
        for (auto x : a) {
            on[x] = true;
        }
        std::vector<int> b;
        for (int x = 0; x < mod; ++x) {
            if (!on[x]) {
                b.push_back(x);
            }
        }
        auto [x, d] = solve(b, mod);
        if (x == -1) {
            std::cout << "-1\n";
        } else {
            x = (x + 1LL * K * d) % mod;
            std::cout << x << ' ' << d << '\n';
        }
    } else {
        auto [x, d] = solve(a, mod);
        if (x == -1) {
            std::cout << "-1\n";
        } else {
            std::cout << x << ' ' << d << '\n';
        }
    }
    exit(0);
}