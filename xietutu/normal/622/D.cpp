#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, p[maxn];
int main() {
	scanf("%d", &n);
	int r = n * 2, l = n;
	for (int i = 1, now = 0; i < n; ++i, now ^= 1) {
		int d = n - i;
		if (now == 0) p[r] = p[r - d] = i, --r;
		else  p[l] = p[l - d] = i, --l;
	}
	for (int i = 1; i <= n * 2; ++i)
		if (!p[i]) p[i] = n;
	for (int i = 1; i <= n * 2; ++i)
		printf("%d%c", p[i], i == n * 2 ? '\n' : ' ');
}