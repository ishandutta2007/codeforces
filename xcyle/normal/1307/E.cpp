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
#define mid ((l + r + 1) >> 1)
#define maxn 5005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, s[maxn];
int sum[maxn][maxn];
int Lcnt[maxn], Rcnt[maxn];
void solve()
{
	n = read(), m = read();
	ru(i, 1, n) Rcnt[s[i] = read()]++; 
	ru(i, 1, m) sum[read()][read()]++;
	ru(i, 1, n) ru(j, 1, n) sum[i][j] += sum[i][j - 1];
	int mx = 0, num = 1;
	ru(i, 1, n) if(sum[i][Rcnt[i]]) mx++, num = (ll)num * sum[i][Rcnt[i]] % mo;
	ru(i, 1, n)
	{
		Lcnt[s[i]]++, Rcnt[s[i]]--;
		if(sum[s[i]][Lcnt[s[i]]] == sum[s[i]][Lcnt[s[i]] - 1]) continue;
		int rem = sum[s[i]][Rcnt[s[i]]];
		if(Lcnt[s[i]] <= Rcnt[s[i]]) rem--;
		int tmx = 1, tnum = 1;
		if(rem) tmx++, tnum = (ll)tnum * rem % mo;
		ru(j, 1, n) if(s[i] ^ j)
		{
			int x = Lcnt[j], y = Rcnt[j];
			if(x > y) swap(x, y);
			if(!sum[j][y]) continue;
			if(sum[j][x] && sum[j][y] > 1)
			{
			    tmx += 2, tnum = (ll)tnum * sum[j][x] % mo * (sum[j][y] - 1) % mo;
			}
			else
			{
				int tmp = sum[j][y] + (sum[j][x] > 0 ? sum[j][x] : 0);
				tmx++, tnum = (ll)tnum * tmp % mo;
			}
		}
//		printf("%d %d\n", tmx, tnum);
		if(tmx > mx) mx = tmx, num = tnum;
		else if(mx == tmx) num = (num + tnum) % mo; 
	}
	printf("%d %d\n", mx, num);
}
int main()
{
	solve();
	return 0;
}