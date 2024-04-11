#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

/**
 * Description: Minimum-cost maximum flow, assumes no negative cycles.
 	* It is possible to choose negative edge costs such that the first
 	* run of Dijkstra is slow, but this hasn't been an issue in the past.
 	* Edge weights $\ge 0$ for every subsequent run. To get flow through
 	* original edges, assign ID's during \texttt{ae}.
 * Time: Ignoring first run of Dijkstra, $O(FM\log M)$
 	* if caps are integers and $F$ is max flow.
 * Source: GeeksForGeeks
 	* https://courses.csail.mit.edu/6.854/06/scribe/s12-minCostFlowAlg.pdf
 	* running time is only pseudo-polynomial; see https://codeforces.com/blog/entry/70740
 	* https://en.wikipedia.org/wiki/Johnson%27s_algorithm (to get non-negative weights)
 	* https://codeforces.com/contest/1316/submission/72472865
 		* mango_lassi, min cost circulation w/ capacity scaling
 * Verification: https://codeforces.com/contest/164/problem/C
 	* https://codeforces.com/contest/316/problem/C2
 		* TLEs, don't use priority queue
 */

 bool ckmin(ll& a,ll b) { return a>b?a=b,1:0;}

struct MCMF {
	using F = ll; using C = ll; // flow type, cost type
	struct Edge { int to, rev; F flo, cap; C cost; };
	int N; vector<C> p, dist; vector<PII> pre; vector<vector<Edge>> adj;
	void init(int _N) { N = _N;
		p.resize(N), adj.resize(N), dist.resize(N), pre.resize(N); }
	void ae(int u, int v, F cap, C cost) { assert(cap >= 0);
		adj[u].pb({v,SZ(adj[v]),0,cap,cost});
		adj[v].pb({u,SZ(adj[u])-1,0,0,-cost});
	} // use asserts, don't try smth dumb
	bool path(int s, int t) { // send flow through lowest cost path
		const C inf = numeric_limits<C>::max(); dist.assign(N,inf);
		using T = pair<C,int>;
		priority_queue<T,vector<T>,greater<T>> todo;
		todo.push({dist[s] = 0,s});
		while (SZ(todo)) { // Dijkstra
			T x = todo.top(); todo.pop();
			if (x.fi > dist[x.se]) continue;
			for (auto&e:adj[x.se]) { // all weights should be non-negative
				if (e.flo < e.cap && ckmin(dist[e.to],
						x.fi+e.cost+p[x.se]-p[e.to]))
					pre[e.to]={x.se,e.rev}, todo.push({dist[e.to],e.to});
			}
		} // if costs are doubles, add some EPS so you
		// don't traverse ~0-weight cycle repeatedly
		return dist[t] != inf; // true if augmenting path
	}
	pair<F,C> calc(int s, int t) { assert(s != t);
		rep(_,0,N) rep(i,0,N) for (auto&e:adj[i]) // Bellman-Ford
			if (e.cap) ckmin(p[e.to],p[i]+e.cost);
		F totFlow = 0; C totCost = 0;
		while (path(s,t)) { // p -> potentials for Dijkstra
			rep(i,0,N) p[i] += dist[i]; // don't matter for unreachable
			F df = numeric_limits<F>::max();
			for (int x = t; x != s; x = pre[x].fi) {
				Edge& e = adj[pre[x].fi][adj[x][pre[x].se].rev];
				ckmin(df,e.cap-e.flo); }
			totFlow += df; totCost += (p[t]-p[s])*df;
			for (int x = t; x != s; x = pre[x].fi) {
				Edge& e = adj[x][pre[x].se]; e.flo -= df;
				adj[pre[x].fi][e.rev].flo += df;
			}
		} // get max flow you can send along path
		return {totFlow,totCost};
	}
};

const int N=105;
char s[N],t[N];
int n,a,cnt[50];
int main() {
	scanf("%s",s);
	scanf("%d",&n);
	MCMF ff;
	ff.init(n*26+200);
	int source=0,sink=n*26+28+n+1;
	rep(i,0,26) cnt[i]=0;
	rep(i,0,strlen(s)) cnt[s[i]-'a']++;
	rep(i,0,26) ff.ae(n+1+n*26+i,sink,cnt[i],0);
	rep(i,0,n) {
		scanf("%s",t);
		scanf("%d",&a);
		rep(j,0,26) cnt[j]=0;
		rep(j,0,strlen(t)) cnt[t[j]-'a']++;
		rep(j,0,26) {
			ff.ae(i+1,n+1+i*26+j,cnt[j],0);
			ff.ae(n+1+i*26+j,n+1+n*26+j,1e9,0);
		}
		ff.ae(source,i+1,min((int)strlen(t),a),i+1);
	}
	auto ans=ff.calc(source,sink);
	if (ans.fi==strlen(s)) {
		printf("%lld",ans.se);
	} else {
		puts("-1");
	}
}