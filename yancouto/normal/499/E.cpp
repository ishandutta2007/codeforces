#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

namespace f {
	const int maxv = 100009;
	const int maxe = 300009 * 2;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;

	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];


	bool bfs(int s, int t) {
		memset(lv, -1, sizeof(int) * n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b) {
			for(int i = es[qu[a]]; i != -1; i = nx[i]) {
				if(cp[i] > fl[i] && lv[to[i]] == -1) {
					lv[to[i]] = lv[qu[a]] + 1;
					qu[b++] = to[i];
					cr[to[i]] = es[to[i]];
					if(to[i] == t) return true;
				}
			}
			a++;
		}
		return false;
	}

	num dfs(int u, int t, num mx) {
		if(u == t) return mx;
		for(int &i = cr[u]; i != -1; i = nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(int a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
					fl[i] += a;
					fl[i ^ 1] -= a;
					return a;
				}
		return 0;
	}


	num max_flow(int s, int t) {
		num fl = 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2=maxv) { n = n2; en = 0; memset(es, -1, sizeof(int) * n); }
	void reset_flow() { memset(fl, 0, sizeof(num) * en); }

	void add_edge(int a, int b, num c, num rc=0) {
		fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}
const int N = f::maxv;

int a[200];
vector<pii> ps[200];

int main() {
	int i, j, n, m, u, v, sn = 0;
	scanf("%d %d", &n, &m);
	f::reset_all();
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int x = a[i];
		for(j = 2; j * j <= x; j++) {
			if(x % j) continue;
			int ct = 0;
			while(!(x % j)) x /= j, ct++;
			ps[i].pb(pii(j, sn));
			if(i & 1) f::add_edge(N - 1, sn++, ct);
			else f::add_edge(sn++, N - 2, ct);
		}
		if(x > 1) {
			ps[i].pb(pii(x, sn));
			if(i & 1) f::add_edge(N - 1, sn++, 1);
			else f::add_edge(sn++, N - 2, 1);
		}
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &u, &v); u--; v--;
		if(v & 1) swap(u, v);
		int x = __gcd(a[u], a[v]);
		for(j = 2; j * j <= x; j++) {
			if(x % j) continue;
			int ct = 0;
			while(!(x % j)) x /= j, ct++;
			int from = lower_bound(ps[u].begin(), ps[u].end(), pii(j, INT_MIN))->snd;
			int to = lower_bound(ps[v].begin(), ps[v].end(), pii(j, INT_MIN))->snd;
			f::add_edge(from, to, ct);
		}
		if(x > 1) {
			int from = lower_bound(ps[u].begin(), ps[u].end(), pii(x, INT_MIN))->snd;
			int to = lower_bound(ps[v].begin(), ps[v].end(), pii(x, INT_MIN))->snd;
			f::add_edge(from, to, 1);
		}
	}
	printf("%d\n", f::max_flow(N - 1, N - 2));
}