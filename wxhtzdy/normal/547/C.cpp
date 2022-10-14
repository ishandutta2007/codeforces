#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e5 + 5;

bool prime[N];

std::vector<std::vector<int>> divs(N);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i < N; i++) prime[i] = true;
    for (int i = 2; i < N; i++) {
        if (!prime[i]) continue;
        for (int j = i; j < N; j += i) {
            prime[j] = false;
            divs[j].push_back(i);
        }
    }

    i64 ans = 0;
    std::vector<int> cnt(N);
    auto add = [&](int x, int v) {
        int s = (int) divs[x].size();
        for (int mask = 1; mask < (1 << s); mask++) {
            int p = 1;
            for (int i = 0; i < s; i++) {
                if (mask >> i & 1) p *= divs[x][i];
            }
            int coeff = (__builtin_popcount(mask) % 2 == 1 ? 1 : -1) * v;
            if (v == -1) {
                cnt[p] -= 1;
            }
            ans += cnt[p] * coeff;
            if (v == +1) {
                cnt[p] += 1;
            }
        }
    };

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> act(n);
    int tsz = 0;
    while (q--) {
        int i;
        std::cin >> i;
        --i;

        if (act[i]) {
            add(a[i], -1);
            tsz--;
        } else {
            add(a[i], 1);
            tsz++;
        }
        act[i] ^= 1;

        std::cout << tsz * 1LL * (tsz - 1) / 2 - ans << "\n";
    }

    return 0;
}