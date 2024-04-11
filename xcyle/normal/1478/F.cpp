#include <iostream>
#include <cstdio>
#include <cmath>
#define ll long long
#define maxn 5005
using namespace std;
int n, vis[maxn];
ll x[maxn], y[maxn];
inline ll calc(int a, int b)
{
	return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &x[i], &y[i]);
	}
	printf("1 ");
	vis[1] = 1;
	int last1 = 1, last2 = 1;
	for (int i = 2; i <= n; i++)
	{
		ll d = 0;
		int id = 0;
		for (int j = 1; j <= n; j++)
		{
			if(vis[j]) continue;
			if(i != 2 && calc(last1, j) - calc(last1, last2) >= calc(last2, j)) continue;
			if(calc(last2, j) > d)
			{
				d = calc(last2, j);
				id = j;
			}
		}
		printf("%d ", id);
		if(id == 0) printf("!!!!!\n");
		vis[id] = 1;
		last1 = last2;
		last2 = id;
	}
	return 0;
}