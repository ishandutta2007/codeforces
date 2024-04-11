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
#define soclose 1e-11
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

struct state {
	int key;
	cat sum, cnt;

	bool operator<(const state & st) const {
		return key < st.key;
	}
};

constexpr cat MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		vector<state> dp;
		cat ans = 0;
		for(int i = N-1; i >= 0; i--) {
			static vector<state> dp_nw;
			dp_nw.clear();
			dp_nw.push_back({.key = A[i], .sum = 0, .cnt = 1});
			for(auto st : dp) {
				int parts = (A[i]+st.key-1)/st.key;
				int key_nw = A[i]/parts;
				dp_nw.push_back({.key = key_nw, .sum = (st.sum + st.cnt * (parts-1)) % MOD, .cnt = st.cnt});
			}
			sort(begin(dp_nw), end(dp_nw));
			dp.clear();
			for(int j = 0; j < (int)dp_nw.size(); j++) {
				if(j == 0 || dp_nw[j-1].key != dp_nw[j].key) dp.push_back(dp_nw[j]);
				else {
					dp.back().cnt += dp_nw[j].cnt;
					if(dp.back().cnt >= MOD) dp.back().cnt -= MOD;
					dp.back().sum += dp_nw[j].sum;
					if(dp.back().sum >= MOD) dp.back().sum -= MOD;
				}
			}
			for(auto st : dp) {
				ans += st.sum;
				if(ans >= MOD) ans -= MOD;
			}
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing