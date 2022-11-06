#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, x; scanf("%d%d", &n, &x);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a.begin(), a.end(), greater<int>());
        int ans = x / a[0];
        int r = x % a[0];
        if (r == 0) {
            printf("%d\n", ans);
            continue;
        }
        if (a[0] > x) {
            bool ok = false;
            for (int i = 0; i < n; ++i) {
                if (a[i] == x) ok = true;
            }
            if (ok) printf("1\n");
            else printf("2\n");
        } else {
            printf("%d\n", (x + a[0] - 1) / a[0]);
        }
    }
}