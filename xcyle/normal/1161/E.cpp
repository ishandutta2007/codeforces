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
#define maxn 100005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, fa[maxn];
char s[maxn];
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
vector<int> rem;
int vis[maxn];
int p[3][maxn], col[maxn];
vector<int> ans[3];
void work(int t, int beg)
{
	for (int i = beg; i < rem.size(); i++) vis[i] = 0;
	int cnt = 0;
	for (int i = beg; i < rem.size(); i++)
	{
		if(!vis[i] && !vis[i + t] && i + t < rem.size())
		{
			cnt++;
			vis[i] = vis[i + t] = 1;
		}
	}
	if(cnt == 0) return;
	printf("Q %d ", cnt);
	fflush(stdout);
	for (int i = beg; i < rem.size(); i++) vis[i] = 0;
	for (int i = beg; i < rem.size(); i++)
	{
		if(!vis[i] && !vis[i + t] && i + t < rem.size())
		{
			printf("%d %d ", rem[i], rem[i + t]);
			fflush(stdout);
			vis[i] = vis[i + t] = 1;
		}
	}
	printf("\n");
	fflush(stdout);
	scanf("%s", s + 1);
	for (int i = beg; i < rem.size(); i++) vis[i] = 0;
	int now = 0;
	for (int i = beg; i < rem.size(); i++)
	{
		if(!vis[i] && !vis[i + 2] && i + 2 < rem.size())
		{
			p[t][i + 2] = s[++now] - '0';
			vis[i] = vis[i + 2] = 1;
		}
	}
}
void solve()
{
	scanf("%d", &n);
	rem.clear();
	for (int i = 0; i < 3; i++) ans[i].clear();
	for (int i = 1; i <= n; i++) fa[i] = i;
	
	if(n >= 2){
	printf("Q %d ", n / 2);
	fflush(stdout);
	for (int i = 1; i + 1 <= n; i += 2)
	{
		printf("%d %d ", i, i + 1);
	fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	scanf("%s", s + 1);
	for (int i = 1; i + 1 <= n; i += 2)
	{
		if(s[(i + 1) / 2] == '1') fa[i + 1] = find(i);
	}
}
if(n >= 3){
	printf("Q %d ", n - 1 - (n / 2));
	fflush(stdout);
	for (int i = 2; i + 1 <= n; i += 2)
	{
		printf("%d %d ", i, i + 1);
	fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	scanf("%s", s + 1);
	for (int i = 2; i + 1 <= n; i += 2)
	{
		if(s[i / 2] == '1') fa[i + 1] = find(i);
	}
	}
	
	for (int i = 1; i <= n; i++)
	{
		if(find(i) == i) rem.push_back(i);
	}
	
	work(2, 0);
	work(2, 2);
	
	col[rem[0]] = 0;
	if(rem.size() > 1) col[rem[1]] = 1;
	for (int i = 2; i < rem.size(); i++)
	{
		if(p[2][i]) 
		{
			col[rem[i]] = col[rem[i - 2]]; 
		} 
		else col[rem[i]] = (3 ^ col[rem[i - 2]] ^ col[rem[i - 1]]);
	}
	int now = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[col[find(i)]].push_back(i);
	}
	printf("A %d %d %d\n", ans[0].size(), ans[1].size(), ans[2].size());
	fflush(stdout);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < ans[i].size(); j++) 
		{
			printf("%d ", ans[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0; 
}