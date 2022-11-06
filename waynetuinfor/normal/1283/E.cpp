#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
int x[kN], cnt[kN], g[kN];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        ++cnt[x[i]];
    }
    sort(x, x + n);
    int ans = 0;
    for (int i = 0, j = 0; i < n; i = j) {
        for (j = i; j < n && x[j] - x[i] <= 2; ++j);
        ans++;
    }
    for (int i = 0; i < n; ++i) {
        if (!g[x[i] - 1]) {
            g[x[i] - 1] = 1;
        } else if (!g[x[i]]) {
            g[x[i]] = 1;
        } else {
            g[x[i] + 1] = 1;
        }
    }
    printf("%d %d\n", ans, accumulate(g, g + kN, 0));
}