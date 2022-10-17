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
int n, a[maxn], sum = 0, fl = 0;
int num = 0;
void dfs(int step)
{
	if(step > n)
	{
		if(sum == 0 && num != n) fl = 1;
		return;
	}
	sum += a[step];
	dfs(step + 1);
	sum -= a[step];
	num++;
	dfs(step + 1);
	num--;
	sum -= a[step];
	dfs(step + 1);
	sum += a[step];
}
void solve()
{
	n = read();
	fl = 0;
	for (int i = 1; i <= n; i++) a[i] = read();
	dfs(1);
	if(!fl) printf("NO\n");
	else printf("YES\n"); 
}
int main()
{
	int T = read();
	while(T--) solve(); 
	return 0;
}