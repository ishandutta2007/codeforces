#include <bits/stdc++.h>
using namespace std;
int main() {
	int t, x, y, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y)
		            swap(x, y);
		if (a * 2 > b)
		            printf("%I64d\n", (long long)x * b + (long long)(y - x) * a); else
		            printf("%I64d\n", (long long)(y + x) * a);
	}
	return 0;
}