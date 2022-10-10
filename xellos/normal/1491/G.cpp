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

void solve(auto cyc, auto & P, auto & st, auto & ans) {
	// P[cyc[i]] == cyc[i+1]
	// swap(P[cyc[i]], P[cyc[i+1]]): P[cyc[i+1]] bude cyc[i+1], P[cyc[i]] bude P[cyc[i+1]]
	// st[]
	int D[2] = {-1, -1};
	for(auto x : cyc) if(st[x]) {
		if(D[0] == -1) D[0] = x;
		else D[1] = x;
	}
	while(!st[P[D[0]]]) {
		ans.push_back({D[0], P[D[0]]});
		swap(P[D[0]], P[P[D[0]]]);
	}
	while(!st[P[D[1]]]) {
		ans.push_back({D[1], P[D[1]]});
		swap(P[D[1]], P[P[D[1]]]);
	}
	ans.push_back({D[0], D[1]});
	swap(P[D[0]], P[D[1]]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> P(N), st(N, 0);
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		P[i]--;
	}
	vector<int> cyc_last, vis(N, 0);
	vector< pair<int, int> > ans;
	for(int i = 0; i < N; i++) if(!vis[i]) {
		vis[i] = 1;
		if(P[i] == i) continue;
		int cur = P[i];
		vector<int> cyc_cur = {i};
		while(!vis[cur]) {
			cyc_cur.push_back(cur);
			vis[cur] = 1;
			cur = P[cur];
		}
		if(cyc_last.empty()) {
			cyc_last = cyc_cur;
			continue;
		}
		ans.push_back({cyc_last[0], cyc_cur[0]});
		swap(P[cyc_last[0]], P[cyc_cur[0]]);
		st[cyc_last[0]] = st[cyc_cur[0]] = 1;
		vector<int> cyc_merged;
		cur = cyc_last[0];
		for(int j = 0; j < (int)cyc_last.size()+(int)cyc_cur.size(); j++) {
			cyc_merged.push_back(cur);
			cur = P[cur];
		}
		cyc_last.clear();
		solve(cyc_merged, P, st, ans);
	}
	if(!cyc_last.empty()) {
		if((int)cyc_last.size() == 2) {
			int f = 0;
			while(P[f] != f) f++;
			ans.push_back({cyc_last[0], f});
			swap(P[cyc_last[0]], P[f]);
			ans.push_back({cyc_last[1], f});
			swap(P[cyc_last[1]], P[f]);
			ans.push_back({cyc_last[0], f});
			swap(P[cyc_last[0]], P[f]);
		}
		else {
			ans.push_back({cyc_last[0], cyc_last[1]});
			swap(P[cyc_last[0]], P[cyc_last[1]]);
			st[cyc_last[0]] = st[cyc_last[1]] = 1;
			ans.push_back({cyc_last[2], cyc_last[1]});
			swap(P[cyc_last[2]], P[cyc_last[1]]);
			int cur = cyc_last[0];
			for(int i = 0; i < (int)cyc_last.size(); i++) {
				cyc_last[i] = cur;
				cur = P[cur];
			}
			solve(cyc_last, P, st, ans);
		}
	}
	for(int i = 0; i < N; i++) if(P[i] != i) cout << "F\n";
	cout << (int)ans.size() << "\n";
	for(auto p : ans) cout << p.ff+1 << " " << p.ss+1 << "\n";
}

// look at my code
// my code is amazing