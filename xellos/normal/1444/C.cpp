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
#define OVER9000 1234567890123LL
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

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> C(N);
	vector< vector<int> > S(K);
	for(int i = 0; i < N; i++) {
		cin >> C[i];
		S[--C[i]].push_back(i);
	}
	vector< vector<int> > G_in(N);
	vector< vector< pair<int, int> > > G(K);
	vector< pair<int, int> > E;
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if(C[u] == C[v]) {
			G_in[u].push_back(v);
			G_in[v].push_back(u);
		}
		else {
			if(C[u] > C[v]) G[C[u]].push_back({C[v], E.size()});
			else G[C[v]].push_back({C[u], E.size()});
			E.push_back({u, v});
		}
	}
	vector<char> bad(K, 0);
	vector<int> comp(N, -1);
	for(int i = 0, l = 0; i < N; i++) if(comp[i] == -1) {
		static queue<int> q;
		q.push(i);
		comp[i] = 2*l;
		l++;
		while(!q.empty()) {
			for(auto v : G_in[q.front()]) {
				if(comp[v] == -1) {
					comp[v] = comp[q.front()]^1;
					q.push(v);
				}
				else if(comp[v] == comp[q.front()]) bad[C[i]] = 1;
			}
			q.pop();
		}
	}
	int K_good = K;
	for(int i = 0; i < K; i++) K_good -= bad[i];
	cat ans = 1LL * K_good * (K_good-1) / 2;
	vector< vector<int> > E_cur(K);
	vector< vector<int> > G_cur(2*N);
	for(int i = 0; i < K; i++) if(!bad[i]) {
		for(auto p : G[i]) if(!bad[p.ff]) E_cur[p.ff].push_back(p.ss);
		for(auto p : G[i]) if(!E_cur[p.ff].empty()) {
			// test (p.ff, i)
			static vector<char> lbl(2*N, 2);
			vector<int> V;
			for(auto e : E_cur[p.ff]) {
				G_cur[comp[E[e].ff]].push_back(comp[E[e].ss]);
				G_cur[comp[E[e].ss]].push_back(comp[E[e].ff]);
				V.push_back(comp[E[e].ff]);
				V.push_back(comp[E[e].ss]);
			}
			bool ok = true;
			for(auto v : V) if(lbl[v] == 2) {
				static queue<int> q;
				lbl[v] = 0;
				lbl[v^1] = 1;
				q.push(v);
				q.push(v^1);
				while(!q.empty()) {
					for(auto u : G_cur[q.front()]) {
						if(lbl[u] == 2) {
							lbl[u] = lbl[q.front()]^1;
							lbl[u^1] = lbl[q.front()];
							q.push(u);
							q.push(u^1);
						}
						else if(lbl[u] == lbl[q.front()]) ok = false;
					}
					q.pop();
				}
				if(!ok) break;
			}
			if(!ok) ans--;
			for(auto v : V) {
				G_cur[v].clear();
				lbl[v] = lbl[v^1] = 2;
			}
			E_cur[p.ff].clear();
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing