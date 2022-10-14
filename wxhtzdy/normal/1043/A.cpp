#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(a, a + n);

    for (int k = a[n - 1];; k++) {
        int sum[2] = {};

        for (int i = 0; i < n; i++)
            sum[0] += a[i], sum[1] += k - a[i];

        if (sum[1] > sum[0]) {
            std::cout << k;
            break;
        }
    }

    return 0;
}