#include <iostream>
#include <cstdio>
#define maxn 200005
#define ll long long
using namespace std;
int n, m, q, u, v;
int d[maxn], type;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u, &v);
		if(u > v) swap(u, v);
		d[u]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) 
	{
		if(d[i] == 0) ans++;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &type);
		if(type == 3) printf("%d\n", ans);
		if(type == 2) 
		{
			scanf("%d%d", &u, &v);
			if(u > v) swap(u, v);
			d[u]--;
			if(d[u] == 0) ans++;
		}
		if(type == 1) 
		{
			scanf("%d%d", &u, &v);
			if(u > v) swap(u, v);
			d[u]++;
			if(d[u] == 1) ans--;
		}
	}
	return 0;
}