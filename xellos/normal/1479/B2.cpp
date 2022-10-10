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

struct itree {
	int b, v0;
	vector<int> val;

	itree(int N, int v0_) {
		v0 = v0_;
		b = 1;
		while(b < N) b *= 2;
		val.resize(2*b, v0);
	}

	void put(int pos, int v, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		if(l == pos && r == pos+1) {
			val[cur] = min(val[cur], v);
			return;
		}
		int m = (l+r)/2;
		if(pos < m) put(pos, v, 2*cur, l, m);
		else put(pos, v, 2*cur+1, m, r);
		val[cur] = min(val[2*cur], val[2*cur+1]);
	}

	int get(int I_l, int I_r, int cur = 1, int l = 0, int r = 0) {
		if(cur == 1) r = b;
		I_l = max(I_l, l);
		I_r = min(I_r, r);
		if(I_l >= I_r) return v0;
		if(l == I_l && r == I_r) return val[cur];
		int m = (l+r)/2;
		return min(get(I_l, I_r, 2*cur, l, m), get(I_l, I_r, 2*cur+1, m, r));
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	itree I(N+1, N);
	I.put(0, 1);
	int add_val = 0;
	for(int i = 1; i < N; i++) {
		int a = min(I.get(A[i], A[i]+1), min(I.get(0, A[i]) + 1, I.get(A[i]+1, N+1) + 1));
		if(A[i] != A[i-1]) a--;
		I.put(A[i-1], a);
		if(A[i] != A[i-1]) add_val++;
	}
	int ans = I.get(0, N+1);
	cout << ans+add_val << "\n";
}

// look at my code
// my code is amazing