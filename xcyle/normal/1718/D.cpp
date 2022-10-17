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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 300005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, Q, k, p[maxn], pos[maxn], a[maxn], s[maxn];
vector<int> G[maxn];
struct dsu
{
	int fa[maxn];
	inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	inline void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if(x ^ y) G[y].push_back(x), fa[x] = y;
	}
}P;
int l[maxn], r[maxn];
int dfs(int x, int mn)
{
	int mx = 0;
	if(a[x]) mn = min(mn, a[x]), mx = max(mx, a[x]);
	for (auto V: G[x]) mx = max(mx, dfs(V, mn));
	l[x] = mx, r[x] = mn;
	return mx;
}
int L, R;
int tmp[maxn];
priority_queue<int> q;
struct node
{
	int l, r;
	inline bool operator < (const node &a) const
	{
		return r == a.r ? l > a.l : r > a.r;
	}
}lim[maxn];
inline int check(int t)
{
	ru(i, 1, k - 1) tmp[i] = s[i];
	tmp[k] = t;
	sort(tmp + 1, tmp + k + 1, greater<int>());
	int pos = 1;
	while(!q.empty()) q.pop(); 
	ru(i, 1, k)
	{
		while(pos <= k && tmp[i] <= lim[pos].r) q.push(lim[pos++].l);
		if(q.empty()) return 2;
		int x = q.top(); q.pop();
		if(x > tmp[i]) return 0;
	}
	return 1;
}
int FL = 0, rem = 263;
inline int calc()
{
	ru(i, 1, k - 1) tmp[i] = s[i];
	sort(tmp + 1, tmp + k, greater<int>());
	int pos = 1;
	while(!q.empty()) q.pop(); 
	ru(i, 1, k - 1)
	{
		while(pos <= k && tmp[i] <= lim[pos].r) q.push(lim[pos++].l);
		if(q.empty()) return 1e6 + 1;
		int x = q.top(); q.pop();
		if(x > tmp[i]) return x;
	}
	while(pos <= k) q.push(lim[pos++].l);
	return q.top();
}
void solve()
{
	n = read(), Q = read(), k = 0;
	ru(i, 1, n) pos[p[i] = read()] = i;
	ru(i, 1, n) a[i] = read(), k += (a[i] == 0);
	ru(i, 1, k - 1) s[i] = read();
	ru(i, 1, n) P.fa[i] = i, G[i].clear();
	p[0] = p[n + 1] = n + 1;
	ru(i, 1, n)
	{
		int now = pos[i];
		if(p[now - 1] < i) P.merge(now - 1, now);
		if(p[now + 1] < i) P.merge(now + 1, now);
	}
	dfs(P.find(1), 1e6 + 1);
	ru(i, 1, n) if(a[i] && (a[i] < l[i] || a[i] > r[i]))
	{
		while(Q--) read(), printf("NO\n");
		return;
	}
//	printf("segment: \n");
//	ru(i, 1, n) printf("%d %d\n", l[i], r[i]);
//	printf("\n");	
	int tot = 0;
	ru(i, 1, n) if(!a[i]) lim[++tot] = {l[i], r[i]};
	sort(lim + 1, lim + k + 1);
//	printf("!!!%d\n", check(8));
//	int l = 0, r = 1e6 + 1, mid;
//	while(l < r)
//	{
//		mid = (l + r) >> 1;
////		assert(check(mid) <= check(mid + 1));
//		if(check(mid) == 0) l = mid + 1;
//		else r = mid;
//	}
//	assert(l != 1e6 + 1 || check(l) != 0);
	L = calc();
	if(check(L) != 1) L = 1e6 + 1; 
	int l = L, r = 1e6, mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		//assert(check(mid - 1) <= check(mid));
		if(check(mid) != 1) r = mid - 1;
		else l = mid;
	}
//	assert(l == 0 || check(l) != 2);
	R = l;
	while(Q--)
	{
		int x = read();
//		if(FL && rem)
//		{
//			rem--;
//			if(!rem){
//			printf("%d %d %d %d %d\n", L, x, R, n, k);
//			ru(i, L, R - 1)
//			{
//				if(check(i) > check(i + 1)) {printf("%d %d %d\n", i, check(i), check(i + 1)); break;}
//			}
//		}
//		}
//		if(!FL)
//		{
			if(L <= x && x <= R) printf("YES\n");
			else printf("NO\n"); //} 
	}
}
int main()
{
	int T = read();
	if(T == 5000) FL = 1;
	while(T--) solve();
	return 0;
}