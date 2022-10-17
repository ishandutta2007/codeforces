#include <iostream>
#include <cstdio>
#define maxn 300005
using namespace std;
int T, n, a[maxn];
int p[maxn];
int check(int t)
{
	if(t == 1 || t == n) return 0;
	if(a[t] > a[t - 1] && a[t] > a[t + 1]) return 1;
	if(a[t] < a[t - 1] && a[t] < a[t + 1]) return 1;
	return 0; 
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			p[i] = 0;
		}
		int cnt = 0;
		for (int i = 2; i <= n - 1; i++)
		{
			if(check(i))
			{
				p[i] = 1;
				cnt++;
			}
		}
		int ans = max(0, cnt - 1);
		for (int i = 2; i <= n - 1; i++)
		{
			if(p[i - 1]) cnt--;
			if(p[i + 1]) cnt--;
			if(p[i]) cnt--;
			int tmp = a[i];
			a[i] = a[i - 1];
			ans = min(ans, cnt + check(i - 1) + check(i) + check(i + 1));
			a[i] = a[i + 1];
			ans = min(ans, cnt + check(i - 1) + check(i) + check(i + 1));
			a[i] = tmp;
			if(p[i - 1]) cnt++;
			if(p[i + 1]) cnt++;
			if(p[i]) cnt++;
		}
		printf("%d\n", ans);
	}
	return 0;
}