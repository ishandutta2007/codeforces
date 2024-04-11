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
#define OVER9000 1234567890
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

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	int sB = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
		sB += B[i];
	}
	vector< vector<int> > dp(N+1, vector<int>(100*N+1, -1000000));
	dp[0][0] = 0;
	for(int i = 0; i < N; i++)
		for(int k = N-1; k >= 0; k--)
			for(int j = 100*i; j >= 0; j--)
				dp[k+1][j+B[i]] = max(dp[k+1][j+B[i]], dp[k][j]+A[i]);
	for(int k = 1; k <= N; k++) {
		int ans = 0;
		for(int i = 0; i <= 100*N; i++) ans = max(ans, min(2*dp[k][i], i+sB));
		cout << ans/2;
		if(ans%2) cout << ".5";
		cout << ((k == N) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing