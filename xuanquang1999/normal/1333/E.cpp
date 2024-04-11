#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int n, a[MAXN][MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    if (n <= 2) {
        puts("-1");
        return 0;
    }

    a[1][n] = n*(n-1) + 1;
    for(int i = 2; i <= n; ++i)
        a[i][n-1] = n*(n-1) + i;

    int cur = 1;
    for(int j = 1; j <= n-1; ++j)
        a[1][j] = cur++;
    for(int i = 2; i <= n; ++i)
        a[i][n] = cur++;

    for(int i = n; i >= 2; --i) {
        if ((n-i)%2 == 0) {
            for(int j = n-2; j >= 1; --j)
                a[i][j] = cur++;
        } else {
            for(int j = 1; j <= n-2; ++j)
                a[i][j] = cur++;
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            printf("%2d ", a[i][j]);
        puts("");
    }

    return 0;
}