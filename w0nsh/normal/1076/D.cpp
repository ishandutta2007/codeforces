#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

const ll INF = 1000000000ll*1000000000ll;

struct Edge{
	int v, w, ind;
	Edge() : v(0), w(0), ind(0) {}
	Edge(int a, int b, int c) : v(a), w(b), ind(c) {}
};
int n, m, k;
std::vector<std::vector<Edge> > g;
std::vector<std::vector<PII> > ng;
std::vector<PII> edges;

std::set<int> delt;
int left_del = 0;

void dfs(int v, int par=-1, int ed=-1){
	TRAV(ch, ng[v]) if(ch.X != par) dfs(ch.X, v, ch.Y);
	if(left_del > 0) delt.insert(ed), left_del--;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	g.resize(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		a--;b--;
		g[a].push_back(Edge(b, c, i));
		g[b].push_back(Edge(a, c, i));
		edges.push_back(MP(a, b));
	}
	std::vector<int> acc;
	std::priority_queue<PR<ll, PII> > que;
	que.push(MP(0, MP(0, -1)));
	std::vector<bool> vis(n);
	std::vector<ll> d(n, INF);
	d[0] = 0;
	while(!que.empty()){
		auto xd = que.top().Y;
		que.pop();
		if(vis[xd.X]) continue;
		vis[xd.X] = true;
		if(xd.Y >= 0) acc.push_back(xd.Y);
		int cur = xd.X;
		TRAV(ch, g[cur]){
			if(!vis[ch.v] && d[ch.v] > d[cur] + ch.w){
				d[ch.v] = d[cur] + ch.w;
				que.push(MP(-d[ch.v], MP(ch.v, ch.ind)));
			}
		}
	}
	ng.resize(n);
	left_del = SZ(acc)-k;
	TRAV(i, acc){
		// std::cout << "ed " << edges[i].X+1 << " "<< edges[i].Y+1 << "\n";
		ng[edges[i].X].push_back(MP(edges[i].Y, i));
		ng[edges[i].Y].push_back(MP(edges[i].X, i));
	}
	dfs(0);
	std::cout << SZ(acc) - SZ(delt) << "\n";
	TRAV(i, acc){
		if(delt.count(i) == 0) std::cout << i+1 << " ";
	}
	std::cout << "\n";
	return 0;
}