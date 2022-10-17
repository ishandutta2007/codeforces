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
#define maxn 505
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], b[maxn];
vector<pii> ans;
void work(int l, int r)
{
	ans.push_back(mp(l, r));
	ru(i, l, (l + r) / 2) swap(a[i], a[l + r - i]);
}
void solve()
{
	n = read(); ans.clear();
	ru(i, 1, n) a[i] = read();
	ru(i, 1, n) b[i] = read();
	if(a[1] != b[1] || a[n] != b[n]) {printf("NO\n"); return;}
	ru(i, 2, n)
	{
		if(a[i] == b[i]) continue;
		ru(j, i + 2, n) if(a[i - 1] == a[j] && b[i] == a[j - 1])
		{
			work(i - 1, j);
			break;
		}
		if(a[i] == b[i]) continue;    
		ru(j, i, n - 1) if(a[i - 1] == a[j] && b[i] == a[j + 1])
		{
			int x = 0, y = 0;
			ru(k, i - 1, j) ru(l, j + 1, n)
			{
				if(a[k] == a[l]) x = k, y = l;
			}
			if(x) work(x, y);
			break;
		} 
		ru(j, i + 2, n) if(a[i - 1] == a[j] && b[i] == a[j - 1])
		{
			work(i - 1, j);
			break;
		}
		if(a[i] != b[i]) {printf("NO\n"); return;}
	}
	printf("YES\n%d\n", (int)ans.size());
	for (auto x: ans) printf("%d %d\n", x.fi, x.se);
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}