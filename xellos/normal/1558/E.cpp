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
#define OVER9000 1234567890123456789LL
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<cat> A(N, 0), B(N, 0);
		for(int i = 1; i < N; i++) cin >> A[i];
		for(int i = 1; i < N; i++) cin >> B[i];
		vector< vector<int> > G(N);
		vector<int> E(2*M);
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			E[2*i] = --u;
			E[2*i+1] = --v;
			G[u].push_back(2*i+1);
			G[v].push_back(2*i);
		}
		cat incr_init = 0, ans = 0;
		while(N > 1) {
			cat init_lt = 0, init_ge = OVER9000;
			vector<int> prev_ge(N, -1);
			int firstv2_ge = -1;
			while(init_ge-init_lt > 1) {
				cat init = (init_lt+init_ge)/2;
				vector<int> prev(N, -2);
				int firstv2 = -1;
				vector<cat> val(N, 0);
				static queue<int> q;
				for(auto e : G[0]) if(A[E[e]] < init + incr_init) {
					if(prev[E[e]] != -2) {
						firstv2 = E[e];
						break;
					}
					prev[E[e]] = e^1;
					val[E[e]] = init + incr_init + B[E[e]];
					q.push(E[e]);
				}
				while(!q.empty() && firstv2 == -1) {
					int v = q.front();
					q.pop();
					for(auto e : G[v]) if(e/2 != prev[v]/2 && A[E[e]] < val[v]) {
						if(E[e] == 0) {
							prev[0] = e^1;
							firstv2 = 0;
							break;
						}
						if(prev[E[e]] != -2) {
							firstv2 = E[e];
							break;
						}
						prev[E[e]] = e^1;
						val[E[e]] = val[v] + B[E[e]];
						q.push(E[e]);
					}
				}
				while(!q.empty()) q.pop();
				if(firstv2 != -1) {
					init_ge = init;
					prev_ge = prev;
					firstv2_ge = firstv2;
				}
				else init_lt = init;
			}
			if(firstv2_ge == -1) return 1;
			// find this cycle
			ans = max(ans, init_ge);
			vector<int> cyc(1, 0);
			if(firstv2_ge == 0) firstv2_ge = E[prev_ge[firstv2_ge]];
			while(firstv2_ge != 0) {
				cyc.push_back(firstv2_ge);
				firstv2_ge = E[prev_ge[firstv2_ge]];
			}
			// compress graph
			for(auto v : cyc) incr_init += B[v];
			vector<int> id_nw(N, -1);
			for(auto v : cyc) id_nw[v] = 0;
			int N_nw = 1, M_nw = 0;
			for(int i = 0; i < N; i++) if(id_nw[i] == -1) id_nw[i] = N_nw++;
			vector<int> E_nw;
			vector< vector<int> > G_nw(N_nw);
			for(int i = 0; i < M; i++) {
				int u = id_nw[E[2*i]], v = id_nw[E[2*i+1]];
				if(u == v) continue;
				E_nw.push_back(u);
				E_nw.push_back(v);
				G_nw[u].push_back(2*M_nw+1);
				G_nw[v].push_back(2*M_nw);
				M_nw++;
			}
			vector<cat> A_nw(N_nw, 0), B_nw(N_nw, 0);
			for(int i = 0; i < N; i++) if(id_nw[i]) {
				A_nw[id_nw[i]] = A[i];
				B_nw[id_nw[i]] = B[i];
			}
			G = G_nw, E = E_nw, N = N_nw, M = M_nw, A = A_nw, B = B_nw;
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing