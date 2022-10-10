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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int L, R;
	cin >> L >> R;
	vector< pair<int, pair<int, int> > > E;
	for(int i = 0; i < 20; i++) {
		E.push_back({L, {0, i+1}});
		for(int j = i+1; j < 20; j++) E.push_back({1<<i, {i+1, j+1}});
	}
	E.push_back({L, {0, 21}});
	for(int i = 19; i >= 0; i--) if(R-L >= (1<<i)) {
		E.push_back({R-L+1-(1<<i), {i+1, 21}});
		R -= (1<<i);
	}
	cout << "YES\n22 " << E.size() << "\n";
	for(auto p : E) cout << p.ss.ff+1 << " " << p.ss.ss+1 << " " << p.ff << "\n";
}

// look at my code
// my code is amazing