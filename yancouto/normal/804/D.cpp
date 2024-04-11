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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

const int N = 112345;
int S[N], sz[N];
vector<int> all[N], adj[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}

inline void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	sz[a] += sz[b];
	for(int x : all[b]) all[a].pb(x);
}

int n;

int mxd, mxv;

void dfs(int u, int p, int d) {
	if(d > mxd) mxd = d, mxv = u;
	for(int v : adj[u])
		if(v != p)
			dfs(v, u, d + 1);
}

void dist(int u, int p, int d, int D[]) {
	D[u] = d;
	for(int v : adj[u])
		if(v != p)
			dist(v, u, d + 1, D);
}

int d[2][N], allda[N], alldb[N], ctda[N], ctdb[N], mx[N];
vector<ll> ds[N], acc[N], Ds[N], ct[N], ctacc[N];

int main() {
	int i, j, m, q, a, b;
	rd(n); rd(m); rd(q);
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1, all[i].pb(i);
	for(i = 0; i < m; i++) {
		rd(a); rd(b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
		join(a, b);
	}
	for(i = 0; i < n; i++)
		if(find(i) == i) {
			mxd = -1; dfs(i, -1, 0);
			dist(mxv, -1, 0,  d[0]);
			mxd = -1; dfs(mxv, -1, 0);
			dist(mxv, -1, 0, d[1]);
			mx[i] = mxd;
			//printf("mx[%d] = %d\n", i, mxd);
			for(int x : all[i])
				ds[i].pb(max(d[0][x], d[1][x]));
			sort(ds[i].begin(), ds[i].end());
			for(int x : ds[i]) {
				//printf("dist %d\n", x);
				if(Ds[i].empty() || Ds[i].back() != x)
					Ds[i].pb(x), ct[i].pb(0);
				ct[i].back()++;
			}
			acc[i].resize(Ds[i].size());
			ctacc[i].resize(Ds[i].size());
			acc[i].back() = Ds[i].back() * ct[i].back();
			ctacc[i].back() = ct[i].back();
			for(j = acc[i].size() - 2; j >= 0; j--) {
				acc[i][j] = acc[i][j + 1] + Ds[i][j] * ct[i][j],
				ctacc[i][j] = ct[i][j] + ctacc[i][j + 1];
				//printf("ctacc[%d][%d] = %lld\n", i, j, ctacc[i][j]);
			}
		}
	map<pii, double> qs;
	for(i = 0; i < q; i++) {
		rd(a); rd(b); a--; b--;
		if((a = find(a)) == (b = find(b))) { puts("-1"); continue; }
		if(sz[a] < sz[b]) swap(a, b);
		if(qs.count(pii(a, b))) { printf("%.15f\n", qs[pii(a, b)]); continue; }
		int mxx = max(mx[a], mx[b]);
		ll left = ll(sz[a]) * ll(sz[b]);
		ll tot = 0;
		ll hasB = 0;
		for(j = 0; j < Ds[b].size(); j++) {
			hasB += ct[b][j];
			auto it = upper_bound(Ds[a].begin(), Ds[a].end(), mxx - 1 - Ds[b][j]);
			//printf("has %lld need >%lld\n", Ds[b][j], mxx - 1 - Ds[b][j]);
			if(it == Ds[a].end()) continue;
			int k = it - Ds[a].begin();
			//printf("k %d\n", k);
			//printf("%lld * %lld + %lld * %lld * %lld\n", acc[a][k], ct[b][j], ctacc[a][k], Ds[b][j]+1, ct[b][j]);
			tot += acc[a][k] * ct[b][j] + ctacc[a][k] * ll(Ds[b][j] + 1) * ct[b][j];
			left -= ct[b][j] * ctacc[a][k];
		}
		//printf("%lld * %lld\n", left, mxx);
		tot += left * mxx;
		//printf("%lld / %lld\n", tot, (ll(sz[a]) * ll(sz[b])));
		printf("%.15f\n", tot / double(ll(sz[a]) * ll(sz[b])));
		qs[pii(a, b)] = tot / double(ll(sz[a]) * ll(sz[b]));
	}
}