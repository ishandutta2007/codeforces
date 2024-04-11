#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y; scanf("%d%d%d", &n, &x, &y);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = i - x; j <= i + y; ++j) 
            ok &= j < 0 || j >= n || i == j || a[i] < a[j];
        if (ok) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
}