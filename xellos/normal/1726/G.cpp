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

cat solve(auto A0, auto A1, int M) {
	int N0 = A0.size(), N1 = A1.size(); // N1 > 0
	for(int i = 1; i < N1; i++) if(A1[i] < M && A1[i-1] == A1[i]) return 0;
	cat ret = 1;
	int i0 = 0, i1 = 0;
	int last = -1, n_eq = 0;
	while(true) {
		if(i0 < N0 && (i1 == N1 || A1[i1] >= A0[i0])) {
			if(A0[i0] == last) n_eq++;
			else n_eq = 1;
			last = A0[i0];
			if(M-A0[i0] > i0+i1-(n_eq-1)) return 0;
			ret = ret * n_eq % MOD;
			i0++;
		}
		else if(i1 < N1 && (i0 == N0 || A0[i0] > A1[i1])) {
			if(A1[i1] == M) {
				ret = ret * (i0+i1+1) % MOD;
				i1++;
			}
			else {
				if(M-A1[i1]-(N1+N0-1) > 0 || M-A1[i1]-(N1+N0-1)+i0+i1 < 0) return 0;
				n_eq = 1;
				last = A1[i1];
				i1++;
			}
		}
		else break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) cin >> B[i];
	vector<int> A0, A1;
	for(int i = 0; i < N; i++) {
		if(B[i] == 0) A0.push_back(A[i]);
		else A1.push_back(A[i]);
	}
	sort(begin(A0), end(A0));
	sort(begin(A1), end(A1));
	if(A1.empty()) {
		cat f = 1;
		for(int i = 1; i <= N; i++) f = f * i % MOD;
		cout << ((A0[0] == A0[N-1]) ? f : 0) << "\n";
		return 0;
	}
	int M = A1.back();
	if(!A0.empty()) M = max(M, A0.back());
	cat ans = solve(A0, A1, M);
	if(A1[0]+N-1 > M)
		ans = (ans + solve(A0, A1, A1[0]+N-1)) % MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing