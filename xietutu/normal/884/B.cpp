#include <bits/stdc++.h>
using namespace std;
int n, x, sum;
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; ++i) {
		int v;
		scanf("%d", &v);
		sum += v;
	}
	if (sum + n - 1 == x) puts("YES");
	else puts("NO");
}