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

struct actree {
	struct node {
		int son[26];
		int dep, prev, last_end, id;

		node(int dep_) : dep(dep_), prev(0), last_end(0), id(-1) {
			memset(son, -1, sizeof(son));
		}
	};

	vector<node> T;

	actree(vector<string> & S) {
		T.reserve(1000000);
		T.push_back(node(0));
		int N = S.size();
		for(int i = 0; i < N; i++) {
			int cur = 0;
			for(int j = 0; j < (int)S[i].length(); j++) {
				if(T[cur].son[S[i][j]-'a'] == -1) {
					T[cur].son[S[i][j]-'a'] = T.size();
					T.push_back(node(T[cur].dep+1));
				}
				cur = T[cur].son[S[i][j]-'a'];
			}
			T[cur].last_end = cur;
			T[cur].id = i;
		}
		vector<int> cur_layer = {0};
		while(!cur_layer.empty()) {
			vector<int> next_layer;
			for(auto v : cur_layer) for(int i = 0; i < 26; i++) {
				int s = T[v].son[i];
				if(s == -1) continue;
				int p = T[v].prev;
				while(p && T[p].son[i] == -1) p = T[p].prev;
				if(p != v && T[p].son[i] != -1) p = T[p].son[i];
				T[s].prev = p;
				if(T[s].last_end == 0) T[s].last_end = T[p].last_end;
				next_layer.push_back(s);
			}
			cur_layer = next_layer;
		}
	}

	int push(int cur, char c) { return T[cur].son[c-'a']; }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<string> S(N);
	for(int i = 0; i < N; i++) cin >> S[i];
	constexpr int MAX_L = 1000000;
	vector< vector<int> > S_by_L(MAX_L+1);
	actree AC(S);
	vector< vector<int> > G(N);
	for(int i = 0; i < N; i++) {
		int L = S[i].length();
		S_by_L[L].push_back(i);
		vector<int> max_len(L, 0), id(L, -1);
		int cur = 0;
		for(int j = 0; j < L; j++) {
			cur = AC.push(cur, S[i][j]);
			if(AC.T[cur].last_end == cur && j == L-1) {
				int prev_end = AC.T[cur].prev;
				prev_end = AC.T[prev_end].last_end;
				max_len[j] = AC.T[prev_end].dep;
				id[j] = AC.T[prev_end].id;
			}
			else {
				max_len[j] = AC.T[AC.T[cur].last_end].dep;
				id[j] = AC.T[AC.T[cur].last_end].id;
			}
		}
		int min_left_pos = L;
		for(int j = L-1; j >= 0; j--) {
			if(max_len[j] && min_left_pos > j+1-max_len[j]) G[i].push_back(id[j]);
			min_left_pos = min(min_left_pos, j+1-max_len[j]);
		}
	}
	int ans = 0;
	vector< vector<int> > under(N);
	vector<char> B(N, 0);
int n_pb = 0;
	for(int L = 1; L <= MAX_L; L++) for(int v : S_by_L[L]) {
		for(auto u : G[v]) for(auto x : under[u]) B[x] = 1;
		for(auto u : G[v]) if(!B[u]) {
			B[u] = 1;
			under[v].push_back(u);
			ans++;
		}
		for(auto u : G[v]) for(auto x : under[u]) under[v].push_back(x), n_pb++;
		sort(begin(under[v]), end(under[v]));
		auto it = unique(begin(under[v]), end(under[v]));
		under[v].resize(it-begin(under[v]));
		for(auto x : under[v]) B[x] = 0;
	}
	if(n_pb < 10000000) cout << ans << "\n";
}

// look at my code
// my code is amazing