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
#define maxn 100005
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
int n, d, m, a[maxn];
int main()
{
	scanf("%d%d%d", &n, &d, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	long long ans = 0;
	int flag = n + 1;
	for (int i = 1; i <= n; i++)
	{
		if(a[i] > m)
		{
			flag = i;
			break;
		}
		ans += a[i];
	}
	long long res = ans;
	int lev = 0;
	for (int i = n; i >= flag; i--)
	{
		int cnt = (n - i) * d - (i - flag);
//		printf("%d\n", cnt);
		if(cnt >= flag) break;
		if(cnt > lev)
		{
			for (int j = lev + 1; j <= cnt; j++) ans -= a[j];
			lev = cnt;
		}
		ans += a[i];
		res = max(res, ans);
//		printf("%d\n", i);
	} 
	printf("%lld\n", res);
	return 0;
}