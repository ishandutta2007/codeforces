#include<bits/stdc++.h>
using namespace std;
int c1, c2, n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > 0) ++c1;
		else if (x < 0) ++c2;
	}
	if (c1 > 1 && c2 > 1) puts("No");
	else puts("Yes");
	return 0;
}