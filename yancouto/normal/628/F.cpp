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
	const int maxv = 11000;
	const int maxe = 70009 * 2;
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
const int N = 10009;
int up[N], qt[N], p[N];
int main() {
	int n, b, q, i;
	scanf("%d %d %d", &n, &b, &q);
	for(i = 0; i < q; i++)
		scanf("%d %d", &up[i], &qt[i]), p[i] = i;
	up[q] = b; qt[q] = n; p[q] = q; q++;
	sort(p, p + q, [](int i, int j) { return up[i] < up[j]; });
	f::reset_all();
	int prev = 1, v = 0;
	for(i = 0; i < q; i++) {
		int j = p[i];
		if(qt[j] - v < 0) break;
		if(qt[j] - v) f::add_edge(N, i, qt[j] - v);
		int r[5] = {0, 0, 0, 0, 0};
		for(int k = prev; k <= up[j]; k++)
			r[k % 5]++;
		for(int k = 0; k < 5; k++)
			if(r[k])
				f::add_edge(i, f::maxv-1-k, r[k]);
		prev = up[j] + 1;
		v = qt[j];
	}
	if(i < q) { puts("unfair"); return 0; }
	for(i = 0; i < 5; i++)
		f::add_edge(f::maxv-1-i, N+1, n/5);
	if(f::max_flow(N, N + 1) == n) puts("fair");
	else puts("unfair");
}