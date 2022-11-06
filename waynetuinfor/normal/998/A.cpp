#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < (1 << n) - 1; ++i) {
        int s = 0;
        for (int j = 0; j < n; ++j) if (i >> j & 1) s += a[j];
        if (s != accumulate(a.begin(), a.end(), 0) - s) {
            printf("%d\n", __builtin_popcount(i));
            for (int j = 0; j < n; ++j) if (i >> j & 1) printf("%d ", j + 1);
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}