#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
#define LS (t[x].ls)
#define RS (t[x].rs)
struct tree { int ls, rs, val, sum, rnd, siz, tag; } t[MAXN];
int top, root;
int newnode (int x) { ++top; t[top].val = x, t[top].rnd = rand(), t[top].siz = 1; return top; }
void pushup (int x) { t[x].siz = t[LS].siz + t[RS].siz + 1, t[x].sum = t[LS].sum + t[RS].sum + t[x].val; }
void cover (int x, int k) { t[x].val += k, t[x].tag += k, t[x].sum += k * t[x].siz; }
void pushdown (int x) {
    if (t[x].tag) {
        cover(LS, t[x].tag); cover(RS, t[x].tag);
        t[x].tag = 0;
    }
}
void split (int x, int k, int &a, int &b) {
    if (!x) { a = b = 0; return; }
    pushdown(x);
    if (t[LS].siz + 1 <= k) a = x, split(RS, k - t[LS].siz - 1, RS, b);
    else b = x, split(LS, k, a, LS);
    pushup(x);
}
int merge (int x, int y) {
    if (!x || !y) return x + y;
    if (t[x].rnd < t[y].rnd) { pushdown(x), t[x].rs = merge(RS, y), pushup(x); return x; }
    else { pushdown(y), t[y].ls = merge(x, t[y].ls); pushup(y); return y; }
}
void insert (int pos) {
    int r1, r2; split(root, pos, r1, r2);
    root = merge(merge(r1, newnode(0)), r2);
}
void modify (int l, int r, int k, int L, int R, int x) {
    if (R < l) return;
    if (l <= L && R <= r) {
        cover(x, k);
        return;
    }
    int mid = L + t[LS].siz; pushdown(x);
    if (l <= mid && mid <= r) t[x].val += k;
    if (l < mid) modify(l, r, k, L, mid - 1, LS);
    if (mid < r) modify(l, r, k, mid + 1, R, RS);
    pushup(x);
}
int query (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) return t[x].sum;
    int mid = L + t[LS].siz, ret = 0; pushdown(x);
    if (l <= mid && mid <= r) ret += t[x].val;
    if (l < mid) ret += query(l, r, L, mid - 1, LS);
    if (mid < r) ret += query(l, r, mid + 1, R, RS);
    pushup(x);
    return ret;
}
int n, a[MAXN];

signed main () {
    // freopen("test.in", "r", stdin);
    srand(time(NULL));
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    insert(1);
    for (i = 1; i <= n; i++) {
        int l = 1, r = i, div = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            // printf("l = %d, mid = %d, r = %d: %d, %d\n", l, mid, r, query(1, mid + 1, 1, t[root].siz, root), query(1, mid, 1, t[root].siz, root) + mid * a[i]);
            if (query(1, mid + 1, 1, t[root].siz, root) < query(1, mid, 1, t[root].siz, root) + (mid) * a[i]) r = mid - 1, div = mid;
            else l = mid + 1;
        }
        // cout << div << endl;
        insert(div);
        modify(div + 1, div + 1, (div - 1) * a[i], 1, t[root].siz, root);
        // for (j = 0; j <= i; j++) printf("%d ", query(1, j + 1, 1, t[root].siz, root));
        // puts("");
        // modify(div + 2, div + 2, -(div - 1) * a[i], 1, t[root].siz, root);
        // for (j = 0; j <= i; j++) printf("%d ", query(1, j + 1, 1, t[root].siz, root));
        // puts("");
        modify(div + 1, t[root].siz, a[i], 1, t[root].siz, root);
        // for (j = 0; j <= i; j++) printf("%d ", query(1, j + 1, 1, t[root].siz, root));
        // puts("");
        // puts("=========================================");
    }
    int ans = 0, s = 0;
    for (i = 1; i <= n + 1; i++) s += query(i, i, 1, t[root].siz, root), ans = max(ans, s);
    printf("%lld\n", ans);
    return 0;
}