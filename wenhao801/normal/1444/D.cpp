#pragma GCC optimize(3)
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
#include <cassert>
 
using namespace std;
 
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
 
const int MAXN = 1010;
int n, m, a[MAXN], b[MAXN];
bitset <(1 << 20)> f[MAXN];
vector <int> va[2], vb[2];
#define all(v) v.begin(), v.end()
 
int main () {
    int T = read();
    while (T--) {
        va[0].clear(), vb[0].clear(), va[1].clear(), vb[1].clear();
        int i, j, sa = 0, sb = 0;
        n = read(); for (i = 1; i <= n; i++) a[i] = read(), sa += a[i];
        m = read(); for (i = 1; i <= m; i++) b[i] = read(), sb += b[i];
        if (n != m || (sa & 1) || (sb & 1)) { puts("No"); continue; }
        f[0][0] = 1; sa >>= 1, sb >>= 1;
        for (i = 1; i <= n; i++) f[i] = f[i - 1] | (f[i - 1] << a[i]);
        if (!f[n][sa]) { puts("No"); continue; }
        for (i = n; i >= 1; i--) {
            if (sa >= a[i] && f[i - 1][sa - a[i]]) va[0].push_back(a[i]), sa -= a[i];
            else va[1].push_back(a[i]);
        }
        for (i = 1; i <= m; i++) f[i] = f[i - 1] | (f[i - 1] << b[i]);
        if (!f[m][sb]) { puts("No"); continue; }
        for (i = m; i >= 1; i--) {
            if (sb >= b[i] && f[i - 1][sb - b[i]]) vb[0].push_back(b[i]), sb -= b[i];
            else vb[1].push_back(b[i]);
        }
        puts("Yes");
        sort(all(va[0])), sort(all(va[1])), sort(all(vb[0])), sort(all(vb[1]));
        if (va[0].size() > va[1].size()) swap(va[0], va[1]);
        if (vb[0].size() > vb[1].size()) swap(vb[0], vb[1]);
        bool rev = va[0].size() > vb[0].size();
        if (!rev) reverse(all(va[0])), reverse(all(va[1])); else reverse(all(vb[0])), reverse(all(vb[1]));
        for (auto &i: va[1]) i *= -1; for (auto &i: vb[1]) i *= -1;
        auto p = va[0].begin(), q = vb[0].begin(); int x = 0, y = 0;
        for (i = 1; i <= (n << 1); i++) {
            if (p == va[0].end()) p = va[1].begin();
            if (q == vb[0].end()) q = vb[1].begin();
            if ((i & 1) ^ rev) x += *(p++); else y += *(q++);
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}