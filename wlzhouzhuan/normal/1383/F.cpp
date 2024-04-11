#include <bits/stdc++.h>

using namespace std;

template<typename C, typename R = C>
struct dinic
{
	typedef C flow_type;
	typedef R result_type;

	static_assert(std::is_arithmetic<flow_type>::value, "flow_type must be arithmetic");
	static_assert(std::is_arithmetic<result_type>::value, "result_type must be arithmetic");

	static const flow_type oo = std::numeric_limits<flow_type>::max();

	struct edge
	{
		//int src; // not needed, can be deleted to save memory
		int dst;
		int rev;
		flow_type cap, flowp;

		edge(int src, int dst, int rev, flow_type cap, int flowp) :
			/*src(src),*/ dst(dst), rev(rev), cap(cap), flowp(flowp) {}
	};

	dinic(int n) : adj(n), que(n), level(n), edge_pos(n), flow_id(0) {}

	int add_edge(int src, int dst, flow_type cap, flow_type rcap = 0)
	{
		adj[src].emplace_back(src, dst, (int) adj[dst].size(), cap, flow_id++);
		if (src == dst) adj[src].back().rev++;
		adj[dst].emplace_back(dst, src,  (int) adj[src].size() - 1, rcap, flow_id++);
		return (int) adj[src].size() - 1 - (src == dst);
	}

	inline bool side_of_S(int u) { return level[u] == -1; }

	result_type max_flow(int source, int sink, vector<flow_type> &flow_e)
	{
		result_type flow = 0;
		while (true)
		{
			int front = 0, back = 0;
			std::fill(level.begin(), level.end(), -1);
			for (level[que[back++] = sink] = 0; front < back && level[source] == -1; ++front)
			{
				int u = que[front];
				for (const edge &e : adj[u])
					if (level[e.dst] == -1 && flow_e[rev(e).flowp] < rev(e).cap)
						level[que[back++] = e.dst] = 1 + level[u];
			}
			if (level[source] == -1)
				break;
			std::fill(edge_pos.begin(), edge_pos.end(), 0);
			std::function<flow_type(int, flow_type)> find_path = [&](int from, flow_type res)
			{
				if (from == sink)
					return res;
				for (int &ept = edge_pos[from]; ept < (int) adj[from].size(); ++ept)
				{
					edge &e = adj[from][ept];
					if (flow_e[e.flowp] == e.cap || level[e.dst] + 1 != level[from]) continue;
					flow_type push = find_path(e.dst, std::min(res, e.cap - flow_e[e.flowp]));
					if (push > 0)
					{
						flow_e[e.flowp] += push;
						flow_e[rev(e).flowp] -= push;
						if (flow_e[e.flowp] == e.cap)
							++ept;
						return push;
					}
				}
				return static_cast<flow_type>(0);
			};
			for (flow_type f; (f = find_path(source, oo)) > 0;)
				flow += f;
		}
		return flow;
	}

	result_type max_flow2(int source, int sink, vector<flow_type> &flow_e)
	{
		result_type flow = 0;
		std::function<flow_type(int, flow_type)> find_path = [&](int from, flow_type res)
		{
			level[from] = 1;
			if (from == sink)
				return res;
			for (int &ept = edge_pos[from]; ept < (int) adj[from].size(); ++ept)
			{
				edge &e = adj[from][ept];
				if (level[e.dst] == 1 || flow_e[e.flowp] == e.cap) continue;
				flow_type push = find_path(e.dst, std::min(res, e.cap - flow_e[e.flowp]));
				if (push > 0)
				{
					flow_e[e.flowp] += push;
					flow_e[rev(e).flowp] -= push;
					if (flow_e[e.flowp] == e.cap)
						++ept;
					return push;
				}
			}
			return static_cast<flow_type>(0);
		};
		
		for (bool ok = true; ok; )
		{
			int it = 0;
			std::fill(edge_pos.begin(), edge_pos.end(), 0);
			for (flow_type f; ; ++it)
			{
				std::fill(level.begin(), level.end(), -1);
				f = find_path(source, oo);
				if (f == 0)
				{
					if (it == 0) ok = false;
					break;
				}
				flow += f;
			}
		}
		return flow;
	}

	int flow_id;
private:
	std::vector<std::vector<edge>> adj;
	std::vector<int> que;
	std::vector<int> level;
	std::vector<int> edge_pos;

	inline edge& rev(const edge &e) { return adj[e.dst][e.rev]; }
};

const int inf = 25;

struct edge
{
	int u, v, w;
};

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void relabel(int n, vector<edge> &e, int k)
{
	shuffle(e.begin() + k, e.end(), rng);

	vector<vector<pair<int, int>>> adj(n);
	for (auto &i : e)
		adj[i.u].push_back({ i.v, &i-&e[0] });

	vector<edge> ne = e;
	vector<int> id(n, -1);
	id[0] = 0;
	id[n-1] = n-1;
	int sz = 1, esz = k;

	function<void(int)> dfs = [&](int u)
	{
		for (auto &v : adj[u])
		{
			if (v.second >= k)
			{
				ne[esz++] = e[v.second];
				v.second = -1;
			}
			if (id[v.first] == -1)
			{
				id[v.first] = sz++;
				dfs(v.first);
			}
		}
	};
	dfs(0);
	
	for (auto &u : adj)
		for (auto v : u)
			if (v.second >= k)
				ne[esz++] = e[v.second];
	
	for (int i = 0; i < n; ++i)
		if (id[i] == -1)
			id[i] = sz++;
			
	e = ne;
	for (auto &i : e)
	{
		i.u = id[i.u];
		i.v = id[i.v];
	}
}

struct masks
{
	int x, cost;
	vector<int> flow_e;
	
	bool operator<(const masks &o) const
	{
		return cost < o.cost;
	}
};

typedef std::chrono::_V2::system_clock::time_point timepoint;

timepoint get_time()
{
	return std::chrono::high_resolution_clock::now();
}

int get_elapsed(timepoint t)
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(get_time() - t).count();
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector<edge> e(m);
	for (auto &i : e) cin >> i.u >> i.v >> i.w, --i.u, --i.v;

	vector<int> mask(1 << k, -1);
	
	relabel(n, e, k);
	dinic<int> d(n);
	for (int i = 0; i < m; ++i)
		d.add_edge(e[i].u, e[i].v, ((i < k) ? inf : e[i].w));

	vector<int> flow_e(d.flow_id);
	for (int i = 0; i < k; ++i)
		flow_e[2*i] = inf;

	mask[0] = d.max_flow(0, n-1, flow_e);
	
	priority_queue<masks> pq;
	pq.push({ 0, 0, flow_e });
	while (!pq.empty())
	{
		int x = pq.top().x;
		flow_e = pq.top().flow_e;
		pq.pop();
		
		for (int j = 0; j < k; ++j)
			if ((~x >> j & 1) && mask[x | 1 << j] == -1)
			{
				auto n_flow_e = flow_e;
				n_flow_e[2 * j] = 0;
				auto t = get_time();
				mask[x | 1 << j] = mask[x] + d.max_flow2(0, n-1, n_flow_e);
				pq.push({ x | 1 << j, get_elapsed(t), n_flow_e });
			}
	}

	vector<int> cut(1 << k), bit(1 << k);
	for (int i = 1; i < 1 << k; ++i)
		bit[i] = i & -i;

	const int U = (1 << k) - 1;
	while (q--)
	{
		for (int i = 0; i < k; ++i)
			cin >> cut[1 << i];

		int ans = mask[U];
		for (int i = 1; i < 1<<k; ++i)
		{
			cut[i] = cut[i ^ bit[i]] + cut[bit[i]];
			ans = min(ans, cut[i] + mask[U ^ i]);
		}
		cout << ans << "\n";
	}

	return 0;
}