#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1 << 20, inf = 1e9;
int n, m; bool a[MAXN];

#define ls t[x].ch[0]
#define rs t[x].ch[1]
struct node { int ch[2], mn, mx, ans; } t[MAXN << 2]; int top = 1;
void pushup(int b, int x) {
    if (t[ls].mn == inf && t[rs].mn == inf) { t[x].mn = inf, t[x].mx = -inf, t[x].ans = inf; return; }
    t[x].mn = min(t[ls].mn, t[rs].mn + (1 << b));
    t[x].mx = max(t[ls].mx, t[rs].mx + (1 << b));
    t[x].ans = min(min(t[ls].ans, t[rs].ans), t[rs].mn + (1 << b) - t[ls].mx);
}
void build(int b, int val, int x) {
    if (b == -1) {
        t[x].mn = inf, t[x].mx = -inf;
        if (a[val]) t[x].mn = t[x].mx = 0;
        t[x].ans = 1e9;
        return;
    }
    build(b - 1, val, ls = ++top);
    build(b - 1, val + (1 << b), rs = ++top);
    pushup(b, x);
}
void work(int b, int to, int x) {
    if (b == to) { swap(ls, rs); pushup(b, x); return; }
    work(b - 1, to, ls), work(b - 1, to, rs);
    pushup(b, x);
}

int cur, ans[MAXN];
void solve(int b) {
    if (b == m) return;
    solve(b + 1);
    cur ^= 1 << b; work(m - 1, b, 1); ans[cur] = t[1].ans;
    solve(b + 1);
}

int main() {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) a[read()] = 1;
    build(m - 1, 0, 1); ans[0] = t[1].ans; solve(0);
    for (i = 0; i < (1 << m); i++) printf("%d ", ans[i]); putchar('\n');
    return 0;
}