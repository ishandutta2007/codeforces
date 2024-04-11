#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

#define ll long long
const int MAXN = 200200;
inline int highbit (int x) { if (!x) return 0; return 32 - __builtin_clz(x); }
inline int lowbit (int x) { return x & -x; }

int a[MAXN], n, m; ll t[MAXN];
void add (int x, int k) { while (x <= n) t[x] += k, x += lowbit(x); }
ll sum (int x) { ll ret = 0; while (x) ret += t[x], x -= lowbit(x); return ret; }

struct expq {
	priority_queue < int, vector <int>, greater <int> > val, rem;
	void push (int x) { val.push(x); }
	void del (int x) { rem.push(x); }
	void upd () { while (!val.empty() && !rem.empty() && val.top() == rem.top()) val.pop(), rem.pop(); }
	int top () { upd(); return val.top(); }
	bool empty () { upd(); return val.empty(); }
} pq[33];

int main () {
	n = read(), m = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read(), pq[highbit(a[i])].push(i), add(i, a[i]);
	while (m--) {
		int x = read(), ans = -1; pq[highbit(a[x])].del(x); add(x, -a[x]);
		a[x] = read(); pq[highbit(a[x])].push(x); add(x, a[x]);
		for (i = 0; i <= 30; i++) if (!pq[i].empty()) {
			int x = pq[i].top(); pq[i].del(x);
			if (sum(x - 1) == a[x]) ans = x;
			if (!pq[i].empty() && sum(pq[i].top() - 1) == a[pq[i].top()]) ans = pq[i].top();
			pq[i].push(x); if (ans != -1) break;
		}
		printf("%d\n", ans);
	}
	return 0;
}