#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
	int t, n, m, r, c;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &n, &m, &r, &c);
		printf("%d\n", max(r - 1, n - r) + max(c - 1, m - c));
	}
	return 0;
}