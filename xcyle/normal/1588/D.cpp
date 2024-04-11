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
#define maxn 105
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, f[200005], len[maxn], last[200005], las[maxn][maxn][maxn], rnk[maxn][maxn];
char s[maxn][maxn];
inline int id(char c)
{
	if(c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}
int pos[maxn];
void dfs(int st)
{
//	printf("%d\n", st);
//	for (int i = 1; i <= n; i++) printf("%d ", pos[i]);
//	printf("\n");
//	int tmpp = (1 << n) * id(s[1][pos[1]]);
//	for (int j = 1; j <= n; j++) tmpp += (1 << (j - 1)) * rnk[j][pos[j]];
//	printf("check: %d\n", tmpp);
	last[st] = -1;
	f[st] = 1;
	int tmp[15];
	for (int i = 1; i <= n; i++) tmp[i] = pos[i];
	for (int i = 0; i < 54; i++)
	{
		int flag = 1, nxtst = (1 << n) * i;
//		for (int j = 1; j <= n; j++) printf("%d ", pos[j]);
//		printf("\n");
		for (int j = 1; j <= n; j++)
		{
			pos[j] = las[j][pos[j] - 1][i];
			if(!pos[j]) flag = 0;
			nxtst += (1 << (j - 1)) * rnk[j][pos[j]];
		}
//		printf("! %d %d\n", i, nxtst);
//		for (int j = 1; j <= n; j++) printf("%d ", pos[j]);
//		printf("\n");
		if(flag)
		{
			if(!f[nxtst]) dfs(nxtst);
			if(f[nxtst] + 1 > f[st])
			{
				f[st] = f[nxtst] + 1;
				last[st] = nxtst;
			}
		}
		for (int j = 1; j <= n; j++) pos[j] = tmp[j];
	}
}
void out(int st)
{
	if(st == -1) return;
	out(last[st]);
	int num = st / (1 << n);
	if(num < 26) printf("%c", 'A' + num);
	else printf("%c", 'a' + num - 26);
}
void solve()
{
	for (int i = 0; i <= 200000; i++) f[i] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		len[i] = strlen(s[i] + 1);
		for (int j = 0; j < maxn; j++) las[i][0][j] = 0;
		for (int j = 1; j <= len[i]; j++)
		{
			rnk[i][j] = las[i][j - 1][id(s[i][j])] ? 1 : 0;
			for (int k = 0; k < maxn; k++) las[i][j][k] = las[i][j - 1][k];
			las[i][j][id(s[i][j])] = j;
//			printf("%d %d: ", i, j);
//			for (int k = 0; k <= 40; k++) printf("%d ", las[i][j][k]);
//			printf("\n");
		}
	}
	for (int i = 1; i <= n; i++) pos[i] = len[i] + 1;
	dfs(200000);
	printf("%d\n", f[200000] - 1);
	out(last[200000]);
	putchar('\n');
}
int main()
{
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}