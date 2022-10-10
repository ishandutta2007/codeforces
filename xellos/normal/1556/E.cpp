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
	int N, Q;
	cin >> N >> Q;
	vector<cat> A(N, 0);
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i] -= a;
	}
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i] += a;
	}
	vector<cat> S(N+1, 0);
	for(int i = 0; i < N; i++) S[i+1] = S[i] + A[i];
	vector< vector< pair<int,int> > > qus(N);
	vector<cat> ans(Q, -1);
	for(int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		l--;
		if(S[r] == S[l]) qus[l].push_back({q, r});
	}
	vector< pair<int,cat> > st_lt, st_gt;
	st_lt.push_back({N+1, -OVER9000});
	st_lt.push_back({N, S[N]});
	st_gt.push_back({-N, S[N]});
	for(int i = N-1; i >= 0; i--) {
		while(!st_lt.empty() && st_lt.back().ss >= S[i]) st_lt.pop_back();
		while(!st_gt.empty() && st_gt.back().ss <= S[i]) st_gt.pop_back();
		st_gt.push_back({-i, S[i]});
		for(auto qu : qus[i]) {
			if(qu.ss >= st_lt.back().ff) continue;
			auto it = lower_bound(begin(st_gt), end(st_gt), make_pair(-qu.ss, -OVER9000));
			ans[qu.ff] = it->ss - S[i];
		}
		st_lt.push_back({i, S[i]});
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}

// look at my code
// my code is amazing