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

struct query {
	int l,k,id;
};

void solve(int v, auto & G, auto & A, auto & QS, auto & occ, vector<int> * l_occ, auto & n_occ, auto & ans) {
	int a = A[v];
	n_occ[occ[a]]--;
	occ[a]++;
	l_occ[occ[a]].push_back(a);
	for(auto qu : QS[v]) {
		int lt = qu.l-1, ge = (int)n_occ.size();
		// chcem prvy i co ma n_occ[i] >= n_occ[l-1]+k
		while(ge-lt > 1) {
			int m = (lt + ge) / 2;
			if(n_occ[m] >= n_occ[qu.l-1]+qu.k) ge = m;
			else lt = m;
		}
		if(ge == (int)n_occ.size()) {
			ans[qu.id] = -1;
			continue;
		}
		while(occ[l_occ[ge].back()] != ge) l_occ[ge].pop_back();
		ans[qu.id] = l_occ[ge].back()+1;
	}
	for(auto s : G[v])
		solve(s, G, A, QS, occ, l_occ, n_occ, ans);
	occ[a]--;
	n_occ[occ[a]]++;
	l_occ[occ[a]].push_back(a);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N, Q;
		cin >> N >> Q;
		vector<int> A(N);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			A[i]--;
		}
		vector< vector<int> > G(N);
		for(int i = 0; i < N-1; i++) {
			int p;
			cin >> p;
			G[p-1].push_back(i+1);
		}
		vector< vector<query> > qs(N);
		for(int i = 0; i < Q; i++) {
			int v,l,k;
			cin >> v >> l >> k;
			qs[v-1].push_back(query{.l = l, .k = k, .id = i});
		}
		vector<int> ans(Q), occ(N, 0), n_occ(N+1, N);
		static vector<int> l_occ[1000010];
		for(int i = 0; i <= N; i++) l_occ[i].clear();
		for(int i = 0; i < N; i++) l_occ[0].push_back(i);
		solve(0, G, A, qs, occ, l_occ, n_occ, ans);
		for(int i = 0; i < Q; i++) cout << ans[i] << ((i == Q-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing