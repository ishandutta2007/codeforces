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
#define OVER9000 1234567890123LL
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

struct edge {
	int u, v;
	cat cost;

	bool operator<(const edge & E) const {
		return cost < E.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int C, N;
	cin >> C >> N;
	vector<cat> A(C), B(N);
	for(int i = 0; i < C; i++) cin >> A[i];
	for(int i = 0; i < N; i++) cin >> B[i];
	vector< vector<int> > S(C);
	vector<edge> E;
	for(int i = 0; i < C; i++) {
		int s;
		cin >> s;
		S[i].resize(s);
		for(int j = 0; j < s; j++) {
			cin >> S[i][j];
			E.push_back({S[i][j]-1, N+i, B[S[i][j]-1]+A[i]});
		}
	}
	vector<int> in_comp(C+N);
	vector< vector<int> > comp(C+N);
	for(int i = 0; i < C+N; i++) in_comp[i] = i, comp[i] = {i};
	sort(begin(E), end(E));
	cat ans = 0;
	for(int i = (int)E.size()-1; i >= 0; i--) {
		int u = in_comp[E[i].u], v = in_comp[E[i].v];
		if(u == v) {
			ans += E[i].cost;
			continue;
		}
		if(comp[u].size() > comp[v].size()) swap(u, v);
		for(auto x : comp[u]) {
			comp[v].push_back(x);
			in_comp[x] = v;
		}
	}
	cout << ans << "\n";
}

// look at my code
// my code is amazing