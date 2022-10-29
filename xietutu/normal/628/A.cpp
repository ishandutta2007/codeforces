#include <bits/stdc++.h>
using namespace std;
int n, b, p, tb, tp;
int solve(int n) {
	if (n == 1) return 0;
	int l = 0, r = 10;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (1 << mid <= n) l = mid;
		else r = mid;
	}
	return solve(n - (1 << l) + (1 << (l - 1))) + (1 << l) * b + (1 << (l - 1));
}
int main() {
	scanf("%d%d%d", &n, &b, &p);
	printf("%d %d\n", solve(n), n * p);
}