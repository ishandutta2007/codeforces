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
int n, f[maxn][2], res[maxn], fl = 1, fat[maxn];
vector<int> G[maxn], G2[maxn], s[3];
inline int check(int a, int b, int c)
{
	if(a + c >= (a + b + c) / 2 && b + c >= (a + b + c + 1) / 2) return 1;
	return 0;
}
void dfs(int x, int fa)
{
	fat[x] = fa;
	for (auto V: G[x]) if(V ^ fa) dfs(V, x);
	s[0].clear(), s[1].clear(), s[2].clear();
	for (auto V: G[x]) if(V ^ fa)
	{
		if(f[V][0] ^ f[V][1]) s[f[V][1]].push_back(V);
		else s[2].push_back(V);
	}
	f[x][0] = check((int)s[0].size() + 1, s[1].size(), s[2].size());
	f[x][1] = check(s[0].size(), (int)s[1].size() + 1, s[2].size());
	if(!f[x][0] && !f[x][1]) fl = 0;
}
int d[maxn];
queue<int> q;
void work(int x, int fa, int st)
{
	s[0].clear(), s[1].clear(), s[2].clear();
	for (auto V: G[x]) if(V ^ fa)
	{
		if(f[V][0] ^ f[V][1]) s[f[V][1]].push_back(V);
		else s[2].push_back(V);
	}
	s[st].push_back(x);
	//printf("%d %d %d %d\n", x, s[0].size(), s[1].size(), s[2].size());
	for (int i = 1, las = 0, now; i <= (int)G[x].size(); i++)
	{
		if(s[i & 1].empty()) now = s[2].back(), s[2].pop_back();
		else now = s[i & 1].back(), s[i & 1].pop_back();
		G2[now].push_back(las), d[las]++;
		res[las = now] = (i & 1);
	}
	for (auto V: G[x]) if(V ^ fa) work(V, x, res[V]);
}
void solve()
{
	fl = 1;
	n = read(); for (int i = 1; i <= n; i++) f[i][0] = f[i][1] = d[i] = 0, G[i].clear(), G2[i].clear();
	for (int i = 1; i < n; i++)
	{
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (auto V: G[1]) dfs(V, 1);
	s[0].clear(), s[1].clear(), s[2].clear();
	for (auto V: G[1])
	{
		if(f[V][0] ^ f[V][1]) s[f[V][1]].push_back(V);
		else s[2].push_back(V);
	}
	if(!fl || !check(s[0].size(), s[1].size(), s[2].size())) printf("NO\n");
	else 
	{
		printf("YES\n");
		for (int i = 1, las = 0, now; i <= (int)G[1].size(); i++)
		{
			if(s[i & 1].empty()) now = s[2].back(), s[2].pop_back();
			else now = s[i & 1].back(), s[i & 1].pop_back();
			G2[now].push_back(las), d[las]++;
			res[las = now] = (i & 1);
		}
		for (auto V: G[1]) work(V, 1, res[V]);
		for (int i = 2; i <= n; i++) if(!d[i]) q.push(i);
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			if(x) printf("%d %d\n", x, fat[x]);
			for (auto V: G2[x])
			{
				d[V]--;
				if(!d[V]) q.push(V);
			}
		}
	}
}
int main() {int T = read(); while(T--) solve(); return 0;}