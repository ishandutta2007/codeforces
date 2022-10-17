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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int q, type;
ll x, y, w;
map<ll, long long> p;
void add(ll x, ll y, long long w)
{
	if(x == y) return;
	if(x < y) swap(x, y);
	if(p.find(x) == p.end()) p.insert(make_pair(x, 0));
	map<ll, long long>::iterator it = p.find(x);
	it->second += w;
	add(x / 2, y, w);
}
ll ans;
void que(ll x, ll y)
{
	if(x == y) return;
	if(x < y) swap(x, y);
	if(p.find(x) == p.end()) p.insert(make_pair(x, 0));
	map<ll, long long>::iterator it = p.find(x);
	ans += (it->second);
	que(x / 2, y);
}
int main()
{
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &type);
		scanf("%lld%lld", &x, &y);
		if(type == 1)
		{
			scanf("%lld", &w);
			add(x, y, w);
		}
		else
		{
			ans = 0;
			que(x, y);
			printf("%lld\n", ans);
		}
	}
	return 0;
}