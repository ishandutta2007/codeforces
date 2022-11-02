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

const int oo = 1000000000;
const int V = 100100;

int mi[V], mx[V];
int n, m, x, y;
int main() {
    while (~scanf("%d", &n)) {
        m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            int cmi = oo;
            int cmx = -oo;
            bool ok = false;
            for (int j = 0; j < x; ++j) {
                scanf("%d", &y);
                if (y > cmi) ok = true;
                cmi = min(cmi, y);
                cmx = max(cmx, y);
            }
            if (!ok) {
                mi[m] = cmi;
                mx[m] = cmx;
                m++;
            }
        }
        sort(mi, mi + m);
        sort(mx, mx + m);
        int p = 0;
        LL ans = 0;
        ans = (LL) n * n - (LL) m * m;
        for (int i = 0; i < m; ++i) {
            while (p != m && mi[p] < mx[i]) ++p;
            ans += p;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5
1 1
1 1
1 2
1 4
1 3

3
4 2 0 2 0
6 9 9 8 8 7 7
1 6

10
3 62 24 39
1 17
1 99
1 60
1 64
1 30
2 79 29
2 20 73
2 85 37
1 100

*/