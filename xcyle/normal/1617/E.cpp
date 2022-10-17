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
#include <unordered_map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
inline int val(int x, int k){if(k == 31) return 0; return ((x >> k) & 1);}
unordered_map<int, int> ch[maxn * 35];
int t[maxn * 35], id[maxn * 35], tot, x, y, ans;
inline void upd(int tx, int ty, int tans)
{
	if(ans < tans) x = tx, y = ty, ans = tans;
}
void dfs(int x, int dep)
{
	int tmp= id[x];
	for (auto i: ch[x])
	{
		int V = i.second;
		dfs(V, dep + 1);
		if(tmp) upd(tmp, id[V], t[V] + (dep != 1));
		if(t[V] + (dep != 1) > t[x])
		{
			t[x] = t[V] + (dep != 1);
			id[x] = id[V];
		}
//		printf("%d %d %d %d\n", x, V, dep, i.first);
	}
//	printf("!!!! %d %d\n", x, t[x]);
	for (auto i: ch[x])
	{
		int V1 = i.second;
		for (auto j: ch[x])
		{
			int V2 = j.second;
			if(V1 == V2) continue;
			upd(id[V1], id[V2], t[V1] + t[V2] + 2 * (dep != 1));
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		if(!a[i]) {id[0] = i; continue;}
		int pos = 0, now = 0;
		for (int j = 30; j >= 0; j--) if(val(a[i], j)) pos = j;
		if(!ch[now][pos]) ch[now][pos] = ++tot;
		now = ch[now][pos];
		a[i] -= (1 << pos);
		if(!a[i]) {id[now] = i; continue;}
		int cnt = 0;
		for (int j = pos + 1; j <= 31; j++) if(val(a[i], j) != val(a[i], j - 1)) cnt ^= 1;
		if(!ch[now][cnt]) ch[now][cnt] = ++tot;
		now = ch[now][cnt];
		int las = pos + 1;
		for (int j = pos + 2; j <= 31; j++)
		{
			if(val(a[i], j) != val(a[i], j - 1))
			{
				int to = j - las;
				if(!ch[now][to]) ch[now][to] = ++tot;
				now = ch[now][to]; 
				las = j - 1;
			}
		}
		id[now] = i;
	}
	dfs(0, 0);
	printf("%d %d %d\n", x, y, ans);
	return 0;
}