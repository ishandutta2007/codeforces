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
	fin() = default;

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
		vector<int> A(M), B(M), C(M);
		vector< vector< pair<int,int> > > G(N);
		vector< vector<int> > E_id(N, vector<int>(N, -1));
		for(int i = 0; i < M; i++) {
			cin >> A[i] >> B[i] >> C[i];
			G[--A[i]].push_back({--B[i], i});
			G[B[i]].push_back({A[i], i});
			E_id[A[i]][B[i]] = i;
			E_id[B[i]][A[i]] = i;
		}
		vector<char> used(M, 0);
		bool fail = false;
		for(int i = 0; i < N; i++) for(auto e : G[i]) if(e.ff < i)
			for(int j = i+1; j < N; j++) if(E_id[i][j] >= 0 && E_id[e.ff][j] >= 0) {
				if(C[e.ss] != -1 && C[E_id[i][j]] != -1 && C[E_id[e.ff][j]] != -1) {
					if((C[e.ss]+C[E_id[i][j]]+C[E_id[e.ff][j]])%3 != 0) fail = true;
					continue;
				}
				used[e.ss] = used[E_id[i][j]] = used[E_id[e.ff][j]] = 1;
			}
		if(fail) {
			cout << "-1\n";
			continue;
		}
		vector<int> var, id_var(M, -1);
		int V = 0;
		for(int i = 0; i < M; i++) if(used[i] && C[i] == -1) {
			var.push_back(i);
			id_var[i] = V++;
		}
		for(int i = 0; i < M; i++) if(!used[i] && C[i] == -1) C[i] = 1;
		vector< vector<int> > H;
		vector<int> O;
		for(int i = 0; i < N; i++) for(auto e : G[i]) if(e.ff < i)
			for(int j = i+1; j < N; j++) if(E_id[i][j] >= 0 && E_id[e.ff][j] >= 0) {
				if(C[e.ss] != -1 && C[E_id[i][j]] != -1 && C[E_id[e.ff][j]] != -1)
					continue;
				H.push_back(vector<int>(V, 0));
				O.push_back(0);
				if(C[e.ss] == -1) H.back()[id_var[e.ss]] = 1;
				else O.back() -= C[e.ss];
				if(C[E_id[i][j]] == -1) H.back()[id_var[E_id[i][j]]] = 1;
				else O.back() -= C[E_id[i][j]];
				if(C[E_id[e.ff][j]] == -1) H.back()[id_var[E_id[e.ff][j]]] = 1;
				else O.back() -= C[E_id[e.ff][j]];
				O.back() %= 3;
			}
		int Q = H.size();
		// H * ans = O
		int s = 0;
		vector<int> P(V, -1);
		for(int i = 0; i < V; i++) {
			int p = -1;
			for(int j = s; j < Q; j++) if(H[j][i]%3) {
				p = j;
				break;
			}
			if(p == -1) continue;
			P[i] = s;
			swap(H[s], H[p]);
			swap(O[s], O[p]);
			if((H[s][i]+1)%3 == 0) {
				for(int j = 0; j < V; j++) H[s][j] = (H[s][j]*2)%3;
				O[s] = (O[s]*2)%3;
			}
			for(int j = 0; j < Q; j++) if(j != s && H[j][i]%3) {
				int x = -H[j][i]*H[s][i]%3;
				for(int k = 0; k < V; k++) H[j][k] = (H[j][k]+H[s][k]*x)%3;
				O[j] = (O[j]+O[s]*x)%3;
			}
			s++;
		}
		vector<int> ans(V, 0);
		for(int i = V-1; i >= 0; i--) if(P[i] != -1) {
			int v = O[P[i]];
			for(int j = i+1; j < V; j++) if(H[P[i]][j]%3) v = (v-H[P[i]][j]*ans[j])%3;
			ans[i] = v;
		}
		for(int i = 0; i < Q; i++) {
			int v = O[i];
			for(int j = 0; j < V; j++) v -= H[i][j]*ans[j];
			if(v%3) fail = true;
		}
		if(fail) {
			cout << "-1\n";
			continue;
		}
		for(int i = 0; i < V; i++) {
			C[var[i]] = ans[i]%3;
			if(C[var[i]] <= 0) C[var[i]] += 3;
		}
		for(int i = 0; i < M; i++) cout << C[i] << ((i == M-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing