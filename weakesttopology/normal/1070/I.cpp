#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

struct Edge{
	int v, rev, cap;
	Edge(int v, int cap, int rev): v(v), cap(cap), rev(rev){}
};

struct MaxFlow {
	vector<vector<Edge> > g;
	vector<int> level;
	queue<int> q;
	int n;
	MaxFlow(int n) : g(n), level(n), n(n){}

	void addEdge(int u, int v, int cap){
		Edge e(v, cap, int(g[v].size()));
		Edge r(u, 0, int(g[u].size()));
		g[u].push_back(e);
		g[v].push_back(r);
	}
	
	int buildLevelGraph(int s, int t){
		fill(level.begin(), level.end(), -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto e: g[u]){
				if(level[e.v] == -1 && e.cap){
					level[e.v] = level[u] + 1;
					if(e.v == t) return 1;
					q.push(e.v);
				}
			}
		}
		return 0;	
	}

	int blockingFlow(int s, int t, int f){
		if(s == t || !f) return f;
		int fu = 0;
		for(auto& e: g[s]){
			if(e.cap && level[e.v] == level[s] + 1){
				int mincap = blockingFlow(e.v, t, min(e.cap, f - fu));
				g[e.v][e.rev].cap += mincap;
				e.cap -= mincap;
				fu += mincap;
			}
		}
		if(!fu) level[s] = -1;
		return fu;
	}

	int maxflow(int s, int t){
		int flow = 0;
		while(buildLevelGraph(s, t))
			flow += blockingFlow(s, t, INF);
		return flow;
	}
	
	vi getEdges(int u){
		vi res;
		for(auto e: g[u]){
			if(!e.cap) res.push_back(e.v);
		}
		return res;
	}
};

void test_case(){
	int n, m, k, a, b;
	cin >> n >> m >> k;
	vvii g(n);
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--;b--;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	MaxFlow mf(n+m+2);
	int s = n+m, t = n+m+1;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int sz = int(g[i].size())-k;
		if(sz >0){
			cnt += 2 * sz;
			mf.addEdge(s, i, 2 * sz);
		}
		for(auto [v, id]: g[i])
			mf.addEdge(i, id+n, 1);
	}
	for(int i = 0; i < m; i++)
		mf.addEdge(i+n, t, 1);
	vi color(m);	
	int x = 1;
	if(mf.maxflow(s, t) ==	cnt){
		for(int i = 0; i < n; i++){
			vi edges = mf.getEdges(i);
			for(int j = 0; j < edges.size(); j+=2){
				color[edges[j]-n] = color[edges[j+1]-n] = x++;
			}
		}
		for(auto &c: color){
			if(!c) c = x++;
		}
	}	
	for(auto c: color)cout << c << " ";
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}