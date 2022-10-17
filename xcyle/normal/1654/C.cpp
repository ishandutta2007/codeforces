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
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
map<ll, int> s;
multiset<ll> now;
multiset<ll>::iterator it;
void solve()
{
	s.clear(), now.clear();
	n = read();
	ll sum = 0;
	for (int i = 1; i <= n; i++) s[a[i] = read()]++, sum += a[i];
	now.insert(sum);
	int ans = 0;
	for (int i = 1; (!now.empty()) && i <= 4 * n; i++)
	{
		it = now.end(); it--;
		ll x = (*it); now.erase(it);
		if(s[x] != 0) s[x]--, ans++;
		else
		{
			now.insert(x / 2);
			now.insert(x - x / 2);
		}
	}
	if(ans == n) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}