#include <bits/stdc++.h>

using ll = long long;
using namespace std;

char s[1 << 18];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, p, k, x, y;
		scanf("%d%d%d", &n, &p, &k);
		p--;
		vector<int> b(n);
		scanf("%s", s);
		scanf("%d%d", &x, &y);
		int ans = 1 << 30;
		for (int i = n - 1; 0 <= i; --i) {
			b[i] = !(s[i] == '1');
			if (i + k < n)
				b[i] += b[i + k];
			if (i >= p)
				ans = min(ans, (i - p) * y + b[i] * x);
		}
		printf("%d\n", ans);
	}
	return 0;
}