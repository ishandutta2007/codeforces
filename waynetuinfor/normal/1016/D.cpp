#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn], b[maxn];
int c[maxn][maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int x = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), x ^= a[i];
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]), x ^= b[i];
    if (x != 0) {
        puts("NO");
        return 0;
    }
    x = 0;
    for (int i = 0; i < n - 1; ++i) 
        for (int j = 0; j < m - 1; ++j) 
            c[i][j] = 0;
    for (int i = 0; i < n; ++i) c[i][m - 1] = a[i];
    for (int j = 0; j < m; ++j) c[n - 1][j] = b[j];
    for (int i = 0; i < n - 1; ++i) x ^= c[i][m - 1];
    c[n - 1][m - 1] = x ^ b[m - 1];
    x = 0;
    for (int j = 0; j < m; ++j) x ^= c[n - 1][j];
    assert(x == a[n - 1]);
    puts("YES");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) printf("%d ", c[i][j]);
        puts("");
    }
    return 0;
}