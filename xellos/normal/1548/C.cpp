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
	int N;
	cin >> N;
	cat mod = 1000000007;
	vector<cat> fac(3*N+5, 1);
	for(int i = 1; i <= 3*N+3; i++) fac[i] = fac[i-1] * i % mod;
	vector<cat> inv(3*N+5, 1);
	inv[2] = pw(2, mod-2, mod);
	inv[3] = pw(3, mod-2, mod);
	inv[4] = pw(4, mod-2, mod);
	inv[5] = pw(5, mod-2, mod);
	for(int i = 6; i <= 3*N+3; i++) {
		if(i%2 == 0) inv[i] = inv[i/2] * inv[2] % mod;
		else if(i%3 == 0) inv[i] = inv[i/3] * inv[3] % mod;
		else if(i%5 == 0) inv[i] = inv[i/5] * inv[5] % mod;
		else inv[i] = pw(i, mod-2, mod);
	}
	vector<cat> fac_inv(3*N+5, 1);
	for(int i = 1; i <= 3*N+3; i++) fac_inv[i] = fac_inv[i-1] * inv[i] % mod;
	vector<cat> ans(3*N+5, 0);
	for(int i = 3*N; i >= 0; i--) {
		ans[i] = (fac_inv[3*N-i] * fac_inv[i+3] - 3 * (ans[i+1] + ans[i+2])) % mod;
		if(ans[i] < 0) ans[i] += mod;
	}
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		int x;
		cin >> x;
		cout << fac[3*(N+1)] * ans[x] % mod << "\n";
	}
}

// look at my code
// my code is amazing