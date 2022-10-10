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

void solve(int R, int par, auto & G, auto & C, auto & min_dep_w, auto & min_dep_b, int max_l) {
	int dep_w[2] = {0, 0};
	int dep_b[2] = {0, 0};
	for(auto s : G[R]) if(s != par) {
		solve(s, R, G, C, min_dep_w, min_dep_b, max_l);
		if(C[R] != 2) {
			int d = min(min_dep_w[s], min_dep_b[s]+1);
			if(d >= dep_w[0]) {
				dep_w[1] = dep_w[0];
				dep_w[0] = d;
			}
			else if(d > dep_w[1]) dep_w[1] = d;
		}
		if(C[R] != 1) {
			int d = min(min_dep_w[s]+1, min_dep_b[s]);
			if(d >= dep_b[0]) {
				dep_b[1] = dep_b[0];
				dep_b[0] = d;
			}
			else if(d > dep_b[1]) dep_b[1] = d;
		}
	}
	if(C[R] != 2 && dep_w[0]+dep_w[1]+1 <= max_l) min_dep_w[R] = dep_w[0];
	if(C[R] != 1 && dep_b[0]+dep_b[1]+1 <= max_l) min_dep_b[R] = dep_b[0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> C(N);
		for(int i = 0; i < N; i++) cin >> C[i];
		vector< vector<int> > G(N);
		for(int i = 0; i < N-1; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}
		int ans_lt = 0, ans_ge = N;
		while(ans_ge-ans_lt > 1) {
			int cur = (ans_lt+ans_ge)/2;
			vector<int> min_dep_w(N, N+1), min_dep_b(N, N+1);
			solve(0, 0, G, C, min_dep_w, min_dep_b, 2*(cur-1)+1);
			if(min(min_dep_w[0], min_dep_b[0]) <= 2*(cur-1)) ans_ge = cur;
			else ans_lt = cur;
		}
		cout << ans_ge << "\n";
	}
}

// look at my code
// my code is amazing