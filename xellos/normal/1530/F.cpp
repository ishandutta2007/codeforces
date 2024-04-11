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
using cat = int;
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

cat mod = 31607;

cat solve(vector< vector<cat> > A) {
	int N = A.size();
	cat ret = 0;
	vector<cat> P_row(N, 1);
	for(int j = 0; j < N; j++)
		for(int k = 0; k < N; k++) P_row[j] = P_row[j] * A[j][k] % mod;
	for(int i = 0; i < (1<<N); i++) {
		cat pr = 1;
		static cat P[21];
		for(int j = 0; j < N; j++) P[j] = 1;
		for(int j = 0; j < N; j++) {
			if((i>>j)&1) pr = pr * P_row[j] % mod;
			else
				for(int k = 0; k < N; k++) P[k] = P[k] * A[j][k] % mod;
		}
		if(__builtin_popcount(i)%2 == 0) pr = -pr;
		cat sc = 1;
		for(int j = 0; j < N; j++) sc = sc * (1-P[j]) % mod;
		if(i == 0) sc -= 1;
		ret = (ret + pr * sc) % mod;
	}
	ret %= mod;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	cat invd = pw(10000, mod-2, mod);
	vector< vector<cat> > A(N, vector<cat>(N));
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		cin >> A[i][j];
		A[i][j] = A[i][j] * invd % mod;
	}
	cat ans = 0;
	for(int k = 0; k < 4; k++) {
		cat p_init = 1;
		auto B = A;
		if(k&1) for(int i = 0; i < N; i++) {
			p_init = p_init * B[i][i] % mod;
			B[i][i] = 1;
		}
		if(k>>1) for(int i = 0; i < N; i++) {
			p_init = p_init * B[i][N-1-i] % mod;
			B[i][N-1-i] = 1;
		}
		cat p_rs = solve(B);
		if(k == 0) ans += p_rs;
		if(k == 1 || k == 2) ans += p_init * (1 - p_rs) % mod;
		if(k == 3) ans += p_init * (p_rs - 1) % mod;
	}
	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
}

// look at my code
// my code is amazing