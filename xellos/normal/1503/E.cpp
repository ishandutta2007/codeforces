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
	int N, M;
	cin >> N >> M;
	cat ans = 0, mod = 998244353;
	vector< vector<cat> > n_incr_seq(N+1, vector<cat>(M, 0));
	n_incr_seq[0][0] = 1;
	for(int i = 0; i < N; i++) {
		cat s = 0;
		for(int j = 0; j < M; j++) {
			s += n_incr_seq[i][j];
			if(s >= mod) s -= mod;
			n_incr_seq[i+1][j] = s;
		}
	}
	vector< vector<cat> > s_incr_seq(N+1, vector<cat>(M, 0));
	for(int i = 1; i <= N; i++) {
		s_incr_seq[i] = n_incr_seq[i];
		for(int j = 1; j < M; j++) {
			s_incr_seq[i][j] += s_incr_seq[i][j-1];
			if(s_incr_seq[i][j] >= mod) s_incr_seq[i][j] -= mod;
		}
	}
	cat m2 = mod * mod * 4;
	for(int i = 1; i < M; i++) {
		vector<cat> v1(N, 0), v2(N, 0);
		v1[0] = 1;
		for(int j = 1; j < N; j++) {
			v1[j] = v1[j-1] + s_incr_seq[j][i-1];
			if(v1[j] >= mod) v1[j] -= mod;
		}
		for(int j = 0; j < N; j++) v1[j] = v1[j] * s_incr_seq[N-1-j][i-1] % mod;
		v2[N-1] = 1;
		for(int j = N-2; j >= 0; j--) {
			v2[j] = v2[j+1] + s_incr_seq[N-1-j][M-i-1];
			if(v2[j] >= mod) v2[j] -= mod;
		}
		for(int j = 0; j < N; j++) v2[j] = v2[j] * s_incr_seq[j][M-i-1] % mod;
		cat s = 0;
		for(int j = 0; j < N; j++) {
			ans += v2[j] * s;
			if(ans >= m2) ans -= m2;
			s += v1[j];
			if(s >= mod) s -= mod;
		}
	}
	for(int i = 0; i < N-1; i++) {
		vector<cat> v1(M), v2(M);
		for(int j = 0; j < M; j++) v1[j] = s_incr_seq[i+1][M-1-j] * n_incr_seq[i+1][j] % mod;
		for(int j = 0; j < M; j++) v2[j] = s_incr_seq[N-i-1][j] * n_incr_seq[N-i-1][M-1-j] % mod;
		cat s = 0;
		for(int l = 1; l < M; l++) {
			ans += s * v1[l];
			if(ans >= m2) ans -= m2;
			s += v2[l-1];
			if(s >= mod) s -= mod;
		}
	}
	ans %= mod;
	cout << 2 * ans % mod << "\n";
}

// look at my code
// my code is amazing