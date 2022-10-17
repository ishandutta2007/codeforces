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
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define maxn 600005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, vis[maxn], vise[maxn];
vector<pii> G[maxn];
int sta[maxn], top;
int ans[maxn][2], now;
string st[2][2];
void dfs(int x)
{
	sta[++top] = x;
	if(vis[x]) return; vis[x] = 1;
	for (auto V: G[x]) if(!vise[V.second])
	{
		vise[V.second] = 1;
		dfs(V.first);
		sta[++top] = x;
	}
}
int main()
{
	n = read();
	ru(i, 1, n)
	{
		int x = read(), y = read();
		G[x].push_back(make_pair(y, i)), G[y].push_back(make_pair(x, i));
	}
	ru(i, 1, 2 * n) if(!vis[i] && !G[i].empty())
	{
		top = 0, dfs(i), top = (top - 1) / 2;
		if(top == 1) {printf("-1\n"); return 0;}
		ru(j, now + 1, now + top) 
		{
			ans[j][0] = sta[j - now];
			ans[j][1] = sta[2 * top - (j - now) + 1];
		}
		now += top;
		if(top & 1)
		{
			ru(j, 1, top / 2) st[0][0] += "LR", st[0][1] += "LR";
			st[0][0] += "U", st[0][1] += "D";
			st[1][0] += "U", st[1][1] += "D";
			ru(j, 1, top / 2) st[1][0] += "LR", st[1][1] += "LR";
		}
		else
		{
			ru(j, 1, top / 2) st[0][0] += "LR", st[0][1] += "LR";
			st[1][0] += "U", st[1][1] += "D";
			ru(j, 1, top / 2 - 1) st[1][0] += "LR", st[1][1] += "LR";
			st[1][0] += "U", st[1][1] += "D";
		}
	}
	cout<<2<<" "<<n<<endl;
	ru(i, 0, 1) {ru(j, 1, n) printf("%d ", ans[j][i]); printf("\n");}
	cout<<st[0][0]<<endl<<st[0][1]<<endl;
	cout<<st[1][0]<<endl<<st[1][1];
	return 0;
}