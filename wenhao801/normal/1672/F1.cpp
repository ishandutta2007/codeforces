#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 200200;
int n, a[MAXN]; vector <int> v[MAXN];
pii buc[MAXN];

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), ++buc[a[i]].fr, buc[i].se = i;
        sort(buc + 1, buc + n + 1, [](pii u, pii v) { return u.fr > v.fr; });
        for (i = n; i >= 2; i--) {
            while (buc[i].fr) {
                for (j = i; j >= 2; j--)
                    v[buc[j].se].emplace_back(buc[j - 1].se), --buc[j].fr;
                v[buc[1].se].emplace_back(buc[i].se), --buc[1].fr;
            }
        }
        while (buc[1].fr) v[buc[1].se].emplace_back(buc[1].se), --buc[1].fr;
        for (i = 1; i <= n; i++) printf("%d ", v[a[i]].back()), v[a[i]].pop_back();
        putchar('\n');
        for (i = 1; i <= n; i++) buc[i] = {0, 0}, v[i].clear();
    }
    return 0;
}