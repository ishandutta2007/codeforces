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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], b[maxn], vis[maxn];
vector<int> buc;
void solve()
{
	n = read(), k = read();
	for (int i = 1; i <= 2 * n; i++) vis[i] = 0;
	for (int i = 1; i <= k; i++)
	{
		a[i] = read(), b[i] = read();
		vis[a[i]] = vis[b[i]] = 1;
		if(a[i] > b[i]) swap(a[i], b[i]);
	}
	buc.clear();
	for (int i = 1; i <= 2 * n; i++)
	{
		if(!vis[i]) buc.push_back(i);
	}
	for (int i = 1; i <= n - k; i++)
	{
		a[k + i] = buc[i - 1], b[k + i] = buc[i + n - k - 1];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			if(a[i] <= a[j] && a[j] <= b[i] && b[i] <= b[j]) cnt++; 
		}
	}
	printf("%d\n", cnt);
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}