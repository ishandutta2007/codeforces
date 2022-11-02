#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif
namespace f {
	const int maxv = 312;
	const int maxe = 112345 * 2;
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
				if(num a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
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

int n, k;

const int N = 112;
struct card {
	int p, c, l;
} c[N];
const int M = 1123456;
int comp[M];

bool ok(int L) {
	vector<card> cs, c1;
	int i, j;
	for(i = 0; i < n; i++) {
		if(c[i].l > L) continue;
		if(c[i].c == 1) c1.pb(c[i]);
		else cs.pb(c[i]);
	}
	sort(c1.begin(), c1.end(), [](card a, card b) { return a.p > b.p; });
	while(c1.size() > 1) c1.pop_back();
	for(card cc : c1) cs.pb(cc);
	f::reset_all(cs.size() + 2);
	ll all = 0;
	for(i = 0; i < cs.size(); i++) {
		all += cs[i].p;
		if(cs[i].c & 1) {
			f::add_edge(i, cs.size() + 1, cs[i].p);
			continue;
		}
		f::add_edge(cs.size(), i, cs[i].p);
		for(j = 0; j < cs.size(); j++) {
			if(!(cs[j].c & 1) || comp[cs[i].c + cs[j].c]) continue;
			debug("%d, %d : %d + %d = %d\n", i, j, cs[i].c, cs[j].c, comp[cs[i].c + cs[j].c]);
			f::add_edge(i, j, f::inf);
		}
	}
	int power = all - f::max_flow(cs.size(), cs.size() + 1);
	debug("L %d -- (%d - %d)\n", L, all, all - power);
	return power >= k;
}

int main() {
	int i, j;
	for(i = 2; i < M; i++)
		if(!comp[i])
			for(j = i + i; j < M; j += i)
				comp[j] = 1;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%d %d %d", &c[i].p, &c[i].c, &c[i].l);
	if(!ok(100)) { puts("-1"); return 0; }
	int l = 1, r = 100;
	while(l < r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m + 1;
	}
	printf("%d\n", l);
}