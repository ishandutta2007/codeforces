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
#define maxn 1005
using namespace std;
const ll INF = 1e16;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int k, tot, siz[maxn], ch[maxn][14], fail[maxn], n;
char s[400005];
vector<int> G[maxn];
void insert(int val)
{
	int len = strlen(s + 1), now = 0;
	for (int i = 1; i <= len; i++)
	{
		int k = s[i] - 'a';
		if(!ch[now][k]) ch[now][k] = ++tot;
		now = ch[now][k];
	}
	siz[now] += val;
}
void get_fail()
{
	queue<int> q;
	for (int i = 0; i < 14; i++) if(ch[0][i]) q.push(ch[0][i]), G[0].push_back(ch[0][i]);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = 0; i < 14; i++)
		{
			if(!ch[u][i]) ch[u][i] = ch[fail[u]][i];
			else G[ch[fail[u]][i]].push_back(ch[u][i]), fail[ch[u][i]] = ch[fail[u]][i], q.push(ch[u][i]);
		}
	}
}
void dfs(int x) {for (auto V: G[x]) siz[V] += siz[x], dfs(V);}
int to[20][maxn], cnt = 1;
ll f[20][maxn], dp[2][(1 << 14)][maxn];
int main()
{
	int k = read();
	while(k--)
	{
		scanf("%s", s + 1);
		insert(read()); 
	}
	get_fail();
	dfs(0);
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 0; i <= tot; i++) to[1][i] = i, f[1][i] = siz[i];
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == '?')
		{
			cnt++;
			for (int j = 0; j <= tot; j++) to[cnt][j] = j, f[cnt][j] = siz[j];
		}
		else
		{
			for (int j = 0; j <= tot; j++) to[cnt][j] = ch[to[cnt][j]][s[i] - 'a'], f[cnt][j] += siz[to[cnt][j]];
		}
	}
	int las = 0, now = 1;
	for (int j = 0; j < (1 << 14); j++) for (int k = 0; k < maxn; k++) dp[las][j][k] = -INF;
	dp[0][0][0] = 0;
	for (int i = 1; i < cnt; i++)
	{
		for (int j = 0; j < (1 << 14); j++) for (int k = 0; k < maxn; k++) dp[now][j][k] = -INF;
		for (int j = 0; j < (1 << 14); j++)
		{
			for (int k = 0; k <= tot; k++)
			{
				if(dp[las][j][k] == -INF) continue;
				for (int l = 0; l < 14; l++)
				{
					if((j >> l) & 1) continue;
					int nxt = ch[to[i][k]][l];
					dp[now][j ^ (1 << l)][nxt] = max(dp[now][j ^ (1 << l)][nxt], dp[las][j][k] + f[i][k]);
				}
			}
		}
		swap(las, now);
	}
	ll ans = -INF;
	for (int i = 0; i < (1 << 14); i++) for (int j = 0; j <= tot; j++)
	{
		ans = max(ans, dp[las][i][j] + f[cnt][j]);
	}
	printf("%lld", ans);
	return 0;
}