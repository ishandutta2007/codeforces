#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int n, a, t[maxn], tmp[maxn], sum[maxn];
int vis[maxn], prime[maxn], tot, miu[maxn];
long long ans = 0;
inline int gcd(int x, int y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
int check(int x, int y)
{
	int d = gcd(x, y);
	if(d != 1) return 0;
	ans = max(ans, (long long)x * y);
	return 1; 
} 
void init()
{
	miu[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		if(!vis[i])
		{
			prime[++tot] = i;
			miu[i] = -1;
		}
		for (int j = 1; j <= tot && i * prime[j] < maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				miu[i * prime[j]] = 0;
				break;
			}
			miu[i * prime[j]] = -miu[i];
		}
	}
}
int main()
{
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		ans = max(ans, (long long)a);
		t[a] = 1;
	}
	for (int i = maxn - 1; i >= 1; i--)
	{
		for (int j = i; j < maxn; j += i) t[i] |= t[j];
	}
	int pos = 1;
	for (int i = 1; i < maxn; i++)
	{
		for (int j = i; j < maxn; j += i) sum[i] += t[j];
	}
	for (int i = maxn - 1; i >= 1; i--)
	{
		if(!t[i]) continue;
		if(pos >= i) continue;
		for (register int j = 1; j * j <= i; j++) 
		{
			if(i % j != 0) continue;
			sum[j]--;
			if(j * j != i) sum[i / j]--;
		}
		long long num = 0;
		for (register int j = 1; j * j <= i; j++) 
		{
			if(i % j != 0) continue;
			num += miu[j] * sum[j];
			if(j * j != i) num += miu[i / j] * sum[i / j];
		}
//		printf("%d %d %d ", i, pos, num);
		while(num)
		{
			if(!t[pos])
			{
				pos++;
				continue;
			}
			if(check(i, pos)) num--;
			for (register int j = 1; j * j <= pos; j++) 
			{
				if(pos % j != 0) continue;
				sum[j]--;
				if(j * j != pos) sum[pos / j]--;
			}
			pos++;
		}
//		printf("%d\n", pos);
	}
	printf("%lld", ans);
	return 0;
}