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

const int N = 312 * 312 + 11234, M = (321 * 321 + 1123456) * 2;
typedef int val;
typedef int num;
int es[N], to[M], nx[M], en = 2, pai[N], seen[N], tempo, qu[N];
val fl[M], cp[M], flow; num cs[M], d[N], tot; int eps = 0;
val spfa(int s, int t) {
	tempo++; int a = 0, b = 0;
	for(int i = 0; i < N; i++) d[i] = numeric_limits<num>::max();
	d[s] = 0; qu[b++] = s; seen[s] = tempo;
	while(a != b) {
		int u = qu[a++]; if(a == N) a = 0; seen[u] = 0;
		for(int e = es[u]; e; e = nx[e]) if(cp[e] - fl[e] > val(0) && d[u] + cs[e] < d[to[e]] - eps) {
			d[to[e]] = d[u] + cs[e]; pai[to[e]] = e ^ 1;
			if(seen[to[e]] < tempo) { seen[to[e]] = tempo; qu[b++] = to[e]; if(b == N) b = 0; }
		}
	}
	if(d[t] == numeric_limits<num>::max()) return false;
	val mx = numeric_limits<val>::max();
	for(int u = t; u != s; u = to[pai[u]])
		mx = min(mx, cp[pai[u] ^ 1] - fl[pai[u] ^ 1]);
	tot += d[t] * val(mx);
	for(int u = t; u != s; u = to[pai[u]])
		fl[pai[u]] -= mx, fl[pai[u] ^ 1] += mx;
	return mx;
}
// public $
num min_cost(int s, int t) {
	tot = 0; flow = 0;
	while(val a = spfa(s, t)) flow += a;
	return tot;
}
void add_edge(int u, int v, val c, num s) {
	fl[en] = 0; cp[en] = c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
	fl[en] = 0; cp[en] = 0; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
}
void reset_flow() { memset(fl, 0, sizeof(val) * en); }
void init(int n) { en = 2; memset(es, 0, sizeof(int) * n); } // XXX must be called

int X = -1000000;
int a[N], b[N];

vector<char> vars[N];

int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	init(N);
	for(i = 0; i < n; i++) scanf("%d", &a[i]), b[i] = a[i];
	sort(b, b + n);
	int bn = unique(b, b + n) - b;
	for(i = 0; i < n; i++) a[i] = lower_bound(b, b + bn, a[i]) - b;
	int s = 0, t = 1;
	int change = 2;
	int collect = change + n + 2;
	int dispense = collect + n + 2;
	add_edge(s, change, m, 0);
	for(i = 0; i < n; i++) {
		add_edge(change + i, collect + i, m, __builtin_popcount(b[a[i]])); // use var here
		add_edge(collect + i, t, 1, X); // collecting
		if(i < n - 1) {
			add_edge(change + i, change + i + 1, m, 0); // keep on change
			add_edge(s, dispense + i, 1, 0);
			add_edge(dispense + i, change + i + 1, 1, 0);
			for(j = i + 1; j < n; j++)
				if(a[i] == a[j]) {
					add_edge(dispense + i, collect + j, 1, 0);
					add_edge(collect + i, collect + j, m, 0);
					break;
				}
		} else {
			add_edge(change + i, t, m, 0); // dont change vars
		}
	}
	int val = min_cost(s, t);
	vector<char> to_change;
	for(i = 0; i < m; i++) to_change.pb('a' + i);
	int ct = 0;
	//asdasdasd
	for(i = 0; i < n; i++) {
		//printf("\n\n=== iteration %d ===\n", i);
		for(int e = es[change + i]; e; e = nx[e]) {
			if(fl[e] <= 0) continue;
			if(to[e] == t) {
				//printf("no more change %d vars\n", fl[e]);
			} else if(to[e] == change + i + 1) {
				//printf("no change %d vars\n", fl[e]);
			} else {
				//printf("%d vars change to %d (%d)\n", fl[e], b[a[to[e] - collect]], to[e]);
				for(int x = 0; x < fl[e]; x++) {
					vars[a[to[e] - collect]].pb(to_change.back());
					ct++;
					to_change.pop_back();
				}
			}
		}
		ct++;
		if(i < n - 1) {
			for(int e = es[dispense + i]; e; e = nx[e]) {
				if(fl[e] <= 0) continue;
				if(to[e] == change + i + 1) {
					to_change.pb(vars[a[i]].back());
					vars[a[i]].pop_back();
				}
			}
		}
	}

	to_change.clear();
	for(i = 0; i < bn; i++) vars[i].clear();
	for(i = 0; i < m; i++) to_change.pb('a' + i);
	printf("%d %d\n", ct, val - X * n);
	for(i = 0; i < n; i++) {
		//printf("\n\n=== iteration %d ===\n", i);
		for(int e = es[change + i]; e; e = nx[e]) {
			if(fl[e] <= 0) continue;
			if(to[e] == t) {
				//printf("no more change %d vars\n", fl[e]);
			} else if(to[e] == change + i + 1) {
				//printf("no change %d vars\n", fl[e]);
			} else {
				//printf("%d vars change to %d (%d)\n", fl[e], b[a[to[e] - collect]], to[e]);
				for(int x = 0; x < fl[e]; x++) {
					vars[a[to[e] - collect]].pb(to_change.back());
					printf("%c=%d\n", to_change.back(), b[a[to[e] - collect]]);
					to_change.pop_back();
				}
			}
		}
		printf("print(%c)\n", vars[a[i]].back());
		if(i < n - 1) {
			for(int e = es[dispense + i]; e; e = nx[e]) {
				if(fl[e] <= 0) continue;
				if(to[e] == change + i + 1) {
					to_change.pb(vars[a[i]].back());
					vars[a[i]].pop_back();
				}
			}
		}
	}
}