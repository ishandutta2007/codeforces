#include <bits/stdc++.h>
using namespace std;
bool p[500000];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 9; ++i) {
		int ret = (1 << i) * ( (1 << (i + 1)) - 1);
		p[ret] = true;
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		if (n % i == 0) {
			if (p[i] && i > ans) ans = i;
			if (p[n / i] && n / i > ans) ans = n / i;
		}
	printf("%d\n", ans);
}