#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		vector<int> a(n);
		for (auto& x : a) 
			scanf("%d", &x);
		int res = n;
		for (int c = 1; c <= 100; ++c) {
			int last = -k, curr = 0;
			for (int j = 0; j < n; ++j) {
				if (a[j] == c) continue;
				if (last + k <= j) {
					last = j;
					curr++;
				}
			}
			res = min(res, curr);
		}
		printf("%d\n", res);
	}
	return 0;
}