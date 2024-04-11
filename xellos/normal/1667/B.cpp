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

template <typename T>
class maxfin {
	T init_val;
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	maxfin(int N, T init_val_) : init_val{init_val_} {
		node_val.resize(N+10, init_val_);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = max(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = max(ret, node_val[i]);
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
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<cat> S(N+1, 0);
		for(int i = 0; i < N; i++) S[i+1] = S[i]+A[i];
		map<cat,int> M;
		for(int i = 0; i <= N; i++) M[S[i]] = 0;
		int m = 0;
		for(auto & p : M) p.ss = m++;
		for(int i = 0; i <= N; i++) S[i] = M[S[i]];
		vector<int> dp(N+1);
		dp[0] = 0;
		maxfin<int> F_p(N+1, -3*N), F_n(N+1, -3*N);
		vector<int> V_z(N+1, -3*N);
		F_p.put(S[0], 0);
		F_n.put(N-S[0], 0);
		V_z[S[0]] = 0;
		for(int i = 1; i <= N; i++) {
			int dp_p = F_p.get(S[i]-1);
			// for(int j = 0; j < i; j++) if(S[j] < S[i]) dp_p = max(dp_p, dp[j]-j);
			int dp_z = V_z[S[i]];
			// for(int j = 0; j < i; j++) if(S[j] == S[i]) dp_z = max(dp_z, dp[j]);
			int dp_n = F_n.get(N-S[i]-1);
			// for(int j = 0; j < i; j++) if(S[j] > S[i]) dp_n = max(dp_n, dp[j]+j);
			dp_p += i, dp_n -= i;
			dp[i] = max(dp_z, max(dp_p, dp_n));
			F_p.put(S[i], dp[i]-i);
			V_z[S[i]] = max(V_z[S[i]], dp[i]);
			F_n.put(N-S[i], dp[i]+i);
		}
		cout << dp[N] << "\n";
	}
}

// look at my code
// my code is amazing