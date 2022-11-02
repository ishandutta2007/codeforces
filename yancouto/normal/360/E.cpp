#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 11009;
int c[N], l[120], r[120], a[120]; ll d[2][N];
function<bool (ll, ll)> cmp;
int n, m, k;
int s[2], f;
vector<pii> adj[N];

int seen[N];
void dij(int p) {
	memset(seen, 0, sizeof seen);
	priority_queue<pii> pq;
	pq.push(pii(0, s[p]));
	for(int i = 0; i < n; i++)
		d[p][i] = LLONG_MAX;
	while(!pq.empty()) {
		pii x = pq.top(); pq.pop();
		if(seen[x.snd]) continue;
		seen[x.snd] = true;
		d[p][x.snd] = -x.fst;
		for(pii e : adj[x.snd])
			if(!seen[e.fst])
				pq.push(pii(x.fst - c[e.snd], e.fst));
	}
}

bool solve() {
	int i;
	while(true) {
		dij(0); dij(1);
		for(i = 0; i < k && (c[m + i] == l[i] || !cmp(d[0][a[i]], d[1][a[i]])); i++);
		if(i == k) return cmp(d[0][f], d[1][f]);
		c[m + i] = l[i];
	}
}

void finish(const char *str) {
	puts(str);
	for(int i = 0; i < k; i++)
		printf("%d ", c[i + m]);
	putchar('\n');
	exit(0);
}

int main() {
	int i, a, b;
	scanf("%d %d %d", &n, &m, &k);
	scanf("%d %d %d", &s[0], &s[1], &f); s[0]--; s[1]--; f--;
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c[i]); a--; b--;
		adj[a].pb(pii(b, i));
	}
	for(i = 0; i < k; i++) {
		scanf("%d %d %d %d", &a, &b, &l[i], &r[i]); a--; b--;
		adj[a].pb(pii(b, m + i));
		c[m + i] = r[i];
		::a[i] = a;
	}
	cmp = less<ll>();
	if(solve()) finish("WIN");
	cmp = less_equal<ll>();
	if(solve()) finish("DRAW");
	puts("LOSE");
}