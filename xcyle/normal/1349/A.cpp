#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 200005
using namespace std;
int n, a[maxn];
vector<int> t[maxn];
long long gcd(long long x, long long y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
long long lcm(long long x, long long y)
{
	return x * y / gcd(x, y);
}
long long pow(int x, int y)
{
	long long res = 1;
	for (int i = 1; i <= y; i++)
	{
		res *= x;
	}
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		for (register int j = 2; j * j <= a[i]; j++)
		{
			if(a[i] % j != 0) continue;
			int cnt = 0;
			while(a[i] % j == 0)
			{
				cnt++;
				a[i] /= j;
			}
			t[j].push_back(cnt);
		}
		if(a[i] > 1) t[a[i]].push_back(1);
	}
	long long ans = 1;
	for (int i = 1; i < maxn; i++)
	{
		if(t[i].size() < n - 1) continue;
		int Mn1 = maxn, Mn2 = maxn;
//		printf("%d  ", i);
		for (int j = 0; j < t[i].size(); j++)
		{
//			printf("%d ", t[i][j]);
			if(t[i][j] < Mn1)
			{
				Mn2 = Mn1;
				 Mn1 = t[i][j];
			}
			else if(t[i][j] < Mn2) Mn2 = t[i][j];
		}
//		printf("    %d %d\n", Mn1, Mn2);
		if(t[i].size() == n - 1) ans = lcm(ans, pow(i, Mn1));
		else ans = lcm(ans, pow(i, Mn2));
	}
	printf("%lld", ans);
	return 0;
}