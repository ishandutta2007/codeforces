#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int ans[maxn][maxn];

int main() {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);
    if (a != 1 && b != 1) return 0 * puts("NO");
    if (a == 1 && b == 1 && (n == 2 || n == 3)) return 0 * puts("NO");
    puts("YES");
    bool inv = false;
    if (a == 1) swap(a, b), inv = true;    
    for (int i = a; i < n; ++i) ans[i][i + 1] = ans[i + 1][i] = 1;
    if (inv) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) if (i != j) ans[i][j] = 1 - ans[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) printf("%d", ans[i][j]);
        puts("");
    }
    return 0;
}