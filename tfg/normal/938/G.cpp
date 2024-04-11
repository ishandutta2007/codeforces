#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <cstdio>

typedef std::pair<int, int> ii;

const int ms = 1 << 18;
const int me = 31;

struct Edge {
	int x, y, w;
};

struct Info {
	int x, y, idx;
};

struct Disjoint_Set {
public:
	struct Element {
		Element(int i = 0) {
			par = i;
			for(int j = 0; j < me; j++) {
				gauss[j] = 0;
			}
			up = 0;
			size = 1;
		}
		int par;
		int gauss[me];
		int up;
		int size;

		void add(int x) {
			for(int j = me - 1; j >= 0; j--) {
				if(x & (1 << j)) {
					if(gauss[j] == 0) {
						gauss[j] = x;
						break;
					}
					x ^= gauss[j];
				}
			}
		}

		int qry(int x) {
			for(int j = me - 1; j >= 0; j--) {
				x = std::min(x, x ^ gauss[j]);
			}
			return x;
		}

		void make_union(Element e) {
			for(int j = 0; j < me; j++) {
				if(e.gauss[j] != 0) {
					add(e.gauss[j]);
				}
			}
			size += e.size;
		}
	};

	void init(int n) {
		nodes.resize(n);
		for(int i = 0; i < n; i++) {
			nodes[i] = Element(i);
		}
	}

	int make_union(int a, int b, int w) {
		ii elems[2];
		elems[0] = get_par(a);
		elems[1] = get_par(b);
		a = elems[0].first;
		b = elems[1].first;
		//std::cout << "(" << elems[0].first << ", " << elems[0].second << ")\n";
		//std::cout << "(" << elems[1].first << ", " << elems[1].second << ")\n";
		if(a == b) {
			st.push_back(nodes[a]);
			nodes[a].add(elems[0].second ^ elems[1].second ^ w);
			//std::cout << "found cycle of " << (elems[0].second ^ elems[1].second ^ w) << "\n";
			return 1;
		} else {
			if(nodes[a].size < nodes[b].size) {
				std::swap(a, b);
				std::swap(elems[0], elems[1]);
			}
			st.push_back(nodes[a]);
			st.push_back(nodes[b]);
			nodes[b].up = w ^ elems[1].second ^ elems[0].second;
			nodes[b].par = a;
			nodes[a].make_union(nodes[b]);
			return 2;
		}
	}

	int qry(int u, int v) {
		int top = get_par(u).first;
		int w = get_par(u).second ^ get_par(v).second;
		//std::cout << "for query " << u << ", " << v << " here, path is " << w << "\n";
		return nodes[top].qry(w);
	}

	ii get_par(int a, int x = 0) {
		if(a == nodes[a].par) {
			return ii(a, x);
		} else {
			return get_par(nodes[a].par, x ^ nodes[a].up);
		}
	}

	void roll_back() {
		nodes[st.back().par] = st.back();
		st.pop_back();
	}
private:
	std::vector<Element> nodes;
	std::vector<Element> st;
};

std::vector<Edge> tree[2 * ms];
std::vector<Info> queries[ms];
int k;

void add(int l, int r, Edge e) {
	//std::cout << "(" << l << ", " << r << "): ";
	//std::cout << "adding edge (" << e.x << ", " << e.y << ", " << e.w << ")\n";
	for(l += k, r += k; l < r; l /= 2, r /= 2) {
		if(l & 1) {
			//std::cout << "got on " << l << "\n";
			tree[l++].push_back(e);
		}
		if(r & 1) {
			tree[--r].push_back(e);
			//std::cout << "got on " << r << "\n";
		}
	}
}

Disjoint_Set DSU;
int ans[ms];

void dfs(int p = 1) {
	//std::cout << "dfs on " << p << ", [" << l << ", " << r << "[\n";
	
	int got = 0;
	for(auto e : tree[p]) {
		//std::cout << "using edge " << e.x << ", " << e.y << ", " << e.w << "\n";
		got += DSU.make_union(e.x, e.y, e.w);
	}
	if(p >= k) {
		p -= k;
		for(auto a : queries[p]) {
			ans[a.idx] = DSU.qry(a.x, a.y);
		}
	} else {
		dfs(p + p);
		dfs(p + p + 1);
	}
	while(got--) {
		//std::cout << "popping on [" << l << ", " << r << "[\n";
		DSU.roll_back();
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	DSU.init(n);
	int q = 0;
	std::map<ii, ii> from;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		//std::cin >> x >> y >> w;
		scanf("%i %i %i", &x, &y, &w);
		x--;y--;
		from[ii(x, y)] = ii(0, w);
	}
	std::cin >> m;
	k = m + 1;
	for(int i = 1; i <= m; i++) {
		int t, x, y;
		//std::cin >> t >> x >> y;
		scanf("%i %i %i", &t, &x, &y);
		x--;
		y--;
		if(t == 1) {
			int w;
			//std::cin >> w;
			scanf("%i", &w);
			from[ii(x, y)] = ii(i, w);
		} else if(t == 2) {
			ii wut = from[ii(x, y)];
			int l = wut.first;
			int r = i;
			int w = wut.second;
			Edge e;
			e.x = x;
			e.y = y;
			e.w = w;
			add(l, r, e);
			from.erase(ii(x, y));
		} else {
			Info a;
			a.x = x;
			a.y = y;
			a.idx = q++;
			queries[i].push_back(a);
		}
	}
	for(auto e : from) {
		Edge a;
		a.x = e.first.first;
		a.y = e.first.second;
		a.w = e.second.second;
		int l = e.second.first;
		int r = m + 1;
		add(l, r, a);
	}
	dfs();
	for(int i = 0; i < q; i++) {
		printf("%i\n", ans[i]);
	}
}