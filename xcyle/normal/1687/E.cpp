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
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn], vis[maxn], cnt[maxn], ok[maxn], id[maxn];
inline int calc(int x, int p) {x = a[x]; int res = 0; while(res <= 100 && x % p == 0) res++, x /= p; return res;}
vector<vector<int> > ans[2];
vector<int> st;
int main()
{
	n = read();
	ru(i, 1, n) cnt[a[i] = read()]++;
	ru(i, 2, maxn - 1) if(!vis[i])
	{
		ru(j, 2, (maxn - 1) / i) cnt[i] += cnt[i * j], vis[i * j] = 1;
		if(n - cnt[i] >= 2) continue;
		int mn = 0, mn2 = 0;
		ru(j, 1, n)
		{
			if(calc(j, i) < calc(mn, i)) mn2 = mn, mn = j;
			else if(calc(j, i) < calc(mn2, i)) mn2 = j;
		}
		ok[mn] = ok[mn2] = 1;
	}
	int tmp = n; n = 0;
	ru(i, 1, tmp) if(ok[i]) id[n++] = i;
	ru(i, 2, maxn - 1) if(!vis[i] && tmp - cnt[i] >= 2)
	{
		int num = 0;
		ru(j, 0, n - 1) if(a[id[j]] % i != 0) num++;
		if(num >= 2) continue;
		ru(j, 1, tmp) if(!ok[j] && a[j] % i != 0)
		{
			ok[id[n++] = j] = 1, num++;
			if(num == 2) break; 
		}
	}
	sort(id, id + n);
	ru(i, 1, (1 << n) - 1)
	{
		st.clear();
		ru(j, 0, n - 1) if((i >> j) & 1) st.push_back(id[j]);
		int tim = (1 - 2 * (st.size() & 1)) * (st.size() - 2);
		if(tim > 0) ru(j, 1, tim) ans[0].push_back(st);
		else ru(j, 1, -tim) ans[1].push_back(st);
	}
	printf("%d\n", ans[0].size() + ans[1].size());
	for (auto x: ans[0]) {printf("0 %d ", x.size()); for (auto y: x) printf("%d ", y); printf("\n");}
	for (auto x: ans[1]) {printf("1 %d ", x.size()); for (auto y: x) printf("%d ", y); printf("\n");}
	return 0;
}