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
	int T;
	cin >> T;
	while(T--) {
		cat N, K;
		cin >> N >> K;
		cat cnt = 1;
		for(int i = 0; i < N-1; i++) if(cnt < K) cnt *= 2;
		if(cnt < K) {
			cout << "-1\n";
			continue;
		}
		vector<int> ans;
		int n = 0;
		while(n < N) {
			int m = n+1;
			if(N-m-1 < 100) {
				cnt = 1;
				for(int i = 0; i < N-m-1; i++) if(cnt < K) cnt *= 2;
				while(m < N && cnt < K) {
					K -= cnt;
					cnt /= 2;
					m++;
				}
			}
			for(int i = m; i > n; i--) ans.push_back(i);
			n = m;
		}
		for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing