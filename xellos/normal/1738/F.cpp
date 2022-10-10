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
		vector<int> D(N);
		vector< pair<int, int> > Ds(N);
		for(int i = 0; i < N; i++) {
			cin >> D[i];
			Ds[i] = {D[i], i};
		}
		sort(Ds.begin(), Ds.end());
		vector<int> in_comp(N, -1);
		int n_comp = 0;
		for(int i = N-1; i >= 0; i--) {
			int r = Ds[i].ss;
			if(in_comp[r] != -1) continue;
			vector<int> cur_comp;
			in_comp[r] = n_comp;
			cur_comp.push_back(r);
			for(int j = 0; j < D[r]; j++) {
				cout << "? " << r+1 << endl;
				int u;
				cin >> u;
				u--;
				if(in_comp[u] == -1) {
					in_comp[u] = n_comp;
					cur_comp.push_back(u);
				}
				else {
					for(auto v : cur_comp) in_comp[v] = in_comp[u];
					cur_comp.clear();
					break;
				}
			}
			if(!cur_comp.empty()) n_comp++;
		}
		cout << "!";
		for(int i = 0; i < N; i++) cout << " " << in_comp[i]+1;
		cout << endl;
	}
}

// look at my code
// my code is amazing