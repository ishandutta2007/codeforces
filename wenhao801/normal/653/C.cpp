#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 150050;
int n, a[MAXN]; vector <int> v;
int ans = 0; map <int, bool> vis[MAXN];
void add (int u, int v) {
    if (u > v) swap(u, v);
    if (!vis[u][v]) vis[u][v] = 1, ++ans;
}

bool t[MAXN << 2];

void pushup (int x) { t[x] = t[x << 1] && t[x << 1 | 1]; }
void build (int l, int r, int x) {
    if (l == r) { t[x] = (l & 1) ? (a[l] < a[l + 1]) : (a[l] > a[l + 1]); return; }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1), build(mid + 1, r, x << 1 | 1);
    pushup(x);
}
void upd (int pos, int l, int r, int x) {
    if (l == r) { t[x] = (l & 1) ? (a[l] < a[l + 1]) : (a[l] > a[l + 1]); return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) upd(pos, l, mid, x << 1); else upd(pos, mid + 1, r, x << 1 | 1);
    pushup(x);
}

void cng (int pos, int k) {
    a[pos] = k;
    if (pos != 1) upd(pos - 1, 1, n - 1, 1);
    upd(pos, 1, n - 1, 1);
}
void check (int x, int y) {
    if (x > y) swap(x, y);
    int p = a[x], q = a[y];
    cng(x, q), cng(y, p);
    if (t[1]) add(x, y);
    cng(x, p), cng(y, q);
}

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    build(1, n - 1, 1);
    for (i = 1; i <= n; i++) {
        if (i & 1) {
            if (i != n && a[i] >= a[i + 1]) v.push_back(i);
            else if (i != 1 && a[i] >= a[i - 1]) v.push_back(i);
        }
        else  {
            if (i != n && a[i] <= a[i + 1]) v.push_back(i);
            else if (i != 1 && a[i] <= a[i - 1]) v.push_back(i);
        }
    }
    if (v.size() >= 10) { puts("0"); return 0; }
    for (int i = 0; i < v.size(); i++) for (int j = 0; j < i; j++) {
        check(v[i], v[j]);
    }
    for (auto i: v) {
        for (int j = 1; j <= n; j++) if (i != j) check(i, j);
    }
    printf("%d\n", ans);
    return 0;
}