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

const int MAXN = 1001000;
const int inf = 1e9 + 7;
int n;

char a[MAXN] = {};

int Max[MAXN << 1] = {};
int Min[MAXN << 1] = {};
int lazy[MAXN << 1] = {};

int min (int x, int y) { return x < y ? x : y; }
int max (int x, int y) { return x > y ? x : y; }

void pushup (int x) { Max[x] = max(Max[x << 1], Max[x << 1 | 1]), Min[x] = min(Min[x << 1], Min[x << 1 | 1]); }

void pushdown (int root) {
    Min[root << 1] += lazy[root];
    Max[root << 1] += lazy[root];
    Min[root << 1 | 1] += lazy[root];
    Max[root << 1 | 1] += lazy[root];
    lazy[root << 1] += lazy[root];
    lazy[root << 1 | 1] += lazy[root];
    lazy[root] = 0;
}

void modify (int l, int r, int k, int L, int R, int root) {
    if (l <= L && R <= r) {
        Min[root] += k;
        Max[root] += k;
        lazy[root] += k;
        return;
    }
    pushdown(root);
    int mid = (L + R) >> 1;
    if (mid >= l) modify(l, r, k, L, mid, root << 1);
    if (mid < r) modify(l, r, k, mid + 1, R, root << 1 | 1);
    pushup(root);
    return;
}

int qmin (int l, int r, int L, int R, int root) {
    if (l == 0) return 0;
    if (l <= L && R <= r) return Min[root];
    pushdown(root);
    int mid = (L + R) >> 1;
    int ret = inf;
    if (mid >= l) ret = min(ret, qmin(l, r, L, mid, root << 1));
    if (mid < r) ret = min(ret, qmin(l, r, mid + 1, R, root << 1 | 1));
    pushup(root);
    return ret;
}

int qmax (int l, int r, int L, int R, int root) {
    if (l <= L && R <= r) return Max[root];
    pushdown(root);
    int mid = (L + R) >> 1;
    int ret = 0;
    if (mid >= l) ret = max(ret, qmax(l, r, L, mid, root << 1));
    if (mid < r) ret = max(ret, qmax(l, r, mid + 1, R, root << 1 | 1));
    pushup(root);
    return ret;
}

void write (int x) {
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

int main () {
    n = read();
    scanf("%s", a + 1);
    int i, j;
    int pos = 1;
    for (i = 1; i <= n; i++) {
        if (a[i] == 'L') pos--, pos = max(pos, 1);
        else if (a[i] == 'R') pos++;
        else if (a[i] == '(') {
            j = qmin(pos, pos, 1, n, 1) - qmin(pos - 1, pos - 1, 1, n, 1);
            modify(pos, n, 1 - j, 1, n, 1);
        }
        else if (a[i] == ')') {
            j = qmin(pos, pos, 1, n, 1) - qmin(pos - 1, pos - 1, 1, n, 1);
            modify(pos, n, -1 - j, 1, n, 1);
        }
        else {
            j = qmin(pos, pos, 1, n, 1) - qmin(pos - 1, pos - 1, 1, n, 1);
            modify(pos, n, -j, 1, n, 1);
        }
        if (qmin(1, n, 1, n, 1) < 0 || qmin(n, n, 1, n, 1) != 0) { putchar('-'), putchar('1'), putchar(' '); continue; }
        else write(qmax(1, n, 1, n, 1)), putchar(' ');
    }
    return 0;
}