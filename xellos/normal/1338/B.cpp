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

void DFS(int R, int par, auto & G, auto & val) {
	for(auto v : G[R]) if(par != v) {
		val[v] = 1-val[R];
		DFS(v, R, G, val);
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
	vector<int> val(N, 0);
	DFS(0, 0, G, val);
	set<int> s_val;
	for(int i = 0; i < N; i++) if(G[i].size() == 1U) s_val.insert(val[i]);
	int ans_mi = 2*s_val.size()-1;
	set<int> disj;
	int ans_mx = N-1;
	for(int i = 0; i < N; i++) if(G[i].size() == 1U) {
		auto it = disj.find(G[i][0]);
		if(it != end(disj)) ans_mx--;
		disj.insert(G[i][0]);
	}
	cout << ans_mi << " " << ans_mx << "\n";
	return 0;
}

// look at my code
// my code is amazing