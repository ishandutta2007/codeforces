#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cout << (char) (i % k + 'a');
    }

    return 0;
}