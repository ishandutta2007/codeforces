#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1)
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
int Tc;
int n, a[maxn], flag;
int ans[maxn], cnt;
void work(int x)
{
	ans[++cnt] = x;
	int tmp = a[x] ^ a[x + 1] ^ a[x + 2];
	a[x] = a[x + 1] = a[x +2] = tmp; 
}
void solve()
{
	cnt = 0;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		 a[i] = read();
		 sum += a[i];
	}
	if(sum & 1)
	{
		printf("NO\n");
		return; 
	}
	sum = 0, flag = 0;
	for (int i = 1; i <= n; i++)
	{
		sum ^= a[i];
		if(sum == 0 && a[i] == 0) flag = i;
	}
	if(!flag)
	{
		int last = 1;
		for (int i = 1; i <= n; i++)
		{
			if(a[i] && ((i - last) & 1)) flag = i - 1;
			if(a[i]) last = i + 1;
		}
		if(!flag)
		{
			printf("NO\n");
			return;
		}
		for(; !a[flag - 1]; flag -= 2) work(flag - 1);
		work(flag - 1);
		flag--;
	}
	for (int i = flag - 1; i >= 1; i--)
	{
		if(!a[i]) continue;
		if(a[i - 1]) work(i - 1);
		else
		{
			work(i - 2);
			if(a[i] == 1) work(i - 1);
		}
	}
	for (int i = flag + 1; i <= n; i++)
	{
		if(!a[i]) continue;
		if(a[i + 1]) work(i - 1);
		else
		{
			work(i);
			if(a[i] == 1) work(i - 1);
		}
	}
	printf("YES\n%d\n", cnt);
	for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	Tc = read();
	while(Tc--) solve();
	return 0;
}