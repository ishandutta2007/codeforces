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
	int T;
	cin >> T;
	while(T--) {
		int N,K;
		cin >> N >> K;
		vector<int> V(N);
		for(int i = 0; i < N; i++) cin >> V[i];
		// V[i] > 0: W[i+K] = V[i]+K <= i+K
		bool ok = true;
		for(int i = N-1; i >= N-K; i--) {
			if(V[i] > 0) ok = false;
			if(V[i] == -1) V[i] = 0;
		}
		if(!ok) {
			cout << "0\n";
			continue;
		}
		// 0 <= W[i<K] <= i: K!
		// 0 <= W[i>=K] <= K
		// ans += K! * (K+1)**(N-K-#(V[i]>0)) = K! * cnt
		int n0 = 0;
		for(int i = 0; i < N; i++) if(V[i] > 0) n0++;
		cat ans = pw(K+1, N-K-n0, MOD), inv = pw(K+1, MOD-2, MOD);
		for(int i = 0; i < N; i++) if(V[i] == -1) {
			// 1. V[i] = 0: 1 option
			// 2. 0 < V[i] <= i: i options, cnt /= K+1
			ans = ans * (1 + inv * i % MOD) % MOD;
		}
		for(int i = 1; i <= K; i++) ans = ans * i % MOD;
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing