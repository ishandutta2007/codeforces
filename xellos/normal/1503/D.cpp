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

template <typename T>
class minfin {
	vector<T> node_val;
	T init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	minfin(int N, T init_val) {
		init_val_ = init_val;
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> R(N), A(N);
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if((a <= N) == (b <= N)) {
			cout << "-1\n";
			return 0;
		}
		if(a <= N) R[a-1] = 0, A[a-1] = 2*N-b;
		else R[b-1] = 1, A[b-1] = 2*N-a;
	}
	A.insert(begin(A), -1);
	R.insert(begin(R), 0);
	// 2 increasing subsequences
	minfin<cat> F[2] = {minfin<cat>(N, N+1), minfin<cat>(N, N+1)};
	F[0].put(0, R[1] == 1);
	F[1].put(0, R[1] == 0);
	cat C[2] = {0, 0};
	// dp[0][j]: (A[i-1], j)
	// dp[1][j]: (j, A[i-1])
	// (A[i-1], j) -> (A[i-1], A[i]) for j <= A[i], cost 1-R[i]
	// A[i] > A[i-1]: (A[i-1], j) -> (A[i], j), cost R[i]
	for(int i = 2; i <= N; i++) {
		cat mi0 = F[0].get(A[i]), mi1 = F[1].get(A[i]);
		mi0 += C[0];
		mi1 += C[1];
		if(A[i] > A[i-1]) {
			C[0] += R[i];
			C[1] += 1-R[i];
		}
		else {
			C[0] += N+1;
			C[1] += N+1;
		}
		F[1].put(A[i-1], mi0+1-R[i]-C[1]);
		F[0].put(A[i-1], mi1+R[i]-C[0]);
	}
	cat ans = min(F[0].get(N-1)+C[0], F[1].get(N-1)+C[1]);
	if(ans > N) ans = -1;
	cout << ans << "\n";
}

// look at my code
// my code is amazing