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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > A(N, vector<int>(M));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> A[i][j];
	vector< vector<int> > B(N, vector<int>(M));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> B[i][j];
	set< pair<int, int> > gr;
	gr.insert({0, N});
	vector< set<int> > ax_spl(M);
	vector<int> ax_bl(M, 0);
	for(int i = 0; i < N-1; i++) for(int j = 0; j < M; j++) {
		if(B[i][j] < B[i+1][j]) ax_spl[j].insert(i);
		ax_bl[j] += (B[i][j] > B[i+1][j]);
	}
	set<int> ax;
	for(int i = 0; i < M; i++) if(ax_bl[i] == 0 && !ax_spl[i].empty()) ax.insert(i);
	vector<int> seq;
	while(!ax.empty()) {
		int a = *begin(ax);
		if(ax_spl[a].empty()) {
			ax.erase(a);
			continue;
		}
		seq.push_back(a);
		int s = *begin(ax_spl[a]);
		auto it = gr.upper_bound({s+1, -1});
		it--;
		int l = it->ff, r = it->ss;
		gr.erase(it);
		gr.insert({l, s+1});
		gr.insert({s+1, r});
		// split podla s
		for(int i = 0; i < M; i++) {
			ax_bl[i] -= (B[s][i] > B[s+1][i]);
			if(B[s][i] < B[s+1][i]) ax_spl[i].erase(s);
			if(ax_bl[i] == 0 && !ax_spl[i].empty()) ax.insert(i);
		}
	}
	cat mod1 = 1000000007, mod2 = 1000000009;
	cat P = 999983;
	vector<cat> HA(N), HB(N);
	for(int i = 0; i < N; i++) {
		cat h1 = 0, h2 = 0;
		for(int j = 0; j < M; j++) {
			h1 = (h1 * P + A[i][j]) % mod1;
			h2 = (h2 * P + A[i][j]) % mod2;
		}
		HA[i] = h1 * mod2 + h2;
	}
	for(int i = 0; i < N; i++) {
		cat h1 = 0, h2 = 0;
		for(int j = 0; j < M; j++) {
			h1 = (h1 * P + B[i][j]) % mod1;
			h2 = (h2 * P + B[i][j]) % mod2;
		}
		HB[i] = h1 * mod2 + h2;
	}
	map<cat, pair<int, int> > V;
	for(auto p : gr) V[HB[p.ff]] = p;
	for(int i = 0; i < N; i++) {
		// HA[i] == HB[l] for some l
		auto it = V.find(HA[i]);
		if(it == end(V)) {
			cout << "-1\n";
			return 0;
		}
		it->ss.ff++;
		if(it->ss.ff == it->ss.ss) V.erase(it);
	}
	reverse(begin(seq), end(seq));
	cout << seq.size() << "\n";
	for(int i = 0; i < (int)seq.size(); i++) cout << seq[i]+1 << ((i == (int)seq.size()-1) ? "\n" : " ");
}

// look at my code
// my code is amazing