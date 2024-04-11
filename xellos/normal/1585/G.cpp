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

void solve(int v, auto & G, auto & dep, auto & rank, auto & SG, auto & SG_path, auto & MEX_path, auto & in_path, auto & dep_path, auto & sz) {
	rank[v] = 0;
	sz[v] = 1;
	int sz_max = 0;
	in_path[v] = v;
	dep_path[v] = 0;
	int s_path = -1;
	for(auto s : G[v]) {
		dep[s] = dep[v]+1;
		solve(s, G, dep, rank, SG, SG_path, MEX_path, in_path, dep_path, sz);
		sz[v] += sz[s];
		if(sz[s] > sz_max) in_path[v] = in_path[s], dep_path[v] = dep_path[s]+1, s_path = s;
		if(rank[v] == 0) rank[v] = rank[s]+1;
		else rank[v] = min(rank[v], rank[s]+1);
	}
	int p = in_path[v];
	SG_path[p].resize(dep_path[v]+2, 0);
	MEX_path[p].resize(sz[v]+1, 0);
	if(rank[v]) {
		for(int i = rank[v]+1; i <= rank[s_path]+1; i++) MEX_path[p][SG_path[p][1+dep_path[v]-(i+1)]]--;
		SG_path[p][1+dep_path[v]] = SG_path[p][dep_path[v]]+1;
	}
	else MEX_path[p][SG_path[p][0]]++;
	for(auto s : G[v]) if(in_path[s] != in_path[v]) {
		for(int i = 0; i <= rank[v]; i++) {
			MEX_path[p][SG_path[p][1+dep_path[v]-(i+1)]]--;
			SG_path[p][1+dep_path[v]-(i+1)] ^= SG_path[in_path[s]][1+dep_path[s]-i];
			MEX_path[p][SG_path[p][1+dep_path[v]-(i+1)]]++;
		}
		SG_path[p][1+dep_path[v]] = 0;
	}
	while(MEX_path[p][SG_path[p][1+dep_path[v]]]) SG_path[p][1+dep_path[v]]++;
	SG[v] = SG_path[p][1+dep_path[v]];
	MEX_path[p][SG_path[p][1+dep_path[v]]]++;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<int> P(N), roots;
		vector< vector<int> > G(N);
		for(int i = 0; i < N; i++) {
			cin >> P[i];
			P[i]--;
			if(P[i] == -1) roots.push_back(i);
			else G[P[i]].push_back(i);
		}
		vector<int> SG(N, 0), dep(N, 0), rank(N), in_path(N), sz(N), dep_path(N);
		vector< vector<int> > SG_path(N), MEX_path(N);
		int SG_ans = 0;
		for(auto r : roots) {
			solve(r, G, dep, rank, SG, SG_path, MEX_path, in_path, dep_path, sz);
			SG_ans ^= SG[r];
		}
		cout << (SG_ans ? "YES\n" : "NO\n");
	}
}

// look at my code
// my code is amazing