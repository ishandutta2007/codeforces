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
	string S;
	cin >> S;
	int L = S.length();
	cat MOD = 998244353;
	cat dp[64];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < L; i++) {
		cat dp_nw[64];
		memset(dp_nw, 0, sizeof(dp_nw));
		for(int k = 0; k < 64; k++) for(int j = 0; j < 8; j++) {
			int n = k;
			if(S[i] == '0') {
				if((7-(k&7)) & (j&7)) continue;
			}
			else n |= (7-j);
			if(j == 1 || j == 6) n |= 1<<3;
			else if(j == 2 || j == 5) n |= 1<<4;
			else if(j == 3 || j == 4) n |= 1<<5;
			dp_nw[n] += dp[k];
			if(dp_nw[n] >= MOD) dp_nw[n] -= MOD;
		}
		memcpy(dp, dp_nw, sizeof(dp_nw));
	}
	cat ans = 0;
	for(int k = 0; k < 64; k++) if((k>>3) == 7) {
		ans += dp[k];
		if(ans >= MOD) ans -= MOD;
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing