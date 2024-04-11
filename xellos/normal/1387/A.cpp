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

void DFS(int R, auto & G, auto & vis, auto & val, auto & sign, auto & val_seq_p, auto & val_seq_n, pair<dbl, int> & fixed) {
	if(sign[R] == -1) val_seq_n.push_back({val[R], R});
	else val_seq_p.push_back({val[R], R});
	for(auto [s, c] : G[R]) if(vis[s] == 0) {
		vis[s] = 1;
		val[s] = c-val[R];
		sign[s] = -sign[R];
		DFS(s, G, vis, val, sign, val_seq_p, val_seq_n, fixed);
	}
	for(auto [s, c] : G[R]) if(sign[s] == sign[R] && !fixed.ss) {
		if(sign[s] == -1) fixed = {(val[s]+val[R]-c)/2., 1};
		else fixed = {(c-val[s]-val[R])/2., 1};
	}
}

dbl solve(auto val_seq_p, auto val_seq_n) {
	sort(begin(val_seq_p), end(val_seq_p));
	sort(begin(val_seq_n), end(val_seq_n));
	int sz_p = val_seq_p.size();
	int sz_n = val_seq_n.size();
	vector<cat> sum_p(sz_p+1, 0), sum_n(sz_n+1, 0);
	for(int i = 0; i < sz_p; i++) sum_p[i+1] = sum_p[i] + val_seq_p[i].ff;
	for(int i = 0; i < sz_n; i++) sum_n[i+1] = sum_n[i] + val_seq_n[i].ff;
	// val_seq_p[i]+ret == 0
	// val_seq_n[a:]-ret >= 0
	// cost == sum (val_seq_p[i:]+ret) - sum (val_seq_p[:i]+ret) + sum (val_seq_n[a:]-ret) - sum (val_seq_n[:a]-ret)
	dbl cost = 1e18, ret = 0;
	for(int i = 0, a = sz_n; i < sz_p; i++) {
		dbl cur = -val_seq_p[i].ff;
		while(a > 0 && val_seq_n[a-1].ff >= cur) a--;
		dbl cur_cost = (sz_p-2*i)*cur+sum_p[sz_p]-2*sum_p[i] + (sz_n-2*a)*(-cur)+sum_n[sz_n]-2*sum_n[a];
		if(cur_cost < cost) cost = cur_cost, ret = cur;
	}
	// val_seq_n[i]-ret == 0
	// val_seq_p[a:]+ret >= 0
	for(int i = 0, a = sz_p; i < sz_n; i++) {
		dbl cur = val_seq_n[i].ff;
		while(a > 0 && val_seq_p[a-1].ff >= -cur) a--;
		dbl cur_cost = (sz_p-2*a)*cur+sum_p[sz_p]-2*sum_p[a] + (sz_n-2*i)*(-cur)+sum_n[sz_n]-2*sum_n[i];
		if(cur_cost < cost) cost = cur_cost, ret = cur;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[--u].push_back({--v, c});
		G[v].push_back({u, c});
	}
	vector<int> vis(N, 0), val(N, 0), sign(N, 1);
	vector<dbl> ans(N);
	for(int i = 0; i < N; i++) if(vis[i] == 0) {
		vector< pair<int, int> > val_seq_p, val_seq_n;
		vis[i] = 1;
		pair<dbl, int> fixed = {0, 0};
		DFS(i, G, vis, val, sign, val_seq_p, val_seq_n, fixed);
		if(fixed.ss) ans[i] = fixed.ff;
		else ans[i] = solve(val_seq_p, val_seq_n);
		for(auto [x, v] : val_seq_p) ans[v] = ans[i]+x;
		for(auto [x, v] : val_seq_n) ans[v] = -ans[i]+x;
	}
	for(int i = 0; i < N; i++) for(auto [s, c] : G[i]) if(ans[s]+ans[i] != c) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing