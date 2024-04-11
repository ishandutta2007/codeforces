#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
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

const int MAXN = 300300, inf = 2e9 + 7;
int n, w, a[MAXN], b[MAXN], now[MAXN];

struct dt { int id, val; dt (int _id = 0, int _val = 0) { id = _id, val = _val; } bool operator < (const dt &tmp) const { if (val == tmp.val) return id > tmp.id; return val > tmp.val; } };
struct removable_pq {
	priority_queue <dt> val, trash;
	void upd () { while (!val.empty() && !trash.empty() && val.top().id == trash.top().id && val.top().val == trash.top().val) val.pop(), trash.pop(); }
	void push (dt tmp) { val.push(tmp); }
	bool empty () { upd(); return val.empty(); }
	dt top () { upd(); return val.top(); }
	void del (dt tmp) { trash.push(tmp); }
} q1, q2, q3, q4, q5;

int main () {
	n = read(), w = read();
	for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read(), q1.push(dt(i, a[i])), q5.push(dt(i, b[i]));
	while (w--) {
		int t1 = inf, t2 = inf, t3 = inf, t4 = inf;
		if (!q1.empty()) t1 = q1.top().val;
		if (!q3.empty()) t2 = q3.top().val;
		if (!q2.empty() && !q5.empty()) t3 = q2.top().val + q5.top().val;
		if (!q4.empty() && !q5.empty()) t4 = q4.top().val + q5.top().val;
		if (t1 <= t2 && t1 <= t3 && t1 <= t4) {
			int id = q1.top().id; assert(now[id] == 0);
			q1.del(dt(id, a[id])), q5.del(dt(id, b[id]));
			now[id] = 1;
			q2.push(dt(id, -a[id])), q3.push(dt(id, b[id] - a[id]));
		}
		else if (t2 <= t1 && t2 <= t3 && t2 <= t4) {
			int id = q3.top().id; assert(now[id] == 1);
			q2.del(dt(id, -a[id])), q3.del(dt(id, b[id] - a[id]));
			now[id] = 2;
			q4.push(dt(id, a[id] - b[id]));
		}
		else if (t3 <= t1 && t3 <= t2 && t3 <= t4) {
			int o = q2.top().id, t = q5.top().id; assert(now[o] == 1 && now[t] == 0);
			q2.del(dt(o, -a[o])), q3.del(dt(o, b[o] - a[o]));
			now[o] = 0;
			q1.push(dt(o, a[o])), q5.push(dt(o, b[o]));
			q1.del(dt(t, a[t])), q5.del(dt(t, b[t]));
			now[t] = 2;
			q4.push(dt(t, a[t] - b[t]));
		}
		else {
			int o = q4.top().id, t = q5.top().id; assert(now[o] == 2 && now[t] == 0);
			q4.del(dt(o, a[o] - b[o]));
			now[o] = 1;
			q2.push(dt(o, -a[o])), q3.push(dt(o, b[o] - a[o]));
			q1.del(dt(t, a[t])), q5.del(dt(t, b[t]));
			now[t] = 2;
			q4.push(dt(t, a[t] - b[t]));
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) { if (now[i] == 1) ans += a[i]; if (now[i] == 2) ans += b[i]; }
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++) putchar('0' + now[i]);
	puts("");
	return 0;
}