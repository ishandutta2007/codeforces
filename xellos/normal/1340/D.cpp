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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, int par, auto & G, auto & ans, int T) {
	int S = G[R].size()-(par!=R);
	bool rewind_done = false;
	int T_rewind = T-1;
	for(auto v : G[R]) if(par != v) {
		if(S <= T_rewind && !rewind_done) {
			ans.push_back({R, T_rewind-S});
			T = T_rewind-S;
			rewind_done = true;
		}
		ans.push_back({v, T+1});
		DFS(v, R, G, ans, T+1);
		ans.push_back({R, T+1});
		T++;
		S--;
	}
	if(R != par && !rewind_done) ans.push_back({R, T_rewind});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	if(N == 1) {
		cout << "1\n1 0\n";
		return 0;
	}
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector< pair<int, int> > ans = {{0, 0}};
	DFS(0, 0, G, ans, 0);
	cout << ans.size() << "\n";
	for(auto p : ans) cout << p.ff+1 << " " << p.ss << "\n";
	return 0;
}

// look at my code
// my code is amazing