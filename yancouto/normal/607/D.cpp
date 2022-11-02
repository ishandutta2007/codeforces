#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif
#define set alsjdalsjd

ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}
inline ll inv(ll x) { return fexp(x, modn - 2); }

const int N = 212345;

vector<int> adj[N];
int t, id[N], d[N], f[N];
void dfs(int a) {
	id[t] = a;
	d[a] = t++;
	for(int b : adj[a])
		dfs(b);
	f[a] = t - 1;
}

ll tr[N*4];
ll lazy[N*4];
void unlaze(int i, int l, int r) {
	if(lazy[i] == 1) return;
	tr[i] = mod(tr[i] * lazy[i]);
	if(l != r) {
		lazy[2*i] = mod(lazy[2*i] * lazy[i]);
		lazy[2*i+1] = mod(lazy[2*i+1] * lazy[i]);
	}
	lazy[i] = 1;
}

void set(int i, int l, int r, int x, ll v) {
	unlaze(i, l, r);
	//if(l == r) printf("no %d [%d, %d] = %lld\n", i, l, r, v);
	if(l == r) return (void) (tr[i] = v);
	int m = (l + r) / 2;
	if(m >= x) set(2*i, l, m, x, v);
	else set(2*i+1, m + 1, r, x, v);
	unlaze(2*i, l, m);
	unlaze(2*i+1, m + 1, r);
	tr[i] = mod(tr[2*i] + tr[2*i+1]);
	//printf("no %d [%d, %d] = %lld\n", i, l, r, tr[i]);
}

ll query(int i, int l, int r, int ql, int qr) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return 0;
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return mod(query(2*i, l, m, ql, qr) + query(2*i+1, m + 1, r, ql, qr));
}

void mult(int i, int l, int r, int ql, int qr, ll v) {
	unlaze(i, l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		lazy[i] = v;
		unlaze(i, l, r);
		//printf("no %d [%d, %d] = %lld\n", i, l, r, tr[i]);
		return;
	}
	int m = (l + r) / 2;
	mult(2*i, l, m, ql, qr, v);
	mult(2*i+1, m + 1, r, ql, qr, v);
	tr[i] = mod(tr[2*i] + tr[2*i+1]);
	//printf("no %d [%d, %d] = %lld\n", i, l, r, tr[i]);
}

int q[N], a[N], b[N], p[N], v[N], V[N]; ll s[N];
inline ll get_contr(int i) {
	//printf("%lld / %d\n", query(1, 0, t - 1, d[i], d[i]), V[i]);
	return mod(query(1, 0, t - 1, d[i], d[i]) * inv(V[i]));
}

int main() {
	int i, j, n; ll v1;
	scanf("%lld %d", &v1, &n);
	int ct = 1;
	V[0] = v1;
	for(i = 0; i < n; i++) {
		scanf("%d %d", &q[i], &a[i]); a[i]--;
		if(q[i] == 1) scanf("%d", &v[i]), V[ct] = v[i], b[i] = ct, adj[a[i]].pb(ct++), p[ct-1] = a[i];
	}
	for(i = 0; i < 4*N; i++) lazy[i] = 1;
	dfs(0);
	for(i = 0; i < t; i++) s[i] = 1;
	//for(i = 0; i < t; i++) printf("[%d] (%d, %d)\n", i, d[i], f[i]);
	set(1, 0, t - 1, 0, v1);
	//printf("con %lld\n", get_contr(0));
	for(i = 0; i < n; i++) {
		//printf("query %d\n", i);
		//for(j = 0; j < t; j++) printf("%d ", query(1, 0, t - 1, j, j)); putchar('\n');
		if(q[i] == 1) {
			mult(1, 0, t - 1, d[a[i]], f[a[i]], mod(inv(s[a[i]]) * ll(s[a[i]] + 1)));
			ll con = get_contr(a[i]);
			set(1, 0, t - 1, d[b[i]], mod(con * ll(v[i])));
			s[a[i]]++;
		} else {
			//printf("get %d (%d, %d)\n", a[i], d[a[i]], f[a[i]]);
			ll ans = query(1, 0, t - 1, d[a[i]], f[a[i]]);
			ll con = a[i]? get_contr(p[a[i]]) : 1;
			//printf("invcon %d\n", (int)inv(con));
			printf("%d\n", (int) mod(ans * inv(con)));
		}
	}
}