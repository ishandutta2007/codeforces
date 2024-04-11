//#pragma GCC optimize("Ofast,unroll-loops,sched-spec-load-dangerous,no-stack-protector,peel-loops")
//#pragma GCC target("avx,tune=native")

#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define F(i, l, r) for(int i = (l); i < (r); i++)
#define E(i, l, r) for(int i = (l); i <= (r); i++)
#define DF(i, l, r) for(int i = (l); i >= (r); i--)
#define I(x, a) for(auto x : (a))
#define mp make_pair
#define X first
#define Y second
#define clean(x) memset((x), 0, sizeof(x))
#define ret return
#define cont continue
#define brk break
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sync ios_base::sync_with_stdio(false);cin.tie(0)
#define pb push_back
#define y1 fjfg
#define tm shjfhg

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct Dinic{
	const long long flow_inf = 1e18;
	struct FlowEdge{
		int v, u;
		long long cap, flow = 0;
		FlowEdge(int _v, int _u, long long _cap):v(_v), u(_u), cap(_cap){}
	};
	vector<FlowEdge> edges;
	vector<vector<int> > adj;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	vector<int> q;
	int qh, qt;
	void resize(int _n){n = _n; q.resize(n); adj.resize(n); level.resize(n); ptr.resize(n);}
	Dinic(){}
	Dinic(int _n, int _s, int _t){resize(_n); s = _s; t = _t;}
	void add_edge(int v, int u, long long cap){
		edges.push_back(FlowEdge(v, u, cap));
		edges.push_back(FlowEdge(u, v, 0));
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}
	bool bfs(){
		while(qh < qt){
			int v = q[qh++];
			for(int id : adj[v]){
				if(edges[id].cap - edges[id].flow < 1)continue;
				if(level[edges[id].u] != -1)continue;
				level[edges[id].u] = level[v] + 1;
				q[qt++] = edges[id].u;
			}
		}
		return level[t] != -1;
	}
	long long dfs(int v, long long pushed){
		if(pushed == 0)return 0;
		if(v == t)return pushed;
		for(int & cid = ptr[v]; cid < (int)adj[v].size(); cid++){
			int id = adj[v][cid];
			int u = edges[id].u;
			if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)continue;
			long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if(tr == 0)continue;
			edges[id].flow += tr;
			edges[id^1].flow -= tr;
			return tr;
		}
		return 0;
	}
	long long flow(){
		long long f = 0;
		while(true){
			ptr.assign(n, 0);
			level.assign(n, -1);
			level[s] = 0;
			qh = 0, qt = 1;
			q[0] = s;
			if(!bfs())break;
			while(long long pushed = dfs(s, flow_inf)){f += pushed;}
		}
		return f;
	}
};

signed main() {
	sync;
	int n, m;
	cin >> n >> m;
	Dinic solver(2 + n + m, 0, 1);
	F(i, 0, n){
		int w;
		cin >> w;
		solver.add_edge(i + 2, 1, w);
	}
	ll sum = 0;
	ll infty = (ll)1e18;
	F(i, 0, m){
		int v, u, w;
		cin >> v >> u >> w;
		--v; --u;
		sum += w;
		solver.add_edge(0, 2 + i + n, w);
		solver.add_edge(2 + i + n, 2 + v, infty);
		solver.add_edge(2 + i + n, 2 + u, infty);
	}
	cout << sum - solver.flow();
	return 0;
}