/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 10005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
ll h[maxn];
vector<int> pre, suf;
ll l[maxn], r[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		pre.clear(), suf.clear();
		pre.push_back(i);
		for (int j = i - 1; j >= 1; j--)
		{
			if(h[j] < h[pre.back()]) pre.push_back(j);
		}
		pre.push_back(0);
		suf.push_back(i);
		for (int j = i + 1; j <= n; j++)
		{
			if(h[j] < h[suf.back()]) suf.push_back(j);
		}
		suf.push_back(n + 1);
		l[suf[1] - 1] = max(l[suf[1] - 1], h[i] * (suf[1] - pre[1] - 1));
		r[pre[1] + 1] = max(r[pre[1] + 1], h[i] * (suf[1] - pre[1] - 1));
		int now = suf.size() - 1;
		ll tmp = 0;
//		printf("! %d\n", i);
		for (int j = 0; j <= pre.size() - 2; j++)
		{
			while(now && h[pre[j]] + h[suf[now - 1]] <= h[i])
			{
				now--;
				tmp = max(tmp, h[suf[now]] * (suf[now + 1] - pre[1] - 1));
			}
			tmp = max(tmp, (h[i] - h[pre[j]]) * (suf[now] - pre[1] - 1));
//			printf("%d %d %lld %lld\n", pre[j], suf[now], tmp, ans);
			ans = max(ans, h[pre[j]] * (suf[1] - pre[j + 1] - 1) + tmp);
		}
		now = 0;
		for (int j = 0; j <= pre.size() - 2; j++)
		{
			while(now <= suf.size() - 2 && h[suf[now + 1]] >= h[pre[j]]) now++;
			ans = max(ans, h[pre[j]] * (suf[now + 1] - pre[j + 1] - 1) + (h[i] - h[pre[j]]) * (suf[1] - pre[1] - 1));
		}
	}
	for (int i = 1; i <= n; i++)
	{
		l[i] = max(l[i], l[i - 1]);
		ans = max(ans, l[i] + r[i + 1]);
	}
	for (int i = 1; i <= n / 2; i++) swap(h[i], h[n - i + 1]);
	for (int i = 1; i <= n; i++)
	{
		pre.clear(), suf.clear();
		pre.push_back(i);
		for (int j = i - 1; j >= 1; j--)
		{
			if(h[j] < h[pre.back()]) pre.push_back(j);
		}
		pre.push_back(0);
		suf.push_back(i);
		for (int j = i + 1; j <= n; j++)
		{
			if(h[j] < h[suf.back()]) suf.push_back(j);
		}
		suf.push_back(n + 1);
		int now = suf.size() - 1;
		ll tmp = 0;
//		printf("! %d\n", i);
		for (int j = 0; j <= pre.size() - 2; j++)
		{
			while(now && h[pre[j]] + h[suf[now - 1]] <= h[i])
			{
				now--;
				tmp = max(tmp, h[suf[now]] * (suf[now + 1] - pre[1] - 1));
			}
			tmp = max(tmp, (h[i] - h[pre[j]]) * (suf[now] - pre[1] - 1));
//			printf("%d %d %lld %lld\n", pre[j], suf[now], tmp, ans);
			ans = max(ans, h[pre[j]] * (suf[1] - pre[j + 1] - 1) + tmp);
		}
		now = 0;
		for (int j = 0; j <= pre.size() - 2; j++)
		{
			while(now <= suf.size() - 2 && h[suf[now + 1]] >= h[pre[j]]) now++;
			ans = max(ans, h[pre[j]] * (suf[now + 1] - pre[j + 1] - 1) + (h[i] - h[pre[j]]) * (suf[1] - pre[1] - 1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}