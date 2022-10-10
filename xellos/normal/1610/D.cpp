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

bool is_pali(vector<int> & V) {
	int N = V.size();
	for(int i = 0; i < N; i++) if(V[i] != V[N-1-i]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int n_odd = 0;
	for(int i = 0; i < N; i++) if(A[i]%2 != 0) n_odd++;
	cat MOD = 1000000007, ans = 0;
	for(int k = 1; k < 30; k++) {
		int n_eq = 0, n_gt = 0, m = (1<<k);
		for(int i = 0; i < N; i++) if(A[i]%m == 0) {
			if(A[i]%(2*m) != 0) n_eq++;
			else n_gt++;
		}
		if(n_eq == 0) continue;
		ans = (ans + (pw(2, n_eq-1, MOD) - 1) * pw(2, n_gt, MOD)) % MOD;
	}
	if(n_odd)
		ans = (ans + (pw(2, n_odd, MOD) - 1) * pw(2, N-n_odd, MOD)) % MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing