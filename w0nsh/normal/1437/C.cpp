#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

using namespace std;

#define pb push_back
#define f first
#define s second
const ll INF = 1e9 + 7;

template< class T > using pqg = priority_queue< T, vector< T >, greater< T > >;
template< class T > T poll(pqg< T > & x){
    T y = x.top(); x.pop();
    return y;
}
template<int SZ> struct mcf{
    struct Edge{int v, rev; ll flow, cap, cost;};
    vector<Edge> adj[SZ];
    void addEdge(int u, int v, ll cap, ll cost){
        Edge a{v, adj[v].size(), 0, cap, cost}, b{u, adj[u].size(), 0, 0, -cost};
        adj[u].pb(a), adj[v].pb(b);
    }
    int ST, EN;
    pair<int, int> pre[SZ];
    pair<ll, ll> cost[SZ];
    ll totFlow, totCost, curCost;
    void reweight(){
    	for(int i = 0 ; i < SZ; i++)
    	 	for(auto & p : adj[i])
    	 		p.cost += cost[i].f - cost[p.v].f;
    }
    bool spfa(){
        for(int i = 0; i < SZ; i++) cost[i] = {INF, 0};
        cost[ST] = {0, INF};
        pqg< pair< ll, int > > todo; todo.push({0, ST});
        while(todo.size()){
            auto x = poll(todo);
            if(x.f > cost[x.s].f) continue;
            for(auto & a : adj[x.s]) if(x.f + a.cost < cost[a.v].f && a.flow < a.cap){
                pre[a.v] = {x.s, a.rev};
                cost[a.v] = {x.f + a.cost, min(a.cap - a.flow, cost[x.s].s)};
                todo.push({cost[a.v].f, a.v});
            }
        }
        curCost += cost[EN].f;
        return cost[EN].s;
    }
    void backtrack(){
        auto f = cost[EN].s; totFlow += f, totCost += curCost*f;
        for (int x = EN; x != ST; x = pre[x].f){
            adj[x][pre[x].s].flow -= f;
            adj[pre[x].f][adj[x][pre[x].s].rev].flow += f;
        }
    }
    pair<ll, ll> minCostFlow(int _ST, int _EN) {
        ST = _ST, EN = _EN; totFlow = totCost = curCost = 0;
        spfa();
        while (1) {
            reweight();
            if (!spfa()) return {totFlow, totCost};
            backtrack();
        }
    }
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i], A[i]--;

		mcf<1002> mc;
		int ILE = 450;
		FOR(i, ILE) mc.addEdge(0, i+2, 1, 0);
		FOR(i, n) mc.addEdge(ILE+2+i, 1, 1, 0);
		FOR(i, ILE){
			FOR(j, n){
				mc.addEdge(2+i, ILE+2+j, 1, std::abs(A[j]-i));
			}
		}

		auto xd = mc.minCostFlow(0, 1);
		assert(xd.X == n);
		std::cout << xd.Y << "\n";
	}
	return 0;
}