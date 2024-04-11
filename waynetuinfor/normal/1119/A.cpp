#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int c[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] != c[n - 1])
            ans = max(ans, n - 1 - i);
    }
    for (int i = 0; i < n; ++i) {
        if (c[i] != c[0]) 
            ans = max(ans, i);
    }
    printf("%d\n", ans);
}