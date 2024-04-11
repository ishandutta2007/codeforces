#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 5e5 + 5;

vector <pii> p[N << 2];
vector <int> qry[N];
int f[N], siz[N], st[N], opt[N], x[N], y[N], las[N];
int n, q, k, nowt, top, tmax;

int find(int x) { return f[x] == x ? x : find(f[x]); }

void merge(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (siz[x] > siz[y]) swap(x, y);
    st[++top] = x; siz[y] += siz[x]; f[x] = y;
}

void add(int u, int L, int R, int l, int r, pii x) {
    if (l <= L && R <= r) {
        p[u].push_back(x);
        return;
    }
    int mid = (L + R) >> 1;
    if (mid >= l) add(u << 1, L, mid, l, r, x);
    if (mid + 1 <= r) add(u << 1 | 1, mid + 1, R, l, r, x);
}

void popst(int tmp) {
    while (top > tmp) {
        siz[f[st[top]]] -= siz[st[top]];
        f[st[top]] = st[top];
        --top;
    }
}

void query(int u, int l, int r) {
    int tmp = top;
    for (auto i : p[u]) merge(i.first, i.second);
    if (l == r) {
        for (auto i : qry[l]) print(siz[find(i)], '\n');
        popst(tmp); return;
    }
    int mid = (l + r) >> 1;
    query(u << 1, l, mid); query(u << 1 | 1, mid + 1, r);
    popst(tmp);
}

int main() {
    read(n); read(q); read(k); nowt = 1;
    for (int i = 1; i <= q; i++) {
        read(opt[i]);
        if (opt[i] == 1) read(x[i]), read(y[i]);
        if (opt[i] == 2) read(x[i]), qry[i].push_back(x[i]);
        if (opt[i] == 3) las[++tmax] = i;
    }
    for (int i = 1; i <= q; i++) {
        if (opt[i] == 1) {
            int r = q;
            if (nowt + k - 1 <= tmax) r = las[nowt + k - 1];
            add(1, 1, q, i, r, make_pair(x[i], y[i]));
        }
        if (opt[i] == 3) ++nowt;
    }
    for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
    query(1, 1, q);
    return 0;
}