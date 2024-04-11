/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
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
int n, k, m, a[maxn], cnt[maxn];
int b[maxn], cnt2[maxn];
int main()
{
	scanf("%d%d%d", &n, &k, &m);
	int tmp = n;
	n = 0;
	for (int i = 1; i <= tmp; i++) 
	{
		scanf("%d", &a[++n]);
		cnt[n] = cnt[n - 1];
		if(a[n] != a[n - 1]) cnt[n] = 0;
		cnt[n]++;
		if(cnt[n] == k) n -= k;
	}
	if(m == 1)
	{
		printf("%d\n", n);
		return 0;
	}
	int l = 1, r = n, ttp = 0;
	while(1)
	{
		if(a[l] != a[r]) break;
		int flag = 1;
		for (int i = l + 1; i <= r; i++)
		{
			if(a[i] != a[i - 1]) flag = 0;
		}
		if(flag)
		{
			ll tot = (ll)m * (r - l + 1);
			if(tot % k != 0)
			{
				printf("%lld\n", tot % k + l - 1 + (n - r));
			}
			else
			{
				int tmp = n;
				n = 0;
				for (int i = 1; i <= l - 1; i++) 
				{
					b[++n] = a[i];
					cnt[n] = cnt[n - 1];
					if(b[n] != b[n - 1]) cnt[n] = 0;
					cnt[n]++;
					if(cnt[n] == k) n -= k;
				}
				for (int i = r + 1; i <= tmp; i++)
				{
					b[++n] = a[i];
					cnt[n] = cnt[n - 1];
					if(b[n] != b[n - 1]) cnt[n] = 0;
					cnt[n]++;
					if(cnt[n] == k) n -= k;
				}
				printf("%d\n", n);
			}
			return 0;
		}
		int tl = l + 1, tr = r - 1;
		while(a[tl] == a[tl - 1]) tl++;
		while(a[tr] == a[tr + 1]) tr--;
		if((tl - l + r - tr) % k == 0)
		{
			l = tl, r = tr;
		}
		else
		{
			ttp = (tl - l + r - tr) / k * k;
			break;
		}
	}
	printf("%lld\n", (l - 1 + n - r) + (ll)m * (r - l + 1) - (ll)(m - 1) * ttp);
	return 0;
}