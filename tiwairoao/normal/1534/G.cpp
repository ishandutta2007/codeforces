#include <bits/stdc++.h>

typedef long long ll;

const int N = 800000;

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = getchar();
	return x;
}

struct point{int x, y;}a[N + 5];
int main() {
	int n = read();
	for (int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
	std::sort(a + 1, a + n + 1, [](const point &p, const point &q){
		return p.x + p.y < q.x + q.y;
	});
	int s = a[n].x + a[n].y;

	std::priority_queue<int>ql;
	std::priority_queue<int, std::vector<int>, std::greater<int> >qr;
	
	ql.push(0), qr.push(s); int tag = 0; ll y0 = 0;
	for (int i = n, lst = s; i >= 0; i--) {
		tag -= (lst - (a[i].x + a[i].y)), lst = a[i].x + a[i].y;
		if (!i) break;

		if (ql.top() + tag <= a[i].x && a[i].x <= qr.top()) {
			ql.push(a[i].x - tag), qr.push(a[i].x);
		} else if (qr.top() < a[i].x) {
			assert (!qr.empty());
			y0 += (a[i].x - qr.top());
			ql.push(qr.top() - tag), qr.pop();
			qr.push(a[i].x), qr.push(a[i].x);
		} else {
			assert (!ql.empty());
			y0 += (ql.top() + tag - a[i].x);
			qr.push(ql.top() + tag), ql.pop();
			ql.push(a[i].x - tag), ql.push(a[i].x - tag);
		}
	}

	ll ans = y0;
	while (0 < ql.top() + tag) ans += (ql.top() + tag), ql.pop();
	while (qr.top() < 0) ans += (0 - qr.top()), qr.pop();
	printf("%lld\n", ans);
}