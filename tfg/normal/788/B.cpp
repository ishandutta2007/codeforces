#include <iostream>
#include <cstdio>

const int ms = 1001000;

int par[ms];
int size[ms];
bool visit[ms];

int get_par(int x)
{
	if(x == par[x])
		return x;
	else
		return par[x] = get_par(par[x]);
}

void make_union(int a, int b)
{
	par[get_par(a)] = get_par(b);
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	for(int i=1;i<=n;i++)
		par[i] = i;
	int temp;
	long long ans = 0;
	int count = 1;
	for(int i=0;i<m;i++)
	{
		int u, v;
		scanf("%i %i", &u, &v);
		visit[u] = visit[v] = true;
		temp = v;
		if(u == v)
		{
		    ans += m - count;
		    count++;
		    continue;
		}
		ans += size[u] + size[v];
		size[u]++;
		size[v]++;
		make_union(u, v);
	}
	for(int i=1;i<=n;i++)
	{
		if(visit[i] && get_par(i) != get_par(temp))
			ans = 0;
	}
	std::cout << ans << '\n';
}