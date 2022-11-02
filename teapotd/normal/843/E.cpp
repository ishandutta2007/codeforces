#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr int INF = 1e9+10;

struct MaxFlow {
	using T = int;

	struct Edge {
		int dst, inv;
		T flow, cap;
	};

	struct Vert {
		vector<Edge> E;
		int prev;
		T add;
	};

	vector<Vert> G;

	MaxFlow(int n = 0) { init(n); }
	void init(int n) { G.assign(n, {}); }

	int addVert() {
		G.emplace_back();
		return sz(G)-1;
	}

	void addEdge(int u,int v,int cap,int rcap=0){
		G[u].E.pb({ v, sz(G[v].E), 0, cap });
		G[v].E.pb({ u, sz(G[u].E)-1, 0, rcap });
	}

	T maxFlow(int src, int dst) {
		T f = 0;

		do {
			each(v, G) v.prev = v.add = -1;
			queue<int> Q;
			Q.push(src);
			G[src].add = INF;

			while (!Q.empty()) {
				int i = Q.front();
				T m = G[i].add;
				Q.pop();

				if (i == dst) {
					while (i != src) {
						auto& e = G[i].E[G[i].prev];
						e.flow -= m;
						G[e.dst].E[e.inv].flow += m;
						i = e.dst;
					}
					f += m;
					break;
				}

				each(e, G[i].E) if (G[e.dst].add < 0) {
					if (e.flow < e.cap) {
						Q.push(e.dst);
						G[e.dst].prev = e.inv;
						G[e.dst].add = min(m,e.cap-e.flow);
					}
				}
			}
		} while (G[dst].prev != -1);

		return f;
	}
};

MaxFlow flow;
vector<bool> seen;

bool dfs(int i, int dst) {
	if (i == dst) return true;
	if (seen[i]) return false;
	seen[i] = true;

	each(e, flow.G[i].E) {
		if (e.cap == 1 && dfs(e.dst, dst)) {
			e.flow++;
			return true;
		}
	}
	return false;
}

void run() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	s--; t--;

	flow.init(n);
	vector<Pii> edgeMap(m);

	each(e, edgeMap) {
		int a, b, g; cin >> a >> b >> g;
		e.x = a-1;
		e.y = sz(flow.G[a-1].E);
		if (g) {
			flow.addEdge(a-1, b-1, 1, INF);
		} else {
			flow.addEdge(a-1, b-1, INF);
		}
	}

	cout << flow.maxFlow(s, t) << '\n';

	each(v, flow.G) each(e, v.E) e.flow = 0;

	rep(i, 0, n) each(e, flow.G[i].E) if (e.flow == 0 && e.cap == 1) {
		seen.assign(n, 0);
		dfs(s, i);
		seen.assign(n, 0);
		dfs(e.dst, t);
		e.flow++;
	}

	each(ind, edgeMap) {
		auto& v = flow.G[ind.x];
		auto& e = v.E[ind.y];
		auto& u = flow.G[e.dst];

		if (v.add >= 0 && u.add < 0) {
			cout << e.flow << ' ' << e.flow << '\n';
		} else {
			cout << e.flow << ' ' << e.flow+1 << '\n';
		}
	}
}