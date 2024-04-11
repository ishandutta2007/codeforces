#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
int n1, n2, n3, a, b, c, tmp;
long long A, B, C;
signed main()
{
	scanf("%d%d%d", &n1, &n2, &n3);
	long long ans = 0;
	a = b = c = INF;
	for (int i = 1; i <= n1; i++)
	{
		scanf("%lld", &tmp);
		a = min(a, tmp);
		A += tmp; 
	}
	for (int i = 1; i <= n2; i++)
	{
		scanf("%lld", &tmp);
		b = min(b, tmp);
		B += tmp;
	}
	for (int i = 1; i <= n3; i++)
	{
		scanf("%lld", &tmp);
		c = min(c, tmp);
		C += tmp;
	}
	ans = max(ans, A + B - C);
	ans = max(ans, A + C - B);
	ans = max(ans, B + C - A);
	ans = max(ans, A + B + C - 2 * (a + b + c) + 2 * max(a, max(b, c)));
	printf("%lld", ans);
	return 0;
}