#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pii;
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

int n;
const int N = 212345;
int dg[N], rdg[N], ok[N], tc[N], t, p[N];
ll d[N];
vector<pii> adj[N];

int go(int u) {
	int ct = 1;
	for(pii e : adj[u])
		if(d[e.fst] != d[u] + e.snd) continue;
		else if(tc[e.fst] && tc[e.fst] < t) continue;
		else {
			tc[e.fst] = t;
			dg[e.fst]--;
			if(dg[e.fst] == 0) {
				ok[e.fst] = 1;
				ct += go(e.fst);
			}
		}
	return ct;
}

int main() {
	int i, j, m, s, a, b, c;
	rd(n); rd(m); rd(s);
	for(i = 0; i < m; i++) {
		rd(a); rd(b); rd(c);
		adj[a].pb(pii(b, c));
		adj[b].pb(pii(a, c));
	}
	for(i = 1; i <= n; i++) d[i] = LLONG_MAX;
	priority_queue<pii> pq;
	pq.push(pii(0, s));
	while(!pq.empty()) {
		pii x = pq.top(); pq.pop();
		if(d[x.snd] < LLONG_MAX) continue;
		d[x.snd] = -x.fst;
		for(pii e : adj[x.snd])
			pq.push(pii(x.fst - e.snd, e.fst));
	}
	for(i = 1; i <= n; i++) p[i] = i;
	sort(p + 1, p + n + 1, [](int i, int j) { return d[i] < d[j]; });
	for(i = 1; i <= n; i++)
		if(d[i] < LLONG_MAX)
			for(pii e : adj[i])
				if(d[e.fst] == d[i] + e.snd)
					dg[e.fst]++, rdg[e.fst]++;
	int best = 0;
	for(j = 2; j <= n; j++) {
		i = p[j];
		if(d[i] == LLONG_MAX) continue;
		if(ok[i]) continue;
		t++;
		best = max(best, go(i));
	}
	printf("%d\n", best);
}