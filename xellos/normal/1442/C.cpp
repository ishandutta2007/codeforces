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

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

struct dist {
	cat n_e, n_t;

	bool operator<(const dist & D) const {
		if(this->n_t == D.n_t) return this->n_e < D.n_e;
		if(this->n_t < 40 && D.n_t < 40) return this->n_e+(1LL<<(this->n_t)) < D.n_e+(1LL<<(D.n_t));
		return this->n_t < D.n_t;
	}

	bool operator!=(const dist & D) const {
		if(this->n_t == D.n_t) return this->n_e != D.n_e;
		if(this->n_t < 40 && D.n_t < 40) return this->n_e+(1LL<<(this->n_t)) != D.n_e+(1LL<<(D.n_t));
		return this->n_t != D.n_t;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N), Gi(N);
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		Gi[v].push_back(u);
	}
	vector< vector<dist> > D(N, vector<dist>(42, {N+1000, N+1000}));
	D[0][0] = {0, 0};
	priority_queue< pair<dist, int>, vector< pair<dist, int> >, greater< pair<dist, int> > > q;
	q.push({D[0][0], 0});
	while(!q.empty()) {
		dist d = q.top().ff;
		int v = q.top().ss;
		q.pop();
		int j_cur = (d.n_t < 40) ? d.n_t : (40+d.n_t%2);
		if(D[v][j_cur] != d) continue;
		int j_nxt = (d.n_t+1 < 40) ? d.n_t+1 : (40+(d.n_t+1)%2);
		dist d_nxt = dist{d.n_e, d.n_t+1};
		if(d_nxt < D[v][j_nxt]) {
			D[v][j_nxt] = d_nxt;
			q.push({D[v][j_nxt], v});
		}
		if(d.n_t%2 == 0) {
			d_nxt = dist{d.n_e+1, d.n_t};
			for(auto u : G[v]) if(d_nxt < D[u][j_cur]) {
				D[u][j_cur] = d_nxt;
				q.push({D[u][j_cur], u});
			}
		}
		else {
			d_nxt = dist{d.n_e+1, d.n_t};
			for(auto u : Gi[v]) if(d_nxt < D[u][j_cur]) {
				D[u][j_cur] = d_nxt;
				q.push({D[u][j_cur], u});
			}
		}
	}
	dist ans_dist = D[N-1][0];
	for(int i = 0; i < 42; i++) if(D[N-1][i] < ans_dist) ans_dist = D[N-1][i];
	cat ans = 1, mod = 998244353;
	for(int i = 0; i < ans_dist.n_t; i++) ans = ans * 2 % mod;
	ans = (ans + ans_dist.n_e + mod-1) % mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing