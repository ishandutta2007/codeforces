#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2020;
char a[MAXN][MAXN];
int u[MAXN][MAXN], d[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN];
int n, m;

int main () {
    scanf("%d%d", &n, &m);
    int i, j;
    for (i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (a[j][i] != a[j - 1][i]) u[j][i] = 1;
            else u[j][i] = u[j - 1][i] + 1; 
        }
        for (j = n; j >= 1; j--) {
            if (a[j][i] != a[j + 1][i]) d[j][i] = 1;
            else d[j][i] = d[j + 1][i] + 1;
        }
    }
    long long ans = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i][j] != a[i][j - 1]) l[i][j] = 1;
            else l[i][j] = min(l[i][j - 1] + 1, min(u[i][j], d[i][j]));
        }
        for (j = m; j >= 1; j--) {
            if (a[i][j] != a[i][j + 1]) r[i][j] = 1;
            else r[i][j] = min(r[i][j + 1] + 1, min(u[i][j], d[i][j]));
        }
        for (j = 1; j <= m; j++)
            ans += min(l[i][j], r[i][j]);
    }
    cout << ans << endl;
    return 0;
}