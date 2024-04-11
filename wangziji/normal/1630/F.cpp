#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e6 + 5;
const int maxm = 1e5 * 80;
const int inf = 1e9;
struct Edge {
	int to, nxt; int w;
};
struct Dinic {
	Edge e[maxm * 2 + 5];
	int n, s, t, gap[maxn + 5], dep[maxn + 5];
	int cnt, head[maxn + 5], cur[maxn + 5];
	void clear() {
		memset(head, 0, n + 1 << 2);
		memset(gap, 0, n + 1 << 2);
		memset(cur, 0, n + 1 << 2);
		memset(dep, 0, n + 1 << 2);
		cnt = 1;
	}
	void add(int u, int v, int w) {
		assert(u != v);
		e[++ cnt] = {v, head[u], w}, head[u] = cnt;
		e[++ cnt] = {u, head[v], 0}, head[v] = cnt;
	}
	int dfs(int u, int flow) {
		if(u == t) return flow;
		int res = flow;
		for(int &i = cur[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			if(dep[v] == dep[u] - 1 && e[i].w) {
				int k = dfs(v, min(res, e[i].w));
				res -= k, e[i].w -= k, e[i ^ 1].w += k;
				if(!res) return flow;
			}
		}
		if(-- gap[dep[u]] == 0) dep[s] = n + 1;
		cur[u] = head[u], ++ gap[++ dep[u]];
		return flow - res;
	}
	ll maxflow() {
		gap[0] = n;
		ll ans = 0;
		while(dep[s] <= n) ans += dfs(s, inf); 
		return ans;
	}
}d;
int n, a[maxn + 5];
vector<int> fac[maxn + 5];
int id[maxn + 5]; 
int main() {
// 	freopen("in.txt", "r", stdin);
	rep(i, 1, maxn) rep(j, 2, maxn/ i) fac[i * j].pb(i);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) id[a[i] = read()] = i;
		d.clear();
		d.s = 4 * n + 1, d.t = d.n = 4 * n + 2; 
		rep(i, 1, n) {
			d.add(d.s, i, 1);
			d.add(i + n, i + 2 * n, 1);
			d.add(i + 3 * n, d.t, 1);
			for(auto x : fac[a[i]]) if(id[x]) {
				d.add(i, id[x] + n, inf);
				d.add(i + 2 * n, id[x] + 3 * n, inf);
			}
		}
		cout << d.maxflow() << '\n';
		rep(i, 1, n) id[a[i]] = 0;
	}
	return 0;
}