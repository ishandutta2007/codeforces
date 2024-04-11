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

int n;
int a[200200] = {};
int ans = 7849757085278673236ll;

void check (int x) {
	if (!x) return;
	int i, j;
	int t = 0;
	for (i = 1; i <= n; i++) t += min((a[i] < x ? ans : a[i] % x), x - a[i] % x);
	ans = min(ans, t);
}

int rnd (int l, int r) { return rand() % (r - l + 1) + l; }

int p[1001000], top = 0;
bool np[1001000];

void genprime() {
	int i, j;
	for (i = 2; i <= 1000000; i++) {
		if (!np[i]) p[++top] = i;
		for (j = 1; j <= top; j++) {
			if (i * p[j] > 1000000) break;
			np[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int cnt[1001000], tc = 0;
int T = 25;

void countp (int x) {
	if (!x) return; int i;
	for (i = 1; i <= top; i++) {
		if (x % p[i] == 0) cnt[++tc] = p[i];
		while (x % p[i] == 0) cnt[i]++, x /= p[i];
	}
	if (x > 1) cnt[++tc] = x;
}

signed main () {
	srand(time(NULL));
	n = read();
	genprime();
	int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	random_shuffle(a + 1, a + n + 1);
	check(2), check(3), check(5), check(7), check(11);
	for (i = 1; i <= T; i++) {
		int num = rnd(1, n);
		//printf("%lld ", a[num]);
		countp(a[num] - 1), countp(a[num]), countp(a[num] + 1);
	}
	sort(cnt + 1, cnt + tc + 1); tc = unique(cnt + 1, cnt + tc + 1) - cnt - 1;
	for (i = 1; i <= tc; i++) check(cnt[i]);
	printf("%lld\n", ans);
	return 0;
}