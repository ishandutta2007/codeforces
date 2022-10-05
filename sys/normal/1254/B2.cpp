#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, A[Maxn], a[Maxn], ct = 1, pos[Maxn], bel[Maxn];
long long mini = 0x3f3f3f3f3f3f3f3fLL, ans, sum, now;
void work(long long target)
{
	memset(pos, 0, sizeof(pos)); 
	for (int i = 1; i <= n; i++)
		a[i] = A[i];
	ans = now = 0;
	ct = 1;
	int pnt = 1;
	for (int i = 1; i <= n; i++)
	{
		bel[i] = ct;
		now += a[i] % target;
		if (now >= target / 2 + 1 && !pos[ct]) pos[ct] = i;
		if (now >= target)
		{
			now -= target, ct++;
			while (pnt < i) ans += (long long) (a[pnt] % target) * abs(pnt - pos[bel[pnt]]), pnt++;
			ans += (long long) (a[i] % target - now) * abs(i - pos[bel[i]]), bel[i] = ct;
			a[i] = now;
			if (now >= target / 2 + 1 && !pos[ct]) pos[ct] = i;
		}
	}
	mini = min(mini, ans);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]), sum += A[i];
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