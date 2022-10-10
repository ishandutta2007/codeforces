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

void solve(int R, int par, auto & G, auto & rem, auto & sum, auto & ans) {
	vector<int> rem_seq;
	for(auto s : G[R]) if(s != par) {
		solve(s, R, G, rem, sum, ans);
		sum[R] += sum[s];
		if(rem[s] != -1) {
			sum[R] += 2;
			rem_seq.push_back(rem[s]);
		}
	}
	rem_seq.push_back(R);
	if((int)rem_seq.size() == 1) {
		rem[R] = rem_seq[0];
		if(R == par) {
			sum[R] += 2;
			int x = 0;
			for(auto s : G[R]) x = s;
			ans[R] = ans[x];
			ans[x] = R;
		}
	}
	else {
		int sz = rem_seq.size();
		for(int i = 0; i < sz; i++) ans[rem_seq[i]] = rem_seq[(i+1)%sz];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> rem(N, -1), ans(N);
	vector<cat> sum(N, 0);
	solve(0, 0, G, rem, sum, ans);
	cout << sum[0] << "\n";
	for(int i = 0; i < N; i++) cout << ans[i]+1 << ((i == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing