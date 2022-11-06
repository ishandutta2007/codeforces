#include<stdio.h>
#include<algorithm>
struct dot
{
	int x, y;
	bool operator<(const dot &A) const
	{
		return (x != A.x) ? (x<A.x) : (y<A.y);
	}
} in[200001];
int main()
{
	int n, i, j;
	long long ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d%d", &in[i].x, &in[i].y);
	std::sort(in + 1, in + 1 + n);
	for (i = 1; i <= n; i = j)
	{
		for (j = i; j<=n && in[i].x == in[j].x; j++);
		int c = j - i;
		ans += 1ll * c*(c - 1) / 2;
	}

	for (i = 1; i <= n; i++) { j = in[i].x; in[i].x = in[i].y; in[i].y = j; }
	std::sort(in + 1, in + 1 + n);
	for (i = 1; i <= n; i = j)
	{
		for (j = i; j<=n && in[i].x == in[j].x; j++);
		int c = j - i;
		ans += 1ll * c*(c - 1) / 2;
	}

	for (i = 1; i <= n; i = j)
	{
		for (j = i; j<=n && in[i].x == in[j].x && in[i].y == in[j].y; j++);
		int c = j - i;
		ans -= 1ll * c*(c - 1) / 2;
	}
	printf("%lld", ans);
	return 0;
}