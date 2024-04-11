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
#define maxn 100105
#define N 20000005
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int mo = 1e9 + 7;
const int mod1 = 998244353, mod2 = 1e9 + 7; 
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
mt19937 Rand(time(NULL));
int n, m, ed[maxn], las[maxn];
int ch[N][2], fir[N], tag[N], hash1[N], hash2[N], tot;
int sum1[maxn + 5], sum2[maxn + 5];
vector<pii> G[maxn];
inline void pushup(int x)
{
	fir[x] = min(fir[ch[x][0]], fir[ch[x][1]]);
	hash1[x] = (hash1[ch[x][0]] + hash1[ch[x][1]]) % mod1;
	hash2[x] = (hash2[ch[x][0]] + hash2[ch[x][1]]) % mod2;
}
inline int new_node(int v, int l, int r)
{
	int x = ++tot;
	hash1[x] = v * (sum1[r] - sum1[(l + maxn + 1) % (maxn + 2)] + mod1) % mod1;
	hash2[x] = v * (sum2[r] - sum2[(l + maxn + 1) % (maxn + 2)] + mod2) % mod2;
	tag[x] = v, fir[x] = (v ? maxn : l);
	return x;
}
int change(int x, int l, int r, int a, int b, int v)
{
	if(a > b) return x;
	if(a <= l && r <= b) return new_node(v, l, r);
	int now = ++tot;
	if(tag[x] != -1) ch[now][0] = new_node(tag[x], l, mid), ch[now][1] = new_node(tag[x], mid + 1, r); 
	else ch[now][0] = ch[x][0], ch[now][1] = ch[x][1];
	if(a <= mid) ch[now][0] = change(ch[now][0], l, mid, a, b, v);
	if(b > mid) ch[now][1] = change(ch[now][1], mid + 1, r, a, b, v);
	pushup(now);
	tag[now] = -1;
	return now;
}
int find(int x, int l, int r, int a, int b)
{
	if(tag[x] != -1) return max(fir[x], a);
	if(a <= l && r <= b) return fir[x];
	if(a > mid) return find(ch[x][1], mid + 1, r, a, b);
	return min(find(ch[x][0], l, mid, a, b), find(ch[x][1], mid + 1, r, a, b));
}
int cmp(int x, int y, int l, int r)
{
	if(tag[x] == 1 || tag[y] == 0) return 0;
	if(tag[x] == 0 || tag[y] == 1) return 1;
	if(hash1[ch[x][1]] == hash1[ch[y][1]] && hash2[ch[x][1]] == hash2[ch[y][1]]) return cmp(ch[x][0], ch[y][0], l, mid);
	else return cmp(ch[x][1], ch[y][1], mid + 1, r);
}
int que(int x, int l, int r, int pos)
{
	if(tag[x] != -1) return tag[x]; 
	if(pos <= mid) return que(ch[x][0], l, mid, pos);
	else return que(ch[x][1], mid + 1, r, pos);
}
struct node
{
	int id, d;
	inline bool operator < (const node &a) const
	{
		return !cmp(d, a.d, 0, maxn);
	}
};
priority_queue<node> q;
int vis[maxn];
int main()
{
	tag[0] = 0, fir[0] = 0;
	ru(i, 0, maxn) sum1[i] = Rand() % mod1, sum2[i] = Rand() % mod2;
	n = read(), m = read();
	ru(i, 1, m)
	{
		int x = read(), y = read(), a = read();
		G[x].push_back(mp(y, a)), G[y].push_back(mp(x, a));
	}
	int s = read(), t = read(); q.push({s, ed[s]});
	ru(i, 1, n) if(i ^ s) ed[i] = change(0, 0, maxn, maxn, maxn, 1);
	while(!q.empty())
	{
		int x = q.top().id; q.pop(); 
		if(vis[x]) continue; vis[x] = 1;
		for (auto to: G[x])
		{
			int V = to.fi, W = to.se;
			int pos = find(ed[x], 0, maxn, W, maxn); //printf("%d\n", pos);
			int t = change(change(ed[x], 0, maxn, pos, pos, 1), 0, maxn, W, pos - 1, 0);
			if(cmp(t, ed[V], 0, maxn)) ed[V] = t, q.push({V, ed[V]}), las[V] = x;
		}
	}
	if(que(ed[t], 0, maxn, maxn)) {printf("-1\n"); return 0;}
	int ans = 0, tmp = 1;
	ru(i, 0, maxn) ans = (ans + (ll)que(ed[t], 0, maxn, i) * tmp % mo) % mo, tmp = (ll)tmp * 2 % mo;
	printf("%d\n", ans);
	vector<int> path;
	for (int i = t; i; i = las[i]) path.push_back(i);
	reverse(path.begin(), path.end());
	printf("%d\n", path.size());
	for (auto x: path) printf("%d ", x);
	return 0;
}