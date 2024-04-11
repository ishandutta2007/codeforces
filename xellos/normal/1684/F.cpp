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
		int N,M;
		cin >> N >> M;
		vector<int> A(N);
		map<int,int> AM;
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			AM[A[i]] = 0;
		}
		int C = 0;
		for(auto & p : AM) p.ss = C++;
		for(int i = 0; i < N; i++) A[i] = AM[A[i]];
		vector<int> L(N, N);
		for(int i = 0; i < M; i++) {
			int l,r;
			cin >> l >> r;
			L[r-1] = min(L[r-1], l-1);
		}
		for(int i = N-1; i > 0; i--) L[i-1] = min(L[i-1], L[i]);
		vector< vector<int> > ids(C);
		vector< pair<int,int> > I(N+1, {N,0});
		int L_min = N;
		for(int i = 0; i < N; i++) {
			auto it = lower_bound(begin(ids[A[i]]), end(ids[A[i]]), L[i]);
			if(it != end(ids[A[i]])) I[i] = {*it, ids[A[i]].back()}, L_min = min(L_min, i);
			ids[A[i]].push_back(i);
		}
		if(L_min == N) {
			cout << "0\n";
			continue;
		}
		for(int i = N-2; i >= 0; i--) {
			I[i].ff = min(I[i].ff, I[i+1].ff);
			I[i].ss = max(I[i].ss, I[i+1].ss);
		}
		int ans = N;
		for(int r = L_min; r < N; r++) {
			if(I[r+1].ff == N) ans = min(ans, r+1-L_min);
			else if(I[r+1].ss <= r) ans = min(ans, r+1-min(L_min,I[r+1].ff));
		}
		cout << ans << "\n";
	}
}

// look at my code
// my code is amazing