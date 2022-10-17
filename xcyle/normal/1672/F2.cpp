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
#define rd(i, l, r) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 200005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, cnt[maxn], a[maxn], b[maxn], vis[maxn], d[maxn];
vector<int> G[maxn];
queue<int> q;
void solve()
{
	n = read();
	ru(i, 1, n) G[i].clear(), d[i] = vis[i] = cnt[i] = 0;
	ru(i, 1, n) a[i] = read(), cnt[a[i]]++, d[a[i]]++;
	ru(i, 1, n) b[i] = read();
	ru(i, 1, n) G[a[i]].push_back(b[i]);
	int mx = 0, pos = 0, fl = 1;
	ru(i, 1, n) if(cnt[i] > mx) mx = cnt[i], pos = i;
	while(1)
	{
		//printf("%d %d\n", mx, pos);
		vis[pos] = pos, d[pos] = 0;
		q.push(pos);
		int nxt = 0;
		while(!q.empty())
		{
			int x = q.front(); q.pop();
			for (auto V: G[x])
			{
				if(cnt[V] == mx)
				{
					if(nxt && nxt != V) fl = 0;
					nxt = V;
					continue;
				}
				if(vis[V] && vis[V] != pos) fl = 0;
				vis[V] = pos, d[V]--;
				if(!d[V]) q.push(V);//printf("%d %d\n", V, d[V]);
			}
		}
		if(!nxt) {fl = 0; break;}
		if(vis[nxt]) break;
		pos = nxt;
	}
	ru(i, 1, n) fl &= (!d[i]);
	if(!fl) printf("WA\n");
	else printf("AC\n");
}
int main()
{
	int T = read(); while(T--) solve();
	return 0;
}