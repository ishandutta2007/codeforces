#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> t(n), p(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		if (i) p[i] = p[i - 1];
		p[i] ^= t[i];
	}
	if (n >= 60) {
		printf("1\n");
		return 0;
	}
	int res = 1024;
	for (int a = 0; a < n; ++a)
		for (int b = a; b < n; ++b)
			for (int c = b + 1; c < n; ++c) {
				int x = (p[b] ^ (a == 0 ? 0 : p[a - 1]));
				if (b + 1 < n && x > t[b + 1])
					res = min(res, b - a);
				if (a >= 1 && t[a - 1] > x)
					res = min(res, b - a);
				int y = (p[c] ^ p[b]);
				if (x > y)
					res = min(res, b - a + c - b - 1);
			}
	if (res == 1024) res = -1;
	printf("%d\n", res);
	return 0;
}