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
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, C[maxn], tmp[maxn];
int ans[1005][1005], tot;
void work(int a, int b, int c, int d)
{
	tot++;
	if(a) ans[tot][++ans[tot][0]] = a;
	if(b) ans[tot][++ans[tot][0]] = b;
	if(c) ans[tot][++ans[tot][0]] = c;
	if(d) ans[tot][++ans[tot][0]] = d;
	int now = 0;
	ru(i, a + b + c + 1, a + b + c + d)
	{
		tmp[++now] = C[i];
	}
	ru(i, a + b + 1, a + b + c) tmp[++now] = C[i];
	ru(i, a + 1, a + b) tmp[++now] = C[i];
	ru(i, 1, a) tmp[++now] = C[i];
	ru(i, 1, n) C[i] = tmp[i];
}
void solve()
{
	n = read();
	ru(i, 1, n) C[i] = read(); 
	ru(i, 1, n)
	{
		rd(j, n, 1) if(C[j] != j)
		{
			int pos = 0;
			ru(k, 1, n) if(C[k] == C[j] + 1) pos = k;
			int tmp = pos;
			while(C[tmp + 1] == C[tmp] + 1) tmp++;
			work(pos - 1, tmp - pos + 1, j - tmp, n - j);
			break;
		}
//	printf("haha\n");
//	ru(i, 1, n) printf("%d ", C[i]); printf("\n");
	}
	printf("%d\n", tot);
	ru(i, 1, tot)
	{
		printf("%d ", ans[i][0]);
		ru(j, 1, ans[i][0]) printf("%d ", ans[i][j]); printf("\n");
	}
}
int main()
{
	solve(); 
	return 0;
}