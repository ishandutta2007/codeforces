#include <bits/stdc++.h>
using namespace std;

int n, p, q;
unsigned int ans, a[205], b[205], C[205];
int main()
{
	scanf("%d%d%d", &n, &p, &q);
	p = min(p, n - 1);
	C[0] = 1;
	for (int i = 1; i <= p; i++)
	{
		for (int j = 1; j <= i; j++)
			a[j] = n - j + 1, b[j] = j;
		for (int j = 1; j <= i; j++)
			for (int k = 1; k <= i; k++)
			{
				int g = __gcd(b[j], a[k]);
				a[k] /= g, b[j] /= g;
			}
		C[i] = 1;
		for (int j = 1; j <= i; j++)
			C[i] *= a[j];
	}
	for (int i = 1; i <= q; i++)
	{
		unsigned int tmp = 0, now = 1;
		for (int j = 0; j <= p; j++)
			tmp += C[j] * now, now = now * i;
		ans ^= tmp * i;
	}
	printf("%u", ans);
	return 0;
}