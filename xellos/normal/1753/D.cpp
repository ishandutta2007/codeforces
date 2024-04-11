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

constexpr cat MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cat P, Q;
	cin >> N >> M >> P >> Q;
	vector< vector<int> > id(N, vector<int>(M));
	int V[2] = {0, 0};
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		id[i][j] = V[(i+j)%2];
		V[(i+j)%2]++;
	}
	vector<string> S(N);
	for(int i = 0; i < N; i++) cin >> S[i];
	vector< vector<int> > G(N*M), H(N*M);
	vector<int> match(N*M, -1);
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	string dir = "LRUD";
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) for(int k = 0; k < 4; k++) {
		if(S[i][j] == '#') continue;
		if(i+dx[k] < 0 || j+dy[k] < 0 || i+dx[k] >= N || j+dy[k] >= M) continue;
		if(S[i+dx[k]][j+dy[k]] == '#') continue;
		G[((i+j)%2)*V[0]+id[i][j]].push_back(((i+j+dx[k]+dy[k])%2)*V[0]+id[i+dx[k]][j+dy[k]]);
		H[((i+j)%2)*V[0]+id[i][j]].push_back(k/2);
		if(dir[k] == S[i][j]) match[((i+j)%2)*V[0]+id[i][j]] = ((i+j+dx[k]+dy[k])%2)*V[0]+id[i+dx[k]][j+dy[k]];
	}
	priority_queue< pair<cat, pair<int,int> > > q;
	vector< vector<cat> > cost(V[0]);
	for(int i = 0; i < V[0]; i++) {
		cost[i].resize(2*G[i].size(), OVER9000);
		for(int j = 0; j < (int)G[i].size(); j++) if(match[G[i][j]] == -1) {
			cost[i][2*j] = 0;
			cost[i][2*j+1] = 0;
			q.push({0LL, {i, 2*j}});
			q.push({0LL, {i, 2*j+1}});
		}
	}
	while(!q.empty()) {
		auto p = q.top();
		q.pop();
		p.ff *= -1;
		if(cost[p.ss.ff][p.ss.ss] != p.ff) continue;
		if(match[p.ss.ff] == -1) continue;
		int m = match[p.ss.ff];
		int h[3];
		for(int j = 0; j < 4; j++) if(G[p.ss.ff][j] == m) {
			h[0] = H[p.ss.ff][j];
			break;
		}
		h[1] = H[p.ss.ff][p.ss.ss/2];
		for(int j = 0; j < 4; j++) if(G[m][j] == p.ss.ff) {
			h[2] = H[m][j];
			break;
		}
		for(int i = 0; i < (int)G[m].size(); i++) {
			int u = G[m][i];
			if(u == p.ss.ff) continue;
			for(int j = 0; j < 4; j++) if(G[u][j] == m) {
				cat cost_nw = p.ff;
				if(p.ss.ss%2 == 0) cost_nw += ((h[0] == h[1]) ? Q : P);
				if(p.ss.ss%2 == 0 && cost_nw < cost[u][2*j]) {
					cost[u][2*j] = cost_nw;
					q.push({-cost_nw, {u, 2*j}});
				}
				if(p.ss.ss%2 != 0) cost_nw += ((h[2] == H[m][i]) ? Q : P);
				if(cost_nw < cost[u][2*j+1]) {
					cost[u][2*j+1] = cost_nw;
					q.push({-cost_nw, {u, 2*j+1}});
				}
				break;
			}
		}
	}
	cat ans = OVER9000;
	for(int i = 0; i < V[0]; i++) if(match[i] == -1)
		for(int j = 0; j < 2*(int)G[i].size(); j++) ans = min(ans, cost[i][j]);
	cout << ((ans == OVER9000) ? -1 : ans) << "\n";
}

// look at my code
// my code is amazing