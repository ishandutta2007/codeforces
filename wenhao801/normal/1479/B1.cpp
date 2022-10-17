#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
const int MAXN = 100100;
int n, a[MAXN], f[MAXN];

int t[MAXN << 2], tag[MAXN << 2];
void pushup (int x) { t[x] = max(t[x << 1], t[x << 1 | 1]); }
void cover (int x, int k) {
    t[x] += k; tag[x] += k;
}
void pushdown (int x) {
    if (tag[x]) { cover(x << 1, tag[x]); cover(x << 1 | 1, tag[x]); tag[x] = 0; }
}
void add () { cover(1, 1); }
int get (int pos, int l, int r, int x) {
    if (l == r) return t[x];
    pushdown(x); int mid = (l + r) >> 1, ret;
    if (pos <= mid) ret = get(pos, l, mid, x << 1);
    else ret = get(pos, mid + 1, r, x << 1 | 1);
    pushup(x); return ret;
}
void modify (int pos, int k, int l, int r, int x) {
    if (l == r) { t[x] = k; return; }
    pushdown(x); int mid = (l + r) >> 1;
    if (pos <= mid) modify(pos, k, l, mid, x << 1);
    else modify(pos, k, mid + 1, r, x << 1 | 1);
    pushup(x);
}

int main () {
    memset(f, 0x3f, sizeof(f));
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    modify(n + 1, 1, 1, n + 1, 1);
    for (i = 2; i <= n; i++) {
        // printf("%d %d %d %d\n", get(1, 1, n + 1, 1), get(2, 1, n + 1, 1), get(3, 1, n + 1, 1), get(n + 1, 1, n + 1, 1));
        if (a[i] == a[i - 1]) {
            
            int res = get(a[i], 1, n + 1, 1);
            modify(a[i], -123, 1, n + 1, 1);
            res = max(res, t[1] + 1);
            modify(a[i], res, 1, n + 1, 1);
            continue;
        }
        int res = get(a[i], 1, n + 1, 1), tmp = res;
        modify(a[i], -123, 1, n + 1, 1);
        res = max(res, t[1] + 1);
        modify(a[i], tmp, 1, n + 1, 1);
        add(); modify(a[i - 1], res, 1, n + 1, 1);
    }
    printf("%d\n", t[1]);
    return 0;
}