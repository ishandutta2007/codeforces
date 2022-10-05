#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, P = 998244353;
int n, k, ct, p[Maxn], pos[Maxn];
long long ans;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = n; i >= n - k + 1; i--)
		ans += i;
	printf("%lld ", ans);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		if (p[i] >= n - k + 1) pos[++ct] = i;
	}
	ans = 1;
	for (int i = 2; i <= ct; i++)
		(ans *= pos[i] - pos[i - 1]) %= P;
	printf("%lld", ans);
	return 0;
}