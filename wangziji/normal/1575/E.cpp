#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2e5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int inv2 = (mod + 1) / 2;
int cnt, head[maxn + 5];
int a[maxn + 5];
int n, k, u, v, w;
int rt, all, mxsum, size[maxn + 5], mx[maxn + 5], vis[maxn + 5];
P f[2][maxn + 5];
int ans;
struct Edge {
	int to, next, w;
}e[maxn * 2 + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;} 
inline int mul(int a, int b) {return 1ll * a * b % mod;}
void add(int u, int v, int w) {
	e[++ cnt] = (Edge) {v, head[u], w}, head[u] = cnt;
}
void findrt(int u, int par) {
	size[u] = 1, mx[u] = 0;
	trv(i, u, v) if(v != par && !vis[v]) {
		findrt(v, u);
		size[u] += size[v];
		chkmx(mx[u], size[v]);
	}
	chkmx(mx[u], all - size[u]);
	if(mx[rt] > mx[u]) rt = u;
}
void dfs(int u, int par, int sum, int lst, int val, int opt) {
	if(chkmx(mxsum, sum)) f[0][sum] = f[1][sum] = {0, 0};
	f[opt][sum].fi ++;
	f[opt][sum].se = add(f[opt][sum].se, val); 
	trv(i, u, v) if(v != par && !vis[v]) {
		dfs(v, u, sum + (lst != e[i].w), e[i].w, add(val, a[v]), opt);
	}
}
P operator * (P a, P b) {
	return {mul(a.fi, b.fi), add(mul(a.fi, b.se), mul(a.se, b.fi))};
}
P c[maxn + 5];
void calc(P *a, P *b, int k, int lim, int t, int v) {
	rep(i, 1, min(k, lim)) c[i].se = add(c[i - 1].se, a[i].se), c[i].fi = c[i - 1].fi + a[i].fi;
	rep(i, 1, min(k, lim)) ans = add(ans, mul(t, add((b[i] * c[min(lim, k - i)]).se, mul((b[i] * c[min(lim, k - i)]).fi, v))));
}
void solve(int u) {
	vis[u] = 1, mxsum = 0;
	trv(i, u, v) if(!vis[v]) dfs(v, u, 1, e[i].w, a[v], e[i].w);
	calc(f[0], f[0], k + 1, mxsum, 1, a[u]);
	calc(f[1], f[1], k + 1, mxsum, 1, a[u]);
	calc(f[0], f[1], k, mxsum, 2, a[u]);
	rep(i, 1, min(mxsum, k)) ans = add(ans, mul(2, add(f[0][i].se, f[1][i].se))), ans = add(ans, mul(2, mul(add(f[0][i].fi, f[1][i].fi), a[u])));
	ans = add(ans, add(a[u], a[u]));
	trv(i, u, v) if(!vis[v]) {
		mxsum = 0;
		dfs(v, u, 1, e[i].w, a[v], e[i].w);
		calc(f[0], f[0], k + 1, mxsum, mod - 1, a[u]);
		calc(f[1], f[1], k + 1, mxsum, mod - 1, a[u]);
		calc(f[0], f[1], k + 1, mxsum, mod - 2, a[u]);
		findrt(v, v), all = size[v], rt = 0, findrt(v, v), solve(rt);
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> k; k ++;
	rep(i, 1, n) cin >> a[i];
	rep(i, 2, n) cin >> u >> v >> w, add(u, v, w), add(v, u, w);
	all = n, mx[rt = 0] = inf, findrt(1, 1), solve(rt);
	cout << mul(ans, inv2) << '\n';
	return 0;
}