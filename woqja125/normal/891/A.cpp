#include<cstdio>
int a[2001];
int g(int x, int y) { return y ? g(y, x%y) : x; }
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", a + i);
	int ans = 100000;
	int c1 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) c1++;
		int t = a[i], j = i+1, c = 0;
		for (; j <= n && t != 1; c++, j++) {
			t = g(t, a[j]);
		}
		if (t == 1 && ans > c) ans = c;
	}
	if (c1 > 0) printf("%d\n", n - c1);
	else if (ans == 100000) printf("-1\n");
	else printf("%d\n", ans + n - 1);
	return 0;
}