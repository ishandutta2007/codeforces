#include <bits/stdc++.h>

using i64 = long long;

const int N = 2E5 + 5;

int sum[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, q;
    std::cin >> n >> k >> q;

    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        ++sum[l];
        --sum[r + 1];
    }

    std::vector<int> v;
    for (int i = 1; i < N; i++) {
        sum[i] += sum[i - 1];

        if (sum[i] >= k) {
            v.push_back(i);
        }
    }

    while (q--) {
        int l, r;
        std::cin >> l >> r;

        std::cout << lower_bound(v.begin(), v.end(), r + 1) - lower_bound(v.begin(), v.end(), l) << "\n";
    }

    return 0;
}