#include <bits/stdc++.h>

using namespace std;

int q, n, a, cnt[105];

int main() {
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &n);
		for (int i = 0; i <= 100; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &a);
			cnt[a]++;
		}
		int res = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j <= 101; ++j) {
				res++;
				if (!cnt[j]) break;
				cnt[j]--;
			}
		}
		printf ("%d\n", res - 2);
	}
	
	return 0;
}