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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

typedef long long ll;

typedef ll num;
const num eps = 0;
const num inf = LLONG_MAX;

const int N = 112345;
const int M = 212345;

namespace f {

typedef int val;
typedef int num;
int es[N], to[M], nx[M], en, pai[N];
val fl[M], cp[M];
num cs[M], d[N];
const num inf = 1e8, eps = 0;
const val infv = INT_MAX;
int seen[N], tempo;
int qu[N];

num tot;
val spfa(int s, int t) {
	tempo++;
	int a = 0, b = 0;
	for(int i = 0; i < N; i++) d[i] = inf;
	d[s] = 0;
	qu[b++] = s;
	seen[s] = tempo;
	while(a != b) {
		int u = qu[a++]; if(a == N) a = 0;
		seen[u] = 0;
		for(int e = es[u]; e != -1; e = nx[e])
			if(cp[e] - fl[e] > val(0) && d[u] + cs[e] < d[to[e]] - eps) {
				d[to[e]] = d[u] + cs[e]; pai[to[e]] = e ^ 1;
				if(seen[to[e]] < tempo) { seen[to[e]] = tempo; qu[b++] = to[e]; if(b == N) b = 0; }
			}
	}
	if(d[t] == inf) return false;
	val mx = infv;
	for(int u = t; u != s; u = to[pai[u]])
		mx = min(mx, cp[pai[u] ^ 1] - fl[pai[u] ^ 1]);
	tot += d[t] * val(mx);
	for(int u = t; u != s; u = to[pai[u]])
		fl[pai[u]] -= mx, fl[pai[u] ^ 1] += mx;
	return mx;
}

void init(int n) {
	en = 0;
	memset(es, -1, sizeof(int) * n);
}

val flow;
num mncost(int s, int t) {
	tot = 0; flow = 0;
	while(val a = spfa(s, t)) flow += a;
	return tot;
}

void add_edge(int u, int v, val c, num s) {
	fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
	fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
}
}


int mn[N], mx[N];

int main() {
	int i, j;
	int n, q;
	int t, l, r, v;
	scanf("%d %d", &n, &q);
	for(i = 0; i < n; i++) mn[i] = 1, mx[i] = n;
	for(i = 0; i < q; i++) {
		scanf("%d %d %d %d", &t, &l, &r, &v); l--; r--;
		for(; l <= r; l++)
			if(t == 1)
				mn[l] = max(mn[l], v);
			else
				mx[l] = min(mx[l], v);
	}
	f::init(N);
	for(i = 0; i < n; i++)
		for(l = mn[i]; l <= mx[i]; l++)
			f::add_edge(i, n - 1 + l, 1, 0);
	int en = 2 * n;
	int src = en++; int snk = en++;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			f::add_edge(en, snk, 1, 0);
			f::add_edge(n + i, en++, 1, 2 * j + 1);
		}
	for(i = 0; i < n; i++)
		f::add_edge(src, i, 1, 0);
	f::mncost(src, snk);
	if(f::flow != n) puts("-1");
	else printf("%d\n", f::tot);
}