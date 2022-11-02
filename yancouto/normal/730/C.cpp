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

int n, m, w, q;
const int N = 11234;
vector<int> adj[N];
vector<pii> ct[N];
int seen[N], d[N], tempo;

int main() {
	int i, j, a, b, c, k, p, g, r;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	scanf("%d", &w);
	for(i = 0; i < w; i++) {
		scanf("%d %d %d", &c, &k, &p); c--;
		ct[c].pb(pii(k, p));
	}
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d %d", &g, &r, &a); g--;
		priority_queue<pii> pq;
		ll cur = 0, qt = 0;
		queue<int> q;
		q.push(g);
		tempo++;
		seen[g] = tempo;
		d[g] = 0;
		int mn = INT_MAX;
		while(!q.empty()) {
			g = q.front(); q.pop();
			for(pii mr : ct[g]) {
				ll pa = min(mr.fst, r);
				ll pr = mr.snd;
				if(qt < r) {
					ll add = min(r - qt, pa);
					qt += add;
					cur += add * pr;
					pa -= add;
					pq.push(pii(pr, add));
					if(pa == 0) continue;
				}
				while(pa > 0 && pq.top().fst > pr) {
					pii x = pq.top(); pq.pop();
					ll add = min<ll>(x.snd, pa);
					pa -= add;
					x.snd -= add;
					cur -= add * ll(x.fst);
					if(x.snd) pq.push(x);
					cur += add * pr;
					pq.push(pii(pr, add));
				}
			}
			//printf("[%d] have %lld with %lld price\n", g, qt, cur);
			if(qt == r && cur <= a) mn = min(mn, d[g]);
			for(int x : adj[g])
				if(seen[x] < tempo) {
					seen[x] = tempo;
					d[x] = d[g] + 1;
					q.push(x);
				}
		}
		if(mn == INT_MAX) puts("-1");
		else printf("%d\n", mn);
	}
}