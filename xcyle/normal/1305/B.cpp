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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
int n, cnt[2];
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int ans = n, pos = 0;
	ru(i, 0, n)
	{
		int cntl = 0, cntr = 0;
		ru(j, 1, i) if(s[j] == '(') cntl++;
		ru(j, i + 1, n) if(s[j] == ')') cntr++;
		if(cntl == cntr)
		{
			if(cntl == 0)
			{
				printf("0\n");
				return 0;
			}
			printf("1\n%d\n", 2 * cntl);
			ru(j, 1, i) if(s[j] == '(') printf("%d ", j);
			ru(j, i + 1, n) if(s[j] == ')') printf("%d ", j);
			return 0;
		}
	}
	return 0;
}