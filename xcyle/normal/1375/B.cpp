#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)

using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, a[305][305], m;
void solve()
{
	scanf("%d%d", &n, &m);
	int flag = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			int cnt = 0;
			if(i != 1) cnt++;
			if(i != n) cnt++;
			if(j != 1) cnt++;
			if(j != m) cnt++;
			if(a[i][j] > cnt) flag = 0;
			else a[i][j] = cnt; 
		}
	}
	if(!flag) printf("NO\n");
	else 
	{
		printf("YES\n");
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
} 
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}