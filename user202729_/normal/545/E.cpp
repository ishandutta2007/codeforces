#include <iostream>
#include <vector>
#include <queue>
#include <limits>

//{
struct _read_type {
	std::istream& str;
	_read_type(std::istream& str) : str (str) {}
	template <typename T>
	_read_type operator , (T& t) { str >> t; return *this; }
} _read (std::cin);
struct _write_type {
	std::ostream& str;
	_write_type(std::ostream& str) : str (str) {}
	template <typename T>
	_write_type operator , (T t) { str << t; return *this; }
} _write (std::cout);
#define  read _read ,
#define write _write,
//}

struct edge {
	int node, id;
	int len;
};

struct state {
	int64_t dist;
	int node, edgelen, edgeid;
};
bool operator < (state const & s1, state const & s2) {
	if (s1.dist != s2.dist) return s1.dist > s2.dist;
	return s1.edgelen > s2.edgelen;
}

main() {
	int nnode, nedge; read nnode, nedge;
	std::vector<std::vector<edge>> adjlist (nnode);
	for (int edge_i = 1; edge_i <= nedge; ++edge_i) {
		int u, v, w;
		read u, v, w;
		--u; --v;
		adjlist[u].push_back({v, edge_i, w});
		adjlist[v].push_back({u, edge_i, w});
	}
	int source; read source; --source;

	std::priority_queue<state> states;
	std::vector<int64_t> dist (nnode, std::numeric_limits<int64_t>::max());
	std::vector<bool> reached (nnode, false);

	states.push({
	0, // dist
	source, // node
	1234, // edgelen. not important because dist is smallest
	0 // edge id
	});
	dist[source] = 0;

	std::vector<int> edgeids;
	int64_t sumlen = 0;
	while (!states.empty()) {
		state st = states.top(); states.pop();
		if (st.dist != dist[st.node] || reached[st.node]) continue;

		if (st.edgeid != 0) {
			edgeids.push_back(st.edgeid);
			sumlen += st.edgelen;
		}
		reached[st.node] = true;
		for (edge e : adjlist[st.node]) {
			if (st.dist + (int64_t)e.len <= dist[e.node]) { // must be <=
				states.push({
					dist[e.node] = st.dist + (int64_t)e.len, // dist
					e.node, // node
					e.len, // edgelen. not important because dist is smallest
					e.id // edge id
				});
			}
		}
	}

	write sumlen, '\n';
	for (int& x : edgeids) write x, ' ';
	write '\n';
}