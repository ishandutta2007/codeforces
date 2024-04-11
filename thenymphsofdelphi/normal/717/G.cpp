#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){ return rando() % (r - l + 1) + l; }

template<class T, class C>
struct min_cost_max_flow{
	static constexpr T eps = (T) 1e-9;
	struct Edge{
		int from, to;
		T capacity, flow;
		C cost;
	};
	vector<vector<int>> adj;
	vector<Edge> edge;
	vector<C> d;
	vector<bool> in_queue;
	vector<int> q, pe;
	int n, source, sink;
	T flow = 0;
	C cost = 0;
	min_cost_max_flow(int n, int source, int sink): n(n), source(source), sink(sink), adj(n), d(n), in_queue(n), pe(n){ }
	void clear(){
		for(auto &e: edge) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T forward_cap, T backward_cap, C cost){
		assert(0 <= from && from < n && 0 <= to && to < n);
		int ind = int(edge.size());
		adj[from].push_back((int)edge.size());
		edge.push_back({from, to, forward_cap, 0, cost});
		adj[to].push_back((int)edge.size());
		edge.push_back({to, from, backward_cap, 0, -cost});
		return ind;
	}
	bool expath(){
		fill(d.begin(), d.end(), numeric_limits<C>::max());
		q.clear();
		q.push_back(source);
		d[source] = 0;
		in_queue[source] = true;
		int beg = 0;
		bool found = false;
		while(beg < (int)q.size()){
			int i = q[beg ++];
			if(i == sink) found = true;
			in_queue[i] = false;
			for(int id : adj[i]){
				const auto &e = edge[id];
				if(e.capacity - e.flow > eps && d[i] + e.cost < d[e.to]){
					d[e.to] = d[i] + e.cost;
					pe[e.to] = id;
					if(!in_queue[e.to]){
						q.push_back(e.to);
						in_queue[e.to] = true;
					}
				}
			}
		}
		if(found){
			T push = numeric_limits<T>::max();
			int v = sink;
			while(v != source){
				const auto &e = edge[pe[v]];
				push = min(push, e.capacity - e.flow);
				v = e.from;
			}
			v = sink;
			while(v != source){
				auto &e = edge[pe[v]];
				e.flow += push;
				auto &back = edge[pe[v] ^ 1];
				back.flow -= push;
				v = e.from;
			}
			flow += push;
			cost += push * d[sink];
		}
		return found;
	}
	pair<T, C> solve(){ // O(Augmenting Paths) * O(SPFA)
		while(expath()){ }
		return {flow, cost};
	}
};

int n;
string s;
string t; int x;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> s;
    min_cost_max_flow <int, int> cac(n + 3, 0, n + 2);
    ForE(i, 2, n + 1){
        cac.insert(i - 1, i, 101, 0, 0);
    }
    int q; cin >> q; while (q--){
        cin >> t >> x;
        For(i, isz(t) - 1, isz(s)){
            if (s.substr(i - isz(t) + 1, isz(t)) == t){
                cac.insert(i - isz(t) + 2, i + 2, 1, 0, -x);
            }
        }
    }
    cin >> x;
    cac.insert(0, 1, x, 0, 0); cac.insert(n + 1, n + 2, x, 0, 0);
    cout << -cac.solve().se << endl;
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/