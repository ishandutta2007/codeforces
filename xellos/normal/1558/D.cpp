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
	constexpr cat mod = 998244353, MX = 400010;
	vector<cat> fac(MX+1, 1);
	for(int i = 1; i <= MX; i++) fac[i] = fac[i-1] * i % mod;
	vector<cat> fac_inv(MX+1, 1);
	fac_inv[MX] = pw(fac[MX], mod-2, mod);
	for(int i = MX-1; i >= 1; i--) fac_inv[i] = fac_inv[i+1] * (i+1) % mod;
	int T;
	cin >> T;
	fin F(MX, 0);
	for(int i = 0; i < MX; i++) F.put(i, 1);
	vector<char> used(MX, 0);
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<int> X(M), Y(M);
		for(int i = 0; i < M; i++) {
			cin >> X[i] >> Y[i];
			X[i]--, Y[i]--;
		}
		int sep = M;
		vector<int> val(M);
		for(int i = M-1; i >= 0; i--) {
			int s = N-M+i-Y[i];
			int val_lt = -1, val_ge = N-1;
			while(val_ge-val_lt > 1) {
				int val_mid = (val_lt + val_ge) / 2;
				if(F.get(val_mid) >= s) val_ge = val_mid;
				else val_lt = val_mid;
			}
			val[i] = N-1-val_ge;
			sep -= used[val[i]+1];
			used[val[i]] = 1;
			F.put(N-1-val[i], -1);
		}
		// C(2*N-1-sep, N-1-sep)
		cout << fac[2*N-1-sep] * fac_inv[N-1-sep] % mod * fac_inv[N] % mod << "\n";
		for(int i = 0; i < M; i++) {
			used[val[i]] = 0;
			F.put(N-1-val[i], 1);
		}
	}
}

// look at my code
// my code is amazing