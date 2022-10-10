#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n = 0): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edge[id];
			int v = u ^ e.from ^ e.to;
			res[u].push_back(v);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

// Requires graph
template<class T>
struct dfs_forest{
	int n;
	vector<T> dist;
	vector<int> pv;
	vector<int> pe;
	vector<int> order;
	vector<int> pos;
	vector<int> end;
	vector<int> size;
	vector<int> root;
	vector<int> depth;
	vector<int> min_depth;
	vector<int> min_depth_origin;
	vector<int> min_depth_spanning_edge;
	vector<int> was;
	T T_id;
	dfs_forest(int n, T T_id = 0): T_id(T_id){ init(n); }
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		size.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		min_depth_origin.assign(n, -1);
		min_depth_spanning_edge.assign(n, -1);
		dist.assign(n, T_id);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	template<class U, class F = plus<>>
	void dfs(const graph<U> &g, int u, bool clear_order = true, F UT = plus<>()){
		assert(n == g.n);
		++ attempt;
		depth[u] = 0;
		dist[u] = T_id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		auto recurse = [&](auto self, int u)->void{
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			size[u] = 1;
			min_depth[u] = depth[u];
			min_depth_origin[u] = u;
			min_depth_spanning_edge[u] = -1;
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					if(min_depth[u] > depth[v]){
						min_depth[u] = depth[v];
						min_depth_spanning_edge[u] = id;
					}
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = UT(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				self(self, v);
				size[u] += size[v];
				if(min_depth[u] > min_depth[v]){
					min_depth[u] = min_depth[v];
					min_depth_origin[u] = min_depth_origin[v];
					min_depth_spanning_edge[u] = min_depth_spanning_edge[v];
				}
			}
			end[u] = (int)order.size();
		};
		recurse(recurse, u);
	}
	template<class U, class F = plus<>>
	void dfs_all(const graph<U> &g, F UT = plus<>()){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs<U, F>(g, u, false, UT);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, src;
	cin >> n >> m >> src, -- src;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.orient(u, v, 1);
	}
	dfs_forest<int> df(n);
	df.dfs(g, src);
	vector<int> root(n, -1);
	auto get_path = [&](int u)->vector<int>{
		vector<int> path{u};
		for(auto v = u; v != src; ){
			path.push_back(v = df.pv[v]);
		}
		ranges::reverse(path);
		assert((int)path.size() == df.depth[u] + 1);
		return path;
	};
	for(auto id: g.adj[src] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
		auto &e = g.edge[id];
		int u = src ^ e.from ^ e.to;
		if(df.pv[u] != src){
			cout << "Possible\n";
			cout << "2\n";
			cout << src + 1 << " " << u + 1 << "\n";
			auto path = get_path(u);
			cout << (int)path.size() << "\n";
			for(auto u: path){
				cout << u + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
		for(auto i = df.pos[u]; i < df.end[u]; ++ i){
			int v = df.order[i];
			root[v] = u;
		}
	}
	for(auto id: g.adj[src] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
		auto &e = g.edge[id];
		int u = src ^ e.from ^ e.to;
		for(auto i = df.pos[u]; i < df.end[u]; ++ i){
			int v = df.order[i];
			for(auto id: g.adj[v] | ranges::views::filter([&](int id){ return !g.ignore || !g.ignore(id);})){
				auto &e = g.edge[id];
				int w = v ^ e.from ^ e.to;
				if(~root[w] && root[w] != root[v]){
					cout << "Possible\n";
					auto pathw = get_path(w);
					cout << (int)pathw.size() << "\n";
					for(auto u: pathw){
						cout << u + 1 << " ";
					}
					cout << "\n";
					auto pathv = get_path(v);
					pathv.push_back(w);
					cout << (int)pathv.size() << "\n";
					for(auto u: pathv){
						cout << u + 1 << " ";
					}
					cout << "\n";
					return 0;
				}
			}
		}
	}
	cout << "Impossible\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////