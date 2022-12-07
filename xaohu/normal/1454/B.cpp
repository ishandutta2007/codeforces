#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<int> cnt(n), a(n);
		for (auto& x : a) {
			scanf("%d", &x);
			cnt[--x]++;
		}
		int res = n;
		for (int i = 0; i < n; ++i)
			if (cnt[a[i]] == 1 && (res == n || a[i] < a[res]))
				res = i;
		if (res == n) res = -1;
		else res++;
		printf("%d\n", res);
	}
	return 0;
}