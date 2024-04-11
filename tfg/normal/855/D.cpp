#include <iostream>
#include <cstdio>

const int me = 20;
const int ms = 100100;

int table[me][ms][3];
int height[ms];

int lca(int a, int b)
{
	if(a == b)
		return a;
	if(height[a] < height[b])
		std::swap(a, b);
	int diff = height[a] - height[b];
	for(int i = me - 1; i >= 0; i--)
	{
		if((diff & (1 << i)) != 0)
			a = table[i][a][2];
	}
	if(a == b)
		return a;
	for(int i = me - 1; i >= 0; i--)
	{
		if(table[i][a][2] != table[i][b][2])
		{
			a = table[i][a][2];
			b = table[i][b][2];
		}
	}
	return table[0][a][2];
}

int up(int a, int l, int t)
{
	int diff = height[a] - height[l];
	int ans = 0;
	for(int i = me - 1; i >= 0; i--)
	{
		if((diff & (1 << i)) != 0)
		{
			ans += table[i][a][t];
			a = table[i][a][2];
		}
	}
	return ans;
}

int main()
{
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int typ, par;
		//std::cin >> par >> typ;
		scanf("%d %d", &par, &typ);
		if(par != -1)
		{
			table[0][i][2] = par;
			table[0][i][typ]++;
		}
		else
		{
			table[0][i][2] = 0;
		}
		height[i] = height[table[0][i][2]] + 1;
	}
	for(int j = 0; j + 1 < me; j++)
	{
		for(int i = 0; i <= n; i++)
		{
			int to = table[j][i][2];
			table[j + 1][i][2] = table[j][to][2];
			for(int k = 0; k < 2; k++)
			{
				table[j + 1][i][k] += table[j][i][k];
				table[j + 1][i][k] += table[j][to][k];
			}
		}
	}
	int q;
	std::cin >> q;
	while(q--)
	{
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		//std::cin >> t >> u >> v;
		int l = lca(u, v);
		if(l == 0 || u == v)
		{
			std::cout << "NO\n";
		}
		else if(t == 1)
		{
			if(l == u && up(v, l, 0) == height[v] - height[u])
			{
				std::cout << "YES\n";
			}
			else
			{
				std::cout << "NO\n";
			}
		}
		else
		{
			if(l == v)
			{
				std::cout << "NO\n";
			}
			else if(l == u)
			{
				if(up(v, u, 1) == height[v] - height[u])
				{
					std::cout << "YES\n";
				}
				else
				{
					std::cout << "NO\n";
				}
			}
			else
			{
				if(up(v, l, 1) + up(u, l, 0) == height[v] + height[u] - 2 * height[l])
				{
					std::cout << "YES\n";
				}
				else
				{
					std::cout << "NO\n";
				}
			}
		}
	}
	
}