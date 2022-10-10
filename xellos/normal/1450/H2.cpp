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

cat MOD = 998244353;
vector<cat> fac;
vector<cat> fac_inv;

class Solver {
	int n, c;

	cat cur_val[4]; // sum_k>=0 C(n-i,c-j+2k)

public:
	Solver(int n_, int c_) : n{n_}, c{c_} {
		for(int k = 0; k < 4; k++) {
			n -= k/2;
			c -= k%2;
			cur_val[k] = 0;
			for(int i = 0; i <= (n-c)/2; i++) {
				if(c+2*i < 0) continue;
				if(n-c-2*i < 0) continue;
				cur_val[k] = (cur_val[k] + fac[n] % MOD * fac_inv[c+2*i] % MOD * fac_inv[n-c-2*i]) % MOD;
			}
			n += k/2;
			c += k%2;
		}
	}

	void inc_n() {
		cur_val[2] = cur_val[0];
		cur_val[3] = cur_val[1];
		cur_val[0] = cur_val[1] = (cur_val[0] + cur_val[1]) % MOD;
		if(c >= 2 && c-2 <= n)
			cur_val[1] = (cur_val[1] + fac[n] * fac_inv[c-2] % MOD * fac_inv[n-c+2]) % MOD;
		n++;
	}

	void dec_n() {
		cat s = cur_val[2] * (MOD/2+1) % MOD;
		cur_val[0] = cur_val[2];
		cur_val[1] = cur_val[3];
		if(n == 2) {
			cur_val[2] = cur_val[3] = 0;
			if(c <= 0 && c%2 == 0) cur_val[2] = 1;
			if(c <= 1 && (c-1)%2 == 0) cur_val[3] = 1;
		}
		else if(c >= 2 && c <= n-1) {
			cat d = fac[n-3] * fac_inv[c-2] % MOD * fac_inv[n-1-c] % MOD * (MOD/2+1) % MOD;
			cur_val[2] = s - d;
			if(cur_val[2] < 0) cur_val[2] += MOD;
			cur_val[3] = (s + d) % MOD;
		}
		else cur_val[2] = cur_val[3] = s;
		n--;
	}

	void inc_c() {
		for(int k = 0; k < 2; k++) {
			swap(cur_val[k*2+1], cur_val[k*2]);
			if(c >= 1 && c-1 <= n-k) {
				cur_val[k*2] = (cur_val[k*2] - fac[n-k] * fac_inv[c-1] % MOD * fac_inv[n-k-c+1]) % MOD;
				if(cur_val[k*2] < 0) cur_val[k*2] += MOD;
			}
		}
		c++;
	}

	void dec_c() {
		for(int k = 0; k < 2; k++) {
			swap(cur_val[k*2+1], cur_val[k*2]);
			if(c >= 2 && c-2 <= n-k)
				cur_val[k*2+1] = (cur_val[k*2+1] + fac[n-k] * fac_inv[c-2] % MOD * fac_inv[n-k-c+2]) % MOD;
		}
		c--;
	}

	cat get() {
		// sum_k>=0 k C(n,c+2k) = n/2 sum_k>=0 C(n-1,c-1+2k) - c/2 sum_k>=0 C(n,c+2k)
		cat ret = (n * cur_val[3] - c * cur_val[0]) % MOD;
		if(ret < 0) ret += MOD;
		ret = ret * (MOD/2+1) % MOD;
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
	fac.resize(N+1, 1);
	for(int i = 1; i <= N; i++) fac[i] = fac[i-1] * i % MOD;
	fac_inv.resize(N+1, 1);
	fac_inv[N] = pw(fac[N], MOD-2, MOD);
	for(int i = N-1; i > 0; i--) fac_inv[i] = fac_inv[i+1] * (i+1) % MOD;
	vector<cat> pw2i(N+1, 1);
	for(int i = 1; i <= N; i++) pw2i[i] = pw2i[i-1] * (MOD/2+1) % MOD;

	Solver solver[] = {Solver(nq[0]+nq[1], nq[1]-d), Solver(nq[0]+nq[1], nq[0]+d)};
	cout << (solver[0].get() + solver[1].get()) * pw2i[nq[0]+nq[1]-1] % MOD << "\n";
	for(int q = 0; q < Q; q++) {
		int id;
		string c_nw;
		cin >> id >> c_nw;
		id--;
		if(S[id] == '?') {
			nq[id&1]--;
			solver[0].dec_n();
			solver[1].dec_n();
			solver[1-(id&1)].dec_c();
		}
		if(S[id] == 'b') {
			d -= (id&1) ? -1 : 1;
			solver[1-(id&1)].dec_c();
			solver[id&1].inc_c();
		}
		S[id] = c_nw[0];
		if(S[id] == '?') {
			nq[id&1]++;
			solver[0].inc_n();
			solver[1].inc_n();
			solver[1-(id&1)].inc_c();
		}
		if(S[id] == 'b') {
			d += (id&1) ? -1 : 1;
			solver[1-(id&1)].inc_c();
			solver[id&1].dec_c();
		}
		cout << (solver[0].get() + solver[1].get()) * pw2i[nq[0]+nq[1]-1] % MOD << "\n";
	}
}

// look at my code
// my code is amazing