#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int LOG = 19;
const int N = 300000;
const ll INF = 2ll*1000000000ll*1000000000ll;


struct ed{
	ll c[2];
	ed () {}
	ed(ll a, ll b){
		c[0] = a;
		c[1] = b;
	}
};

int n;
std::vector<ll> cost;
std::vector<std::vector<PR<int, ed> > > g;
ll dp[2][2][LOG][N+5];
int par[LOG][N+5];
int lev[N+5];

void dfs(int v, int parent=-1){
	par[0][v] = parent;
	TRAV(ch, g[v]) if(ch.X != parent){
		dp[0][0][0][ch.X] = std::min(ch.Y.c[0], cost[ch.X]+cost[v]+ch.Y.c[1]);
		dp[1][1][0][ch.X] = std::min(ch.Y.c[1], cost[ch.X]+cost[v]+ch.Y.c[0]);
		dp[0][1][0][ch.X] = std::min(ch.Y.c[0]+cost[v], cost[ch.X]+ch.Y.c[1]);
		dp[1][0][0][ch.X] = std::min(ch.Y.c[1]+cost[v], cost[ch.X]+ch.Y.c[0]);
		lev[ch.X] = lev[v]+1;
		dfs(ch.X, v);
	}
}

void prepare(){
	dfs(0);
	REP(l, 1, LOG){
		FOR(i, n){
			par[l][i] = (par[l-1][i] == -1 ? -1 : par[l-1][par[l-1][i]]);
			if(par[l][i] != -1){
				int mid = par[l-1][i];
				FOR(a, 2) FOR(b, 2) dp[a][b][l][i] = std::min(dp[a][0][l-1][i]+dp[0][b][l-1][mid],
															dp[a][1][l-1][i]+dp[1][b][l-1][mid]);
			}
		}
	}
}

int lca(int a, int b){
	if(lev[a] < lev[b]) std::swap(a, b);
	for(int i = LOG-1; i >= 0; --i) if(lev[a] - (1<<i) >= lev[b]) a = par[i][a];
	if(a == b) return a;
	for(int i = LOG-1; i >= 0; --i) if(par[i][a] != -1 && par[i][a] != par[i][b]) a = par[i][a], b = par[i][b];
	return par[0][a];
}

ll get(int v, int a, int ile, int b){
	if(ile == 0){
		if(a != b) return cost[v];
		return 0;
	}
	ll dis[2];
	dis[a] = 0;
	dis[1-a] = cost[v];
	for(int i = LOG-1; i >= 0; --i){
		if(ile - (1<<i) >= 0){
			ile -= (1<<i);
			ll old1 = dis[1];
			dis[1] = std::min(dis[0]+dp[0][1][i][v], dis[1]+dp[1][1][i][v]);
			dis[0] = std::min(dis[0]+dp[0][0][i][v], old1+dp[1][0][i][v]);
			v = par[i][v];
		}
	}
	return dis[b];
}

ll answer(int a, int ak, int b, int bk){
	int lc = lca(a, b);
	int la = lev[a]-lev[lc];
	int lb = lev[b]-lev[lc];
	ll dis = INF;
	FOR(i, 2){
		dis = std::min(dis, get(a, ak, la, i)+get(b, bk, lb, i));
	}
	return dis;
}

std::vector<std::vector<PR<int, ll> > > alt;
void dijkstra(){
	cost.resize(n+1, INF);
	std::vector<bool> vis(n+1);
	cost[n] = 0;
	std::priority_queue<PR<ll, int> > que;
	que.push(MP(0, n));
	int done = 0;
	while(done <= n){
		int v = que.top().Y;
		que.pop();
		if(vis[v]) continue;
		vis[v] = true;
		done++;
		TRAV(ch, alt[v]){
			if(cost[ch.X] > cost[v]+ch.Y){
				cost[ch.X] = cost[v]+ch.Y;
				que.push(MP(-cost[ch.X], ch.X));
			}
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	alt.resize(n+1);
	ll tmp;
	FOR(i, n) std::cin >> tmp, alt[n].push_back(MP(i, tmp));
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		ll w1, w2;
		std::cin >> w1 >> w2;
		g[a].push_back(MP(b, ed(w1, w2)));
		g[b].push_back(MP(a, ed(w1, w2)));
		alt[a].push_back(MP(b, w1+w2));
		alt[b].push_back(MP(a, w1+w2));
	}
	dijkstra();
	prepare();
	int q;
	std::cin >> q;
	FOR(_, q){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		int ak = a&1;
		int bk = b&1;
		std::cout << answer(a/2, ak, b/2, bk) << "\n";
	}
	return 0;
}