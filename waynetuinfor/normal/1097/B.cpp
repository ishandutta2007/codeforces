#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int s = 0; s < (1 << n); ++s) {
        int deg = 0;
        for (int i = 0; i < n; ++i) {
            if (s >> i & 1) (deg += a[i]) %= 360;
            else (deg += 360 - a[i]) %= 360;
        }
        if (deg == 0) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}