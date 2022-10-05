#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
int n, a[Maxn], ct = 1, pos[Maxn], bel[Maxn], now;
long long mini = 0x3f3f3f3f3f3f3f3fLL, ans, sum;
void work(int target)
{
	memset(pos, 0, sizeof(pos)); 
	ans = now = 0;
	ct = 1;
	for (int i = 1; i <= n; i++)
	{
		bel[i] = ct;
		now += a[i];
		if (now == target / 2 + 1 && !pos[ct]) pos[ct] = i;
		if (now == target) now = 0, ct++;
	}
	for (int i = 1; i <= n; i++)
		if (a[i]) ans += abs(i - pos[bel[i]]);
	mini = min(mini, ans);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum += a[i];
	if (sum == 1)
	{
		printf("-1");
		return 0;
	}
	int maxi = sqrt(sum);
	for (int i = 2; i <= maxi; i++)
		if (sum % i == 0)
		{
			work(i);
			while (sum % i == 0) sum /= i;
		}
	if (sum != 1)
		work(sum);
	printf("%lld", mini);
	return 0;
}