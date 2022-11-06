#include <bits/stdc++.h>

const int maxn = 50 + 5;
int a[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    std::vector<int> o(n); iota(o.begin(), o.end(), 0);
    std::sort(o.begin(), o.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    for (int i = n - 1; i >= 0 && k; --i) {
        for (int j = i; j >= 0 && k; --j) {
            printf("%d ", n - i);
            for (int z = n - 1; z > i; --z) printf("%d ", a[o[z]]);
            printf("%d\n", a[o[j]]);
            --k;
        }
    }
    return 0;
}