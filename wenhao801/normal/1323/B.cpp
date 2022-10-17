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

int n, m, k;
int a[40040], b[40040];

int p[80800], q[80080];
int lowbit (int x) { return x & -x; }
void add(int root, int num, int *f) {
	while (root != 0) {
		f[root] += num;
		root -= lowbit(root);
	}
	return;
}

int query(int x, int *f) {
	int ret = 0;
	while (x <= max(n, m)) {
		ret += f[x];
		x += lowbit(x);
	}
	return ret;
}
#include <cmath>
int main () {
    n = read(), m = read(), k = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= m; i++) b[i] = read();
    for (i = 1, j = 0; i <= n; i++) {
        if (a[i] == 0) continue;
        if (a[i] == a[i - 1]) j++;
        else j = 1;
        add(j, 1, p);
    }
    for (i = 1, j = 0; i <= m; i++) {
        if (b[i] == 0) continue;
        if (b[i] == b[i - 1]) j++;
        else j = 1;
        add(j, 1, q);
    }
    int rua = sqrt(k);
    long long ans = 0;
    for (i = 1; i <= rua; i++) {
        if (k % i != 0) continue;
        int P = i, Q = k / i;
        if (P <= n && Q <= m) {
            ans += (long long)(query(P, p) * query(Q, q));
        }
        if (Q <= n && P <= m) {
            ans += (long long)(query(P, q) * query(Q, p));
        }
    }
    if (rua * rua == k) {
        if (rua <= n && rua <= m) ans -= (long long)(query(rua, p) * query(rua, q));
    }
    printf("%lld\n", ans);
    return 0;
}