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
	int N,M,K;
	cat P;
	cin >> N >> M >> K >> P;
	vector< vector<cat> > dp(N+1, vector<cat>(K+1, 0));
	dp[0][0] = dp[1][1] = 1;
	for(int i = 2; i <= N; i++) dp[i][1] = dp[i-1][1] * i % P;
	vector< vector<cat> > C(N+1, vector<cat>(N+1, 0));
	for(int i = 0; i <= N; i++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % P;
	}
	for(int m = 2; m <= M; m++) {
		vector< vector<cat> > dp_nw(N+1, vector<cat>(K+1, 0));
		dp_nw[0][0] = 1;
		for(int nl = 0; nl <= N-1; nl++) for(int nr = 0; nr <= N-1-nl; nr++)
			for(int kl = 0; kl <= nl; kl++) if(dp[nl][kl]) {
				cat c = C[nl+nr][nl] * dp[nl][kl] % P;
				for(int kr = 0; kr <= min(K-kl,nr); kr++)
					dp_nw[nl+nr+1][kl+kr] = (dp_nw[nl+nr+1][kl+kr] + c * dp[nr][kr]) % P;
			}
		dp = dp_nw;
	}
	cout << dp[N][K] << "\n";
}

// look at my code
// my code is amazing