
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
int n, vis[maxn], a[maxn], b[maxn], posb[maxn];
vector<int> len;
void solve()
{
	n = read(); ru(i, 1, n) a[i] = read(); ru(i, 1, n) posb[b[i] = read()] = i;
	ru(i, 1, n) vis[i] = 0; len.clear();
	ru(i, 1, n) if(!vis[i])
	{
		int now = i, cnt = 0;
		while(!vis[now])
		{
			vis[now] = 1;
			now = posb[a[now]];
			cnt++;
		}
		len.push_back(cnt);
	}
	sort(len.begin(), len.end(), greater<int>());
	ll ans = 0;
	for (auto x: len)
	{
//		printf("%d ", x);
		ru(i, 1, x / 2) ans += (n + 1 - 2 * i) * 2;
		n -= (x / 2) * 2;
	}
	printf("%lld\n", ans);
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}