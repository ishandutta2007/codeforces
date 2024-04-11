#include <bits/stdc++.h>

using namespace std;

const int oo = (int)1e9 + 7;
const int MAXN = 505;

int n, m, a[MAXN][MAXN], b[MAXN][MAXN];

int pow4(int x) {return x*x*x*x;}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    int lcm = 720720;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if ((i+j)%2 == 0)
                b[i][j] = lcm;
            else
                b[i][j] = lcm + pow4(a[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            printf("%d ", b[i][j]);
        puts("");
    }

    return 0;
}