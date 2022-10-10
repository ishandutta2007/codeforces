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

cat mod = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int H, W;
		cin >> H >> W;
		vector<string> ans(H);
		for(int i = 0; i < W; i++) ans[0] += '0';
		for(int i = 1; i < H; i++) ans[i] = ans[0];
		ans[0][0] = ans[0][W-1] = ans[H-1][0] = ans[H-1][W-1] = '1';
		for(int i = 1; i < W-1; i++) if(ans[0][i-1] == '0' && ans[0][i+1] == '0') ans[0][i] = '1';
		for(int i = 1; i < W-1; i++) if(ans[H-1][i-1] == '0' && ans[H-1][i+1] == '0') ans[H-1][i] = '1';
		for(int i = 1; i < H-1; i++) if(ans[i-1][0] == '0' && ans[i+1][0] == '0') ans[i][0] = '1';
		for(int i = 1; i < H-1; i++) if(ans[i-1][W-1] == '0' && ans[i+1][W-1] == '0') ans[i][W-1] = '1';
		for(int i = 0; i < H; i++) cout << ans[i] << "\n";
	}
}

// look at my code
// my code is amazing