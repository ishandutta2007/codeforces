#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int cnt[30];

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n, a;
		scanf ("%d", &n);
		for (int i = 0; i < 30; ++i) cnt[i] = 0;
		while (n--) {
			scanf ("%d", &a);
			cnt[31 - __builtin_clz(a)]++;
		}
		ll res = 0;
		for (int i = 0; i < 30; ++i)
			res += 1LL * cnt[i] * (cnt[i] - 1) / 2;
		printf ("%lld\n", res);
	}
}