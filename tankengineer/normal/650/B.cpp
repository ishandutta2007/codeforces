#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500005;

int n, a, b, T;

char s[N];

int pre[N], suf[N];

int main() {
	scanf("%d%d%d%d", &n, &a, &b, &T);
	scanf("%s", s);
	pre[0] = s[0] == 'w' ? b + 1 : 1;
	for (int i = 1; i < n; ++i) {
		int cost = 1 + a;
		if (s[i] == 'w') {
			cost += b;
		}
		pre[i] = pre[i - 1] + cost;
	}
	suf[0] = 0;
	for (int i = n - 1; i >= 0; --i) {
		int cost = 1 + a;
		if (s[i] == 'w') {
			cost += b;
		}
		suf[n - i] = suf[n - i - 1] + cost;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = i + 1, left = T - pre[i] - i * a;
		if (left < 0) {
			continue;
		}
		int pos = upper_bound(suf, suf + n, left) - suf - 1;
		pos = min(pos, n - tmp);
		tmp += pos;
		ans = max(ans, tmp);
	}
	for (int i = 0; i < n; ++i) {
		int tmp = i, left = T - suf[i] - i * a;
		if (left < pre[0]) {
			continue;
		}
		int pos = upper_bound(pre, pre + n, left) - pre - 1;
		pos = min(pos, n - 1 - tmp);
		tmp += pos + 1;
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}