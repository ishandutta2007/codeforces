/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, l, r) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n;
vector<int> pos[maxn];
inline int cmp(int x, int y)
{
	return pos[x].size() > pos[y].size();
}
int id[maxn], ans[maxn];
void solve()
{
	n = read();
	for (int i = 1; i <= n + 1; i++) pos[i].clear();
	for (int i = 1; i <= n; i++) pos[read()].push_back(i);
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= pos[id[1]].size(); i++)
	{
		for (int j = 2; j <= n + 1; j++)
		{
//			printf("%d ", pos[id[j - 1]][i - 1]);
			if(pos[id[j]].size() >= i)
			{
				ans[pos[id[j]][i - 1]] = id[j - 1];
			}
			else
			{
				ans[pos[id[1]][i - 1]] = id[j - 1];
				break;
			}
		}
//		printf("\n");
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}