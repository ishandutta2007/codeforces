#pragma GCC optimize(3)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 200200;

struct pt { int a, b, c, d, id; bool operator < (const pt &tmp) const { return a < tmp.a; } } a[MAXN];
int n, p[MAXN], q[MAXN], tp, tq;
inline int xHash (int x) { return lower_bound(p + 1, p + tp + 1, x) - p; }
inline int yHash (int x) { return lower_bound(q + 1, q + tq + 1, x) - q; }

queue <int> Q;
int dis[MAXN];

struct node {
    int mnid;
    node (int _val = 0) { mnid = _val; }
    node operator + (const node &tmp) const {
        if (a[mnid].b < a[tmp.mnid].b) return node(mnid);
        return tmp;
    }
} t[MAXN << 2];
void build (int l, int r, int x) {
    if (l == r) { t[x].mnid = l; return; }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
void modify (int pos, int l, int r, int x) {
    if (l == r) { t[x].mnid = 0; return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(pos, l, mid, x << 1); else modify(pos, mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
node query (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) return t[x];
    int mid = (L + R) >> 1;
    if (l <= mid && mid < r) return query(l, r, L, mid, x << 1) + query(l, r, mid + 1, R, x << 1 | 1);
    if (l <= mid) return query(l, r, L, mid, x << 1); else return query(l, r, mid + 1, R, x << 1 | 1);
}

int from[MAXN];
void out (int x) {
    if (!x) return;
    out(from[x]); printf("%d ", x);
}

int main () {
	// freopen("test2.out", "w", stdout);
	n = read(); int i, j, k;
	for (i = 1; i <= n; i++) {
		a[i].a = read(), a[i].b = read(), a[i].c = read(), a[i].d = read(); a[i].id = i;
		p[++tp] = a[i].a, p[++tp] = a[i].c;
		q[++tq] = a[i].b, q[++tq] = a[i].d;
	}
	p[++tp] = 0, q[++tq] = 0;
	sort(p + 1, p + tp + 1); tp = unique(p + 1, p + tp + 1) - p - 1;
	sort(q + 1, q + tq + 1); tq = unique(q + 1, q + tq + 1) - q - 1;
    sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++) {
        dis[i] = -1;
		a[i].a = xHash(a[i].a), a[i].c = xHash(a[i].c);
		a[i].b = yHash(a[i].b), a[i].d = yHash(a[i].d);
	}
    build(1, n, 1); a[0].b = 1e9 + 7; a[n + 1].a = 1e9 + 7;
    for (i = 1; i <= n; i++) if (!p[a[i].a] && !q[a[i].b]) dis[a[i].id] = 0, modify(i, 1, n, 1), Q.push(i);
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        int tmp = query(1, upper_bound(a + 1, a + n + 1, pt{a[x].c, 0, 0, 0, 0}) - a - 1, 1, n, 1).mnid;
        while (a[tmp].b <= a[x].d) {
            dis[a[tmp].id] = dis[a[x].id] + 1; Q.push(tmp); from[a[tmp].id] = a[x].id;
            modify(tmp, 1, n, 1);
            tmp = query(1, upper_bound(a + 1, a + n + 1, pt{a[x].c, 0, 0, 0, 0}) - a - 1, 1, n, 1).mnid;
        }
    }
    if (dis[n] == -1) puts("-1"); else {
        printf("%d\n", dis[n] + 1);
        out(n);
    }
	return 0;
}