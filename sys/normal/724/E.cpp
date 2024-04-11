#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
int n, c, p[Maxn], s[Maxn];
long long f[Maxn];
int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; j--)
			f[j] = min(f[j] + c * (long long) j + p[i], f[j - 1] + s[i]);
		f[0] += p[i];
	}
	printf("%lld", *min_element(f, f + n + 1));
	return 0;
}