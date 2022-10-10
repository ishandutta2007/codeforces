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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	constexpr cat mod = 998244353;
	constexpr cat inv2 = (mod+1)/2;
	constexpr cat inv3 = (mod+1)/3;
	vector<int> cnt_arb(N+1, 0);
	cnt_arb[0] = 1;
	for(int i = 1, s = 0; i <= N; i++) {
		cnt_arb[i] = (1 + s + (cnt_arb[i-1] + 1) * inv2) % mod * cnt_arb[i-1] % mod;
		s += cnt_arb[i-1];
		if(s >= mod) s -= mod;
	}
	cat ans = (2 * cnt_arb[N] - cnt_arb[N-1]) % mod;
	ans = (ans + inv3 * cnt_arb[N-1] % mod * (cnt_arb[N-1]+1) % mod * (cnt_arb[N-1]+2)) % mod;
	cat s = 0;
	for(int i = 0; i < N-1; i++) s += cnt_arb[i];
	s %= mod;
	ans = (ans + s * (s+1) % mod * cnt_arb[N-1] + s * cnt_arb[N-1] % mod * (cnt_arb[N-1]+1)) % mod;
	for(int i = 1; i < N; i++) ans = (ans + 1LL * cnt_arb[N-1-i] * (cnt_arb[i] - cnt_arb[i-1])) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing