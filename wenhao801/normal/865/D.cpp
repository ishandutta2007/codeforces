#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define ll long long
inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
int n, a[1001000];
priority_queue < int, vector<int>, greater<int> > q;

int main () {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	ll ans = 0;
	for (i = 1; i <= n; i++) {
		if (q.empty() || a[i] <= q.top()) { q.push(a[i]); continue; }
		ans += a[i] - q.top(); q.pop();
		q.push(a[i]); q.push(a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}