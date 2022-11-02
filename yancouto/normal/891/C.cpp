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

int n;

struct st {
	int u, p, d;
	bool operator < (st o) const { return d > o.d; }
};

const int N = 512345;
int seen[N];
vector<int> adj2[N];
int a[N], b[N], w[N];
bool B[N];

int tempo = 2;

int S[N], sz[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
inline void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	sz[a] += sz[b];
}

bool dfs(int u, int pe) {
	for(int e : adj2[u]) {
		if(e == pe) continue;
		int v = find(a[e]) + find(b[e]) - u;
		//if(seen[v] == tempo) printf("%d->%d (%d->%d)\n", u, v, a[e], b[e]);
		if(seen[v] == tempo) return true;
		seen[v] = tempo;
		if(dfs(v, e)) return true;
	}
	return false;
}

int k[N];
vector<int> el[N];

struct cmp {
	bool operator()(int i, int j) {
		assert(!el[i].empty() && !el[j].empty());
		return w[el[i].back()] > w[el[j].back()];
	}
};

int es[N];

int main() {
	int i, j; int m;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a[i]); rd(b[i]); rd(w[i]);
		es[i] = i;
	}
	int Q; rd(Q);
	for(int q = 0; q < Q; q++) {
		tempo++;
		rd(k[q]);
		vector<int> vx;
		for(i = 0; i < k[q]; i++) {
			int e;
			rd(e); e--;
			el[q].pb(e);
		}
		sort(el[q].begin(), el[q].end(), [](int e, int f) { return w[e] > w[f]; });
	}
	priority_queue<int, vector<int>, cmp> pq;
	for(int q = 0; q < Q; q++) pq.push(q);
	sort(es, es + m, [](int i, int j) { return w[i] < w[j]; });
	for(i = 0; i <= n; i++) S[i] = i, sz[i] = 1;
	for(int i_ = 0; i_ < m; i_++) {
		i = es[i_];
		debug("adding %d (%d, %d) w = %d\n", i, a[i], b[i], w[i]);
		while(!pq.empty() && w[el[pq.top()].back()] <= w[i]) {
			tempo++;
			vector<int> vx;
			vector<int> es;
			int j = pq.top(); pq.pop();
			debug("\ntrying %d\n", j);
			while(!el[j].empty() && w[el[j].back()] <= w[i]) {
				es.pb(el[j].back());
				el[j].pop_back();
			}
			if(!el[j].empty()) pq.push(j);
			for(int e : es) {
				debug("edge %d (%d, %d) (%d, %d) w = %d\n", e, a[e], b[e], find(a[e]), find(b[e]), w[e]);
				vx.pb(find(a[e]));
				adj2[vx.back()].pb(e);
				vx.pb(find(b[e]));
				adj2[vx.back()].pb(e);
			}
			bool bad = false;
			for(int u : vx) {
				if(seen[u] == tempo) continue;
				seen[u] = tempo;
				if(dfs(u, -1)) { bad = true; break; }
			}
			for(int u : vx) adj2[u].clear();
			if(bad) debug("%d bad at %d\n", j, w[i]);
			if(bad) B[j] = true;
		}
		join(a[i], b[i]);
	}
	for(i = 0; i < Q; i++)
		if(B[i]) puts("NO");
		else puts("YES");
}