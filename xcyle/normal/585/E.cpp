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
#define maxn 10000005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n;
int ans = 0;
int t[maxn];
int prime[maxn], cnt, vis[maxn], miu[maxn], poww[maxn];
int main()
{
	scanf("%d", &n);
	poww[0] = 1;
	for (int i = 1; i < maxn; i++) poww[i] = poww[i - 1] * 2 % mo;
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		t[x]++;
	}
	miu[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		if(!vis[i])
		{
			prime[++cnt] = i;
			miu[i] = -1;
		}
		for (int j = 1; j <= cnt && i * prime[j] < maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
			miu[i * prime[j]] = -miu[i];
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = (maxn - 1) / prime[i]; j >= 1; j--)
		{
			t[j] += t[j * prime[i]];
		}
	}
	for (int i = 1; i < maxn; i++)
	{
		if(!t[i]) continue;
		int tmp = (mo - (ll)(poww[t[i]] + mo - 1) * n % mo + (ll)2 * poww[t[i] - 1] % mo * t[i] % mo) % mo;
//		printf("%d\n", tmp);
		tmp = (tmp * miu[i] + mo) % mo;
		ans = (ans + tmp) % mo;
	}
	printf("%d\n", ans);
	return 0;
}