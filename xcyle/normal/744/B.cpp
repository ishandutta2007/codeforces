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
int n;
int ans[maxn];
int main()
{
	n = read();
	ru(i, 1, n) ans[i] = 1e9 + 1;
	ru(i, 0, 9)
	{
		ru(j, 0, 1)
		{
			vector<int> t; t.clear();
			ru(k, 1, n) if(((k >> i) & 1) == j) t.push_back(k);
			if(t.empty()) continue; 
			printf("%d\n", t.size());
			for (auto x: t) printf("%d ", x);
			printf("\n");
			fflush(stdout);
			ru(k, 1, n) 
			{
				int x = read();
				if(((k >> i) & 1) != j) ans[k] = min(ans[k], x);
			}
		}
	}
	printf("-1\n");
	ru(i, 1, n) printf("%d ", ans[i]);
	fflush(stdout);
	return 0;
}