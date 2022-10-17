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
#define maxn 200005
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
int T, n;
void solve()
{
	scanf("%d", &n);
	if(n == 1)
	{
		 printf("-1\n");
		 return;
	}
	int flag = n - 1;
	if((n - 1) % 3 == 0) flag = n - 2;
	for (int i = 1; i <= flag; i++)
	{
		printf("5");
	}
	for (int i = flag + 1; i <= n; i++) printf("3");
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}