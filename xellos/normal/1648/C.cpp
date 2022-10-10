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
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i] += val;
		}
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret += node_val[i];
		}
		return ret;
	}
};

cat MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,M;
	constexpr int MX = 200000;
	cin >> M >> N;
	vector<int> A(N), B(MX+1, 0);
	for(int i = 0; i < M; i++) {
		int b;
		cin >> b;
		B[b]++;
	}
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<cat> fac(MX+1,1), fac_inv(MX+1,1);
	for(int i = 1; i <= MX; i++) fac[i] = fac[i-1] * i % MOD;
	fac_inv[MX] = pw(fac[MX], MOD-2, MOD);
	for(int i = MX; i >= 1; i--) fac_inv[i-1] = fac_inv[i] * i % MOD;
	cat ans = 0;
	fin<cat> F(MX+1, 0LL);
	for(int i = 1; i <= MX; i++) F.put(i, B[i]);
	cat c = 1;
	for(int i = 1; i <= MX; i++) c = c * fac_inv[B[i]] % MOD;
	for(int i = 0; i <= min(N,M); i++) {
		if(i == min(N,M)) {
			if(N > i) ans = (ans+1)%MOD;
			break;
		}
		cat s = F.get(A[i]-1);
		ans = (ans + s % MOD * fac[M-i-1] % MOD * c) % MOD;
		if(B[A[i]] == 0) break;
		F.put(A[i], -1);
		c = c * B[A[i]] % MOD;
		B[A[i]]--;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing