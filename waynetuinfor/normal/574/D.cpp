#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int h[maxn], ans[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
    for (int i = 1; i <= n; ++i) {
        ans[i] = min(h[i], i);
        ans[i] = min(ans[i], ans[i - 1] + 1);
    }
    for (int i = n; i >= 1; --i) {
        ans[i] = min(ans[i], n - i + 1);
        ans[i] = min(ans[i], ans[i + 1] + 1);
    }
    int t = 0;
    for (int i = 1; i <= n; ++i) t = max(t, ans[i]);
    printf("%d\n", t);
    return 0;
}
 // h[i][j] = min(h[i - 1][j - 1], h[i][j - 1] - 1, h[i + 1][j - 1]);
 // h[i - 1][j - 1] = min(h[i - 2][j - 2], h[i - 1][j - 2] - 1, h[i][j - 2]);
 //