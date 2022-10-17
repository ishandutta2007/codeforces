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
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q;
void solve()
{
	n = read();
	vector<int> a, b;
	ru(i, 1, n) a.push_back(read());
	int cnt = 0;
	ru(i, 1, n - 1)
	{
		b.clear();
		int las = -1;
		if(cnt) cnt--, las = 0;
		for (auto x: a)
		{
			if(las != -1) 
			{
				if(x == las) cnt++;
				else b.push_back(x - las);
			}
			las = x;
		}
		a = b, sort(a.begin(), a.end());
	}
	if(cnt) printf("0\n");
	else printf("%d\n", a[0]);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}