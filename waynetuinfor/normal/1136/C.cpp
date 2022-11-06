#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
int a[maxn][maxn], b[maxn][maxn];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            scanf("%d", &b[i][j]);
    }
    for (int s = 0; s < n + m; ++s) {
        multiset<int> x, y;
        for (int i = 0; i < n; ++i) {
            if (s - i >= 0 && s - i < m) {
                x.insert(a[i][s - i]);
                y.insert(b[i][s - i]);
            }
        }
        if (x != y) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}