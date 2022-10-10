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
using dbl = double;
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
	vector<string> S(N);
	int n[3] = {0,0,0};
	for(int i = 0; i < N; i++) {
		cin >> S[i];
		for(int k = 0; k < 2; k++) {
			if(S[i][k] == 'W') n[0]++;
			else if(S[i][k] == 'B') n[1]++;
			else n[2]++;
		}
	}
	cat MOD = 998244353;
	vector<cat> fac(2*N+1, 1);
	for(int i = 1; i <= 2*N; i++) fac[i] = fac[i-1] * i % MOD;
	vector<cat> fac_inv(2*N+1, 1);
	fac_inv[2*N] = pw(fac[2*N], MOD-2, MOD);
	for(int i = 2*N-1; i >= 0; i--) fac_inv[i] = fac_inv[i+1] * (i+1) % MOD;
	cat ans = 0;
	for(int i = 0; i <= n[2]; i++) if(abs(n[0]+i-n[1]-(n[2]-i)) <= 0)
		ans = (ans + fac[n[2]] * fac_inv[i] % MOD * fac_inv[n[2]-i]) % MOD;
	bool ok = false;
	n[0] = n[1] = n[2] = 0;
	for(int i = 0; i < N; i++) {
		if(S[i] == "WW" || S[i] == "BB") {
			ok = true;
			break;
		}
		if(S[i] == "W?" || S[i] == "?B") S[i] = "WB";
		if(S[i] == "B?" || S[i] == "?W") S[i] = "BW";
		if(S[i] == "WB") n[0]++;
		if(S[i] == "BW") n[1]++;
		if(S[i] == "??") n[2]++;
	}
	if(!ok) for(int i = 0; i <= n[2]; i++) if(n[0]+i > 0 && n[1]+n[2]-i > 0)
		ans = (ans - fac[n[2]] * fac_inv[i] % MOD * fac_inv[n[2]-i]) % MOD;
	if(ans < 0) ans += MOD;
	cout << ans << "\n";
}

// look at my code
// my code is amazing