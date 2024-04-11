// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 123456789000000LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

void DFS(int v, auto & G, auto & C, auto & C_cur, auto & prev) {
	if(C_cur[1]) return;
	for(auto s : G[v]) if(C_cur[s] == 0 && C[v][s] > 0) {
		C_cur[s] = min(C[v][s], C_cur[v]);
		prev[s] = v;
		DFS(s, G, C, C_cur, prev);
		if(C_cur[1]) break;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	map< pair<int,int>, vector<int> > P;
	vector< vector<cat> > C(2*N+2, vector<cat>(2*N+2, 0));
	vector< vector<int> > G(2*N+2);
	int V = 2;
	for(int i = 0; i < N; i++) {
		int x,y;
		cin >> x >> y;
		if(x%2 == 0) {
			P[{x,y}] = {V, V+1};
			cin >> C[V][V+1];
			G[V].push_back(V+1);
			G[V+1].push_back(V);
			V += 2;
		}
		else {
			P[{x,y}] = {V};
			if(y%2 == 0) {
				cin >> C[0][V];
				G[0].push_back(V);
				G[V].push_back(0);
			}
			else {
				cin >> C[V][1];
				G[V].push_back(1);
				G[1].push_back(V);
			}
			V++;
		}
	}
	cat ans = 0;
	for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) ans += C[i][j];
	for(auto p : P) if(p.ff.ff%2 == 0) {
		int id0 = (p.ss)[0], id1 = (p.ss)[1];
		for(int dx = -1; dx <= 1; dx += 2) {
			pair<int,int> p2 = {p.ff.ff+dx, p.ff.ss};
			auto it = P.find(p2);
			if(it == end(P)) continue;
			int id = (it->ss)[0];
			if(p.ff.ss%2 == 0) {
				C[id][id0] = OVER9000;
				G[id].push_back(id0);
				G[id0].push_back(id);
			}
			else {
				C[id1][id] = OVER9000;
				G[id].push_back(id1);
				G[id1].push_back(id);
			}
		}
		if(p.ff.ss%2 != 0) continue;
		for(int dy = -1; dy <= 1; dy += 2) {
			pair<int,int> p2 = {p.ff.ff, p.ff.ss+dy};
			auto it = P.find(p2);
			if(it == end(P)) continue;
			int id = (it->ss)[0];
			C[id1][id] = OVER9000;
			G[id1].push_back(id);
			G[id].push_back(id1);
		}
	}
	while(true) {
		vector<cat> C_cur(V, 0);
		vector<int> prev(V);
		C_cur[0] = OVER9000;
		DFS(0, G, C, C_cur, prev);
		if(C_cur[1] == 0) break;
		cat d = C_cur[1];
		ans -= d;
		int cur = 1;
		while(cur) {
			C[prev[cur]][cur] -= d;
			C[cur][prev[cur]] += d;
			cur = prev[cur];
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing