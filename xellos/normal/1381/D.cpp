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

void DFS(int R, auto & G, auto & par, auto & dep_down, auto & dep_sub) {
	for(auto s : G[R]) if(par[s] == -1) {
		par[s] = R;
		dep_down[s] = dep_down[R]+1;
		DFS(s, G, par, dep_down, dep_sub);
		dep_sub[R] = max(dep_sub[R], dep_sub[s]+1);
	}
}

void DFS2(int R, auto & G, auto & par, auto & dep, auto & rev, int L, int max_dep_up = 0) {
	int cnt_sub = (max_dep_up >= L);
	for(auto s : G[R]) if(s != par[R] && dep[s]+1 >= L) cnt_sub++;
	rev[R] = cnt_sub >= 3;
	vector<int> dep_seq;
	for(auto s : G[R]) if(s != par[R]) dep_seq.push_back(dep[s]+1);
	dep_seq.push_back(0);
	for(int i = (int)dep_seq.size()-2; i >= 0; i--) dep_seq[i] = max(dep_seq[i], dep_seq[i+1]);
	int l = 0;
	for(auto s : G[R]) if(s != par[R]) {
		DFS2(s, G, par, dep, rev, L, max(max_dep_up, dep_seq[l+1])+1);
		max_dep_up = max(max_dep_up, dep[s]+1);
		l++;
	}
}

void DFS3(int R, int par, auto & G, auto & is_s, auto & rev, auto & S_dep, auto & S_rev, int dep = 0) {
	S_dep = max(S_dep, dep);
	if(rev[R]) S_rev = 1;
	for(auto s : G[R]) if(s != par && is_s[s] == 0)
		DFS3(s, R, G, is_s, rev, S_dep, S_rev, dep+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, A, B;
		cin >> N >> A >> B;
		A--, B--;
		vector< vector<int> > G(N);
		for(int i = 0; i < N-1; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}

		vector<int> par_g(N, -1), dep_g(N, 0), dep_sub(N, 0);
		par_g[A] = A;
		DFS(A, G, par_g, dep_g, dep_sub);

		int L = dep_g[B];
		vector<int> rev(N, 0);
		DFS2(A, G, par_g, dep_sub, rev, L);

		vector<char> S_rev(L+1, 0), is_s(N, 0);
		vector<int> S, S_dep(L+1);
		S.push_back(B);
		int cur = B;
		is_s[B] = 1;
		while(cur != A) {
			cur = par_g[cur];
			S.push_back(cur);
			is_s[cur] = 1;
		}
		for(int i = 0; i <= L; i++) DFS3(S[i], S[i], G, is_s, rev, S_dep[i], S_rev[i]);

		bool has_rev = false;
		for(int i = 0; i < N; i++) if(rev[i]) has_rev = true;
		if(!has_rev) {
			cout << "NO\n";
			continue;
		}

		int l = 0, r = L, dep_l = S_dep[0], dep_r = S_dep[L];
		while(dep_l < L && dep_r < L) {
			bool stop = true;
			while(r > L-dep_l) {
				r--;
				dep_r = max(dep_r, S_dep[r]-(L-r));
				stop = false;
			}
			if(stop) while(l < dep_r) {
				l++;
				dep_l = max(dep_l, S_dep[l]-l);
				stop = false;
			}
			if(stop) break;
		}

		if(dep_l >= L || dep_r >= L) {
			cout << "YES\n";
			continue;
		}
		has_rev = false;
		for(int i = 0; i <= l; i++) if(S_rev[i]) has_rev = true;
		for(int i = r; i <= L; i++) if(S_rev[i]) has_rev = true;
		cout << (has_rev ? "YES\n" : "NO\n");
	}
}

// look at my code
// my code is amazing