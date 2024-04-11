// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
// #define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct line {
	cat a, c;
	short id;

	bool operator<(const line & l) const {
		return c < l.c;
	}
};

struct FlowEdge {
	short v, u;
	short cap, cost;
};

struct Flow {
	const short inf = 16 + (16<<8);
	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	short n;
	int m = 0;
	short s, t;
	vector<short> ptr, vis;
	deque<short> dq;

	Flow(short n_, short s_, short t_) : n(n_), s(s_), t(t_) {
		adj.resize(n_);
		vis.resize(n_);
		ptr.resize(n_);
		srand(n);
	}

	void add_edge(short v, short u, short cap, short cost = 0) {
		edges.push_back({v, u, cap, cost});
		edges.push_back({u, v, 0, -cost});
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	void add_bidirectional_edge(short v, short u, short cap) {
		edges.push_back({v, u, cap, 0});
		edges.push_back({u, v, cap, 0});
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	void clear() {
		m = 0;
		edges.clear();
		for(short i = 0; i < n; i++) adj[i].clear();
	}

	short dfs(short v, short x) {
		vis[v] = x;
		if (v == t)
			return 1;
		for (short& cid = ptr[v]; cid < (short)adj[v].size(); cid++) {
			int id = adj[v][cid];
			short u = edges[id].u;
			if (vis[u] == x || !edges[id].cap)
				continue;
			short tr = dfs(u, x);
			if (tr == 0)
				continue;
			edges[id].cap--;
			edges[id ^ 1].cap++;
			return 1;
		}
		return 0;
	}

	short flow() {
		for(int i = 0; i < n; i++)
			for(int j = 0; j < (int)adj[i].size(); j++)
				swap(adj[i][j], adj[i][rand()%(j+1)]);
		short f = 0, r = 0;
		memset(&vis[0], 0, sizeof(short)*n);
		while(true) {
			memset(&ptr[0], 0, sizeof(short)*n);
			bool stop = true;
			while (true) {
				short pushed = dfs(s, r+1);
				r++;
				if(pushed == 0) break;
				f++;
				stop = false;
			}
			if(stop) break;
		}
		return f;
	}

	void shortest_paths(vector<short>& d, vector<int>& p) {
		memset(&d[0], inf >> 8, sizeof(short)*n);
		d[s] = 0;
		static vector<char> M = vector<char>(n);
		memset(&M[0], 2, n);
		dq.push_back(s);
		memset(&p[0], -1, sizeof(int)*n);

		while (!dq.empty()) {
			int u = dq.front();
			dq.pop_front();
			M[u] = 0;
			if(d[t]) for (int id : adj[u]) {
				if (edges[id].cap && d[edges[id].u] > d[u] + edges[id].cost) {
					d[edges[id].u] = d[u] + edges[id].cost;
					p[edges[id].u] = id;
					if (M[edges[id].u] == 2) {
						M[edges[id].u] = 1;
						dq.push_back(edges[id].u);
					} else if (M[edges[id].u] == 0) {
						M[edges[id].u] = 1;
						dq.push_front(edges[id].u);
					}
				}
			}
		}
	}

	short min_cost_flow(short K) {
		short flow = 0;
		short cost_ = 0;
		vector<short> d(n);
		vector<int> p(n);
		while (flow < K) {
			shortest_paths(d, p);
			if (d[t] == inf)
				break;

			// apply flow
			flow++;
			cost_ += d[t];
			short cur = t;
			while (cur != s) {
				edges[p[cur] ^ 1].cap++;
				edges[p[cur]].cap--;
				cur = edges[p[cur]].v;
			}
		}
		if (flow < K)
			return -1;
		else
			return cost_;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	short N;
	cin >> N;
	vector<line> L(2*N);
	for(int i = 0; i < 2*N; i++) {
		cin >> L[i].a >> L[i].c;
		L[i].id = i;
	}
	sort(begin(L), end(L));
	cat T_min = -1, T_max = OVER9000;
	Flow solver = Flow(6*N+2, 0, 6*N+1);
	while(T_max-T_min > 1) {
		cat T = (T_min + T_max) / 2;
		// cout << T << endl;
		vector< pair<cat, int> > val_init(2*N), val_fin(2*N);
		vector<cat> val_max(2*N), val_max_a(2*N);
		for(int i = 0; i < 2*N; i++) {
			val_init[i] = {L[i].c, i};
			val_max[i] = L[i].c + T * L[i].a;
			val_fin[i] = {L[i].c + T * L[i].a, i};
		}
		sort(begin(val_init), end(val_init));
		sort(begin(val_fin), end(val_fin));
		cat D = 0;
		for(cat k = (1<<30); k >= 1; k /= 2) if(T >= D+k) {
			bool dif = false;
			for(int i = 0; i < 2*N-1; i++) {
				cat x = L[val_fin[i].ss].a * (T-D-k) + L[val_fin[i].ss].c;
				cat y = L[val_fin[i+1].ss].a * (T-D-k) + L[val_fin[i+1].ss].c;
				if(x > y) {
					dif = true;
					break;
				}
			}
			if(!dif) D += k;
		}
		for(int i = 0, next = 0; i < 2*N; i++) {
			cat val = L[i].c + T * L[i].a;
			while(next < 2*N && L[next].c <= L[i].c) next++;
			for(int j = next; j < 2*N; j++) if(val > val_max[j]) {
				val_max[j] = val;
				val_max_a[j] = L[i].a;
			}
		}
		solver.clear();
		for(short i = 0; i < 2*N-1; i++) {
			if(val_init[i].ff == val_init[i+1].ff)
				solver.add_bidirectional_edge(1+L[val_init[i].ss].id, 1+L[val_init[i+1].ss].id, N);
			else
				solver.add_edge(1+L[val_init[i+1].ss].id, 1+L[val_init[i].ss].id, N);
		}
		for(short i = 0; i < 2*N-1; i++) {
			if(val_fin[i].ff == val_fin[i+1].ff)
				solver.add_bidirectional_edge(1+L[val_fin[i].ss].id+2*N, 1+L[val_fin[i+1].ss].id+2*N, N);
			else
				solver.add_edge(1+L[val_fin[i+1].ss].id+2*N, 1+L[val_fin[i].ss].id+2*N, N);
		}
		for(short i = 0; i < 2*N; i++) if(L[i].id < N) {
			pair<cat, int> p = {val_max[i], 2*N+1};
			auto it = upper_bound(begin(val_fin), end(val_fin), p);
			it--;
			solver.add_edge(1+L[i].id, 1+L[it->ss].id+2*N, N);
			if(L[it->ss].a < L[i].a)
				D = min(D, (L[i].a*T+L[i].c - (L[it->ss].a*T+L[it->ss].a)) / (L[i].a-L[it->ss].a));
		}
		D = max(0LL, D);
		for(short i = 0; i < 2*N; i++) {
			solver.add_edge(1+i, 1+i+2*N, N);
		}
		for(short i = 0; i < N; i++) {
			solver.add_edge(0, 1+i, 1);
			solver.add_edge(4*N-i, 6*N+1, 1);
		}
		if(solver.flow() < N) T_min = T;
		else T_max = T-D;
	}
	if(T_max == OVER9000) {
		cout << "-1\n";
		return 0;
	}
	cout << T_max << " ";
	{
		cat T = T_max;
		vector< pair<cat, int> > val_init(2*N), val_fin(2*N);
		vector<cat> val_max(2*N);
		for(int i = 0; i < 2*N; i++) {
			val_init[i] = {L[i].c, i};
			val_max[i] = L[i].c + T * L[i].a;
			val_fin[i] = {L[i].c + T * L[i].a, i};
		}
		for(int i = 0, next = 0; i < 2*N; i++) {
			cat val = L[i].c + T * L[i].a;
			while(next < 2*N && L[next].c <= L[i].c) next++;
			for(int j = next; j < 2*N; j++) val_max[j] = max(val_max[j], val);
		}
		sort(begin(val_init), end(val_init));
		sort(begin(val_fin), end(val_fin));
		solver.clear();
		for(short i = 0; i < 2*N-1; i++) {
			if(val_init[i].ff == val_init[i+1].ff)
				solver.add_bidirectional_edge(1+L[val_init[i].ss].id+N, 1+L[val_init[i+1].ss].id+N, N);
			else
				solver.add_edge(1+L[val_init[i+1].ss].id+N, 1+L[val_init[i].ss].id+N, N);
		}
		for(short i = 0; i < 2*N-1; i++) {
			if(val_fin[i].ff == val_fin[i+1].ff)
				solver.add_bidirectional_edge(1+L[val_fin[i].ss].id+3*N, 1+L[val_fin[i+1].ss].id+3*N, N);
			else
				solver.add_edge(1+L[val_fin[i+1].ss].id+3*N, 1+L[val_fin[i].ss].id+3*N, N);
		}
		for(short i = 0; i < 2*N; i++) if(L[i].id < N) {
			pair<cat, int> p = {val_max[i], 2*N+1};
			auto it = upper_bound(begin(val_fin), end(val_fin), p);
			it--;
			solver.add_edge(1+L[i].id+N, 1+L[it->ss].id+3*N, N, 1);
		}
		for(short i = 0; i < 2*N; i++) {
			solver.add_edge(1+i+N, 1+i+3*N, N, 1);
		}
		for(short i = 0; i < N; i++) {
			solver.add_edge(1+i, 1+i+N, N);
			solver.add_edge(1+i, 1+i+3*N, N);
		}
		for(short i = 0; i < N; i++) {
			solver.add_edge(1+i+2*N, 1+i+5*N, N);
			solver.add_edge(1+i+4*N, 1+i+5*N, N);
		}
		for(short i = 0; i < N; i++) {
			solver.add_edge(0, 1+i, 1);
			solver.add_edge(6*N-i, 6*N+1, 1);
		}
		cout << solver.min_cost_flow(N)+N << "\n";
	}

	return 0;
}

// look at my code
// my code is amazing