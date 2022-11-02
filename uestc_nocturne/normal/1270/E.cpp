/*
Author: elfness@UESTC
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 1010;
LL gcd(LL x, LL y) {
    if (!y) return x;
    return gcd(y, x %y);
}

int ans[V], x[V], y[V];
int n, m;

int main() {
    while (~scanf("%d", &n)) {
        m = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        LL gd = 0;
        for (int i = n; i >= 1; --i) {
            x[i] -= x[1];
            y[i] -= y[1];
            gd = gcd(x[i], gd);
            gd = gcd(y[i], gd);

        }
        for (int i = 1; i <= n; ++i) {
            x[i] /= gd;
            y[i] /= gd;
            if ((x[i] + y[i]) % 2 == 0) ans[m++] = i;
        }
        /*
        for (int i = 1; i <= n; ++i, puts("")) {
            for (int j = 1; j <= n; ++j) {
                printf("%d ", (x[i] - x[j]) * (x[i] - x[j]) +(y[i] - y[j]) *(y[i] - y[j]));
            }
        }*/
        if (m == n) {
            m = 0;
            for (int i = 1; i <= n; ++i) {
            if (x[i] % 2 == 0 && y[i] % 2 == 0) ans[m++] = i;
        }
        }
        printf("%d\n", m);
        for (int i = 0; i < m; ++i) printf("%d ", ans[i]); puts("");
    }
    return 0;
}

/*
3
0 0
0 1
1 0
4
0 1
0 -1
1 0
-1 0
3
-2 1
1 1
-1 0
6
2 5
0 3
-4 -1
-5 -4
1 0
3 -1
2
-1000000 -1000000
1000000 1000000
*/