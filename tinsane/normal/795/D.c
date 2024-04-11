#include <stdio.h>

int main(void) {
	const int N = 1e5 + 10;
	int a[N], b[N];
	int n, l, r, i;
	int ok = 1;
	scanf("%d%d%d", &n, &l, &r);
	--l, --r;
	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	for(i = 0; i < n; ++i)
		if (a[i] != b[i] && !(l <= i && i <= r))
			ok = 0;
	if (ok)
		puts("TRUTH");
	else
		puts("LIE");
	return 0;
}