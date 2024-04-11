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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int A[2];
		cin >> A[0] >> A[1];
		int N = A[0]+A[1];
		set<int> ans;
		for(int k = 0; k < 2; k++) {
			// n(0i)+n(1i) = A[0]
			// n(10)+n(11) = N/2
			// n(00)+n(01) = N-N/2
			for(int n0 = 0; n0 <= N; n0++) {
				int n1 = N-N/2-n0;
				int n2 = A[0]-n0;
				int n3 = N/2-n2;
				if(n1 >= 0 && n2 >= 0 && n3 >= 0)
					ans.insert(n1+n2); // n(01)+n(10)
			}
			swap(A[0], A[1]);
		}
		cout << ans.size() << "\n";
		bool st = true;
		for(auto x : ans) {
			if(st) st = false;
			else cout << " ";
			cout << x;
		}
		cout << "\n";
	}
}

// look at my code
// my code is amazing