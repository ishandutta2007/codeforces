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
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (a[i][j] != b[i][j]) {
                a[i][j] ^= 1;
                a[i + 1][j] ^= 1;
                a[i][j + 1] ^= 1;
                a[i + 1][j + 1] ^= 1;
            }
        }
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            ans &= a[i][j] == b[i][j];
    }
    if (ans) puts("Yes");
    else puts("No");
}