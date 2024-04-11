#include <iostream>
#include <cstdio>
#define maxn 1005
using namespace std;
int n, p[maxn], id[maxn], flag = 1, a[maxn][maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &p[i]);
		id[i] = i;
		if(i != p[i]) flag = 0;
	}
	if(flag) printf("%d\n", n);
	else
	{
		int l = 1, r = n;
		for (int i = n; i >= 1; i--)
		{
			if(!((n - i) & 1))
			{
				while(l == p[id[l]] && l < r) l++; 
				if(l >= r) break;
				int x = p[id[l]];
				a[i][l] = a[i][x] = a[i][r] = 1;
				id[r] = id[x], id[x] = id[l];
				if(x == r) r--;
			}
			else
			{
				while(r == p[id[r]] && l < r) r--; 
				if(l >= r) break;
				int x = p[id[r]];
				a[i][r] = a[i][x] = a[i][l] = 2;
				id[l] = id[x], id[x] = id[r];
				if(x == l) l++;
			}
		}
		printf("%d\n", n - 1);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(!a[i][j]) printf(".");
			else if(a[i][j] == 1) printf("/");
			else printf("\\");
		}
		printf("\n");
	}
	return 0;
}