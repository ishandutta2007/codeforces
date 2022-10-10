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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, Q;
	string S;
	cin >> N >> Q >> S;
	int nq[2] = {0,0};
	int d = 0;
	for(int i = 0; i < N; i++) {
		if(S[i] == '?') nq[i&1]++;
		if(S[i] == 'b') d += (i&1) ? -1 : 1;
	}
	cat MOD = 998244353;
	vector<cat> fac(N+1, 1);
	for(int i = 1; i <= N; i++) fac[i] = fac[i-1] * i % MOD;
	vector<cat> fac_inv(N+1, 1);
	fac_inv[N] = pw(fac[N], MOD-2, MOD);
	for(int i = N-1; i > 0; i--) fac_inv[i] = fac_inv[i+1] * (i+1) % MOD;
	cat ans = 0;
	for(int k = 0; k < 2; k++) {
		for(int i = 1; i <= (nq[0]+d)/2; i++) {
			if(nq[1]-d+2*i < 0) continue;
			if(2*i > nq[0]+d) continue;
			ans = (ans + i * fac[nq[0]+nq[1]] % MOD * fac_inv[nq[1]-d+2*i] % MOD * fac_inv[nq[0]+nq[1]-(nq[1]-d+2*i)]) % MOD;
		}
		d *= -1;
		swap(nq[0], nq[1]);
	}
	ans = ans * pw(2, MOD-1-(nq[0]+nq[1]-1), MOD) % MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing