#include <cstdio>

const int N = 200000;
int t, n, a[N];

bool test(int x) 
{
	for (int i = 0, j = n; i < j; ++i) if (a[i] != x) {
		for (--j; i < j && a[j] == x; --j);
		if (a[i] != a[j]) return 0;
	}
	return 1;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		int i;
		for (i = 0; i < n && a[i] == a[n - i - 1]; ++i);
		if (i == n) printf("YES\n");
		else if (test(a[i]) || test(a[n - i - 1])) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}