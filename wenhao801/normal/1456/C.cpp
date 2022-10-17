#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

using ll = long long;
const int MAXN = 500500;
int n, K, a[MAXN];

ll ans; priority_queue <ll> pq;

int main () {
	n = read(), K = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	ll sum = 0;
	for (i = n; i >= 1 && a[i] >= 0; i--) {
		ans += sum;
		sum += a[i];
	}
	pq.push(sum);
	for (j = 1; j <= K; j++) pq.push(0);
	for (i; i >= 1; i--) {
		ll now = pq.top(); ans += now;
		pq.pop(); pq.push(now + a[i]);
	}
	printf("%lld\n", ans);
	return 0;
}