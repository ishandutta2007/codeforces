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
#define maxn 200005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, b[maxn], a[maxn], tot, R[maxn], ans;
int miu[maxn], phi[maxn], f[maxn], prime[maxn], cnt, vis[maxn];
vector<int> D[maxn];
inline void upd(int &x, int y) {x += y; if(x >= mo) x -= mo;}
inline int qpow(int x, int step)
{
	int res = 1;
	for (; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
void init()
{
	miu[1] = phi[1] = 1;
	ru(i, 2, maxn - 1)
	{
		if(!vis[i]) prime[++cnt] = i, miu[i] = -1, phi[i] = i - 1;
		for (int j = 1; j <= cnt && i * prime[j] < maxn; j++)
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {phi[i * prime[j]] = prime[j] * phi[i]; break;} 
			miu[i * prime[j]] = -miu[i], phi[i * prime[j]] = (prime[j] - 1) * phi[i];
		}
	}
}
vector<int> G[maxn];
void dfs(int x, int fa)
{
	int dfn = ++tot; a[dfn] = b[x];
	for (auto V: G[x]) if(V ^ fa) dfs(V, x);
	R[dfn] = tot;
}
int sum[2][maxn], res;
inline void change(int tp, int x)
{
	for (auto d: D[x])
	{
		upd(res, mo - (ll)sum[0][d] * sum[1][d] % mo * f[d] % mo);
		upd(sum[tp ^ 1][d], mo - phi[x]);
		upd(sum[tp][d], phi[x]);
		upd(res, (ll)sum[0][d] * sum[1][d] % mo * f[d] % mo);
	}
}
void solve(int l, int r)
{
	if(l == r)
	{
		if(R[l] == l) upd(ans, res);
		return;
	}
	int pos = r;
	ru(i, l, mid)
	{
		if(mid < R[i] && R[i] <= r)
		{
			while(pos > R[i]) change(1, a[pos--]);
			upd(ans, res);
		}
		change(1, a[i]);
	}
	ru(i, pos + 1, r) change(0, a[i]);
	solve(mid + 1, r);
	ru(i, l, mid) change(0, a[i]);
	ru(i, mid + 1, r) change(1, a[i]);
	solve(l, mid);
	ru(i, mid + 1, r) change(0, a[i]);
}
int main()
{
	init(); 
	n = read();
	ru(i, 1, n) b[i] = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	ru(i, 1, n) 
	{
		int val = (ll)i * qpow(phi[i], mo - 2) % mo;
		ru(j, 1, n / i) upd(f[i * j], (ll)val * (miu[j] + mo) % mo);
		//printf("%d ", f[i]);
	}//printf("\n");
	ru(i, 1, n) ru(j, 1, n / i) D[i * j].push_back(i), upd(sum[0][i], phi[i * j]);
	dfs(1, 0), solve(1, n);
	printf("%d\n", (ll)ans * qpow(((ll)n * (n - 1) / 2) % mo, mo - 2) % mo);
	return 0;
}