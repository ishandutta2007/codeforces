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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[(1 << 21) + 1];
vector<int> ans;
vector<int> res;
void dfs(int step, int* vis)
{
	if(step >= 20)
	{
		if(ans.size() > res.size()) ans = res;
		return;
	}
//	printf("%d %d\n", step, res.size());
//	for (int i = 0; i <= (1 << (21 - step)); i++)
//	{
//		if(vis[i]) printf("%d ", i - (1 << (20 - step)));
//	}
//	printf("\n");
	int tmp[(1 << (20 - step)) + 1];
	int fl = 1;
	for (int i = 0; i <= (1 << (21 - step)); i++) if(vis[i] && (i & 1)) fl = 0;
	if(fl)
	{
		for (int i = 0; i <= (1 << (20 - step)); i++) tmp[i] = 0;
		for (int i = 0; i <= (1 << (21 - step)); i++) if(vis[i]) tmp[(i - (1 << (20 - step))) / 2 + (1 << (19 - step))] = 1;
		dfs(step + 1, tmp);
		return;
	}
	for (int i = 0; i <= (1 << (20 - step)); i++) tmp[i] = 0;
	for (int i = 0; i <= (1 << (21 - step)); i++) 
	{
		if(!vis[i]) continue;
		if(i % 2 == 0) tmp[(i - (1 << (20 - step))) / 2 + (1 << (19 - step))] = 1;
		else tmp[(i - (1 << (20 - step)) + 1) / 2 + (1 << (19 - step))] = 1;
	}
	res.push_back(-(1 << step));
	dfs(step + 1, tmp);
	res.pop_back();
	for (int i = 0; i <= (1 << (20 - step)); i++) tmp[i] = 0;
	for (int i = 0; i <= (1 << (21 - step)); i++) 
	{
		if(!vis[i]) continue;
		if(i % 2 == 0) tmp[(i - (1 << (20 - step))) / 2 + (1 << (19 - step))] = 1;
		else tmp[(i - (1 << (20 - step)) - 1) / 2 + (1 << (19 - step))] = 1;
	}
	res.push_back((1 << step));
	dfs(step + 1, tmp);
	res.pop_back();
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[(1 << 20) + read()] = 1;
	for (int i = 0; i <= 20; i++) ans.push_back((1 << i));
	dfs(0, a);
	printf("%d\n", ans.size());
	for (auto x: ans) printf("%d ", x);
	return 0;
}