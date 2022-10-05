#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 53, p = 1e9 + 7;
int n, ct, ans, maxi, fa[Maxn], id[Maxn], siz[Maxn];
string G[Maxn];
long long w[1 << 23 | 5], f[1 << 23 | 5], g[1 << 23 | 5];
bool M[Maxn][Maxn];
void FWT(long long now[], int len, bool type = false)
{
	for (int i = 1; i < len; i <<= 1)
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
				now[i + k] += type ? p - now[k] : now[k];
	for (int i = 0; i < len; i++) now[i] %= p;
}
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a != b)
	{
		fa[a] = b;
		siz[b] += siz[a];
	}	
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		string tmp;
		cin >> tmp;
		G[i] = ' ' + tmp;
		for (int j = 1; j <= n; j++)
			if (G[i][j] == 'A') merge(i, j);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (get_fa(i) == get_fa(j) && G[i][j] == 'X')
			{
				puts("-1");
				return 0;
			}
	for (int i = 1; i <= n; i++)
		if (get_fa(i) == i && siz[i] != 1) id[i] = ct++, ans += siz[i];
		else if (get_fa(i) == i) ans++;
	if (!ct)
	{
		printf("%d", ans - 1);
		return 0;
	}
	//siz  1  
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (G[i][j] == 'X' && siz[get_fa(i)] > 1 && siz[get_fa(j)] > 1) M[id[get_fa(i)]][id[get_fa(j)]] = true; 
	// siz[get_fa(i)] > 1 && siz[get_fa(j)] > 1 
	maxi = 1 << ct;
	for (int i = 0; i < ct; i++) f[1 << i] = true; 
	for (int i = 1; i < maxi; i++)
	{
		if (!f[i]) continue;
		for (int j = 0; j < ct; j++)
			if (!(i & (1 << j)))
			{
				for (int k = 0; k < ct; k++)
					if ((i & (1 << k)) && M[j][k]) goto END;
				f[i ^ (1 << j)] = 1;
				END:;
			}
	}
	for (int i = 0; i < maxi; i++)
		w[i] = ((ct - __builtin_popcount(i)) & 1) ? p - 1 : 1;
	// 
	FWT(f, maxi);
	for (int i = 0; i < maxi; i++) g[i] = 1;
	for (int i = 0; i <= n; i++)
	{
		long long tmp = 0;
		for (int j = 0; j < maxi; j++)
			(g[j] *= f[j]) %= p, (tmp += w[j] * g[j]) %= p;
		if (tmp)
		{
			printf("%d", ans + i);
			return 0;
		}
	}
	return 0;
}