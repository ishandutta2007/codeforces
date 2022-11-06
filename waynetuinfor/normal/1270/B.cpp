#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        bool ok = false;
        for (int i = 1; !ok && i < n; ++i) {
            if (abs(a[i] - a[i - 1]) >= 2) {
                puts("YES");
                printf("%d %d\n", i, i + 1);
                ok = true;
            }
        }
        if (!ok) puts("NO");
    }
}