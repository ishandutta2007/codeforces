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

template <typename T>
class minfin {
	vector<T> node_val;
	T init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	minfin(int N, T init_val) {
		init_val_ = init_val;
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

vector<int> idx, scc, up;
int cur_idx;
stack<int> st;
vector<char> in_st;
int n_scc;

void DFS(int v, auto & G) {
	idx[v] = up[v] = cur_idx;
	cur_idx++;
	st.push(v);
	in_st[v] = 1;
	for(auto s : G[v]) {
		if(idx[s] == -1) {
			DFS(s, G);
			up[v] = min(up[v], up[s]);
		}
		else if(in_st[s]) up[v] = min(up[v], idx[s]);
	}
	if(idx[v] == up[v]) {
		while(true) {
			int u = st.top();
			in_st[u] = 0;
			st.pop();
			scc[u] = n_scc;
			if(u == v) break;
		}
		n_scc++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector<string> V(N);
	// for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
	// 	if(rand()%100 < 50) V[i] += '#';
	// 	else V[i] += '.';
	// }
	for(int i = 0; i < N; i++) cin >> V[i];
	for(int i = 0; i < N-1; i++) for(int j = 0; j < M; j++)
		if(V[i][j] != '.' && V[i+1][j] == '.') V[i+1][j] = 'C';
	vector< vector<int> > G(N*M);
	for(int i = 0; i < N-1; i++) for(int j = 0; j < M; j++) {
		if(V[i][j] == '#' && V[i+1][j] == '#') {
			G[i*M+j].push_back(i*M+M+j);
			G[i*M+M+j].push_back(i*M+j);
		}
		else if(V[i][j] != '.')
			G[i*M+j].push_back(i*M+M+j);
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < M-1; j++) {
		if(V[i][j] == '#' && V[i][j+1] == '#') {
			G[i*M+j].push_back(i*M+j+1);
			G[i*M+j+1].push_back(i*M+j);
		}
		if(V[i][j] == 'C' && V[i][j+1] == '#')
			G[i*M+j].push_back(i*M+j+1);
		if(V[i][j] == '#' && V[i][j+1] == 'C')
			G[i*M+j+1].push_back(i*M+j);
	}
	idx.resize(N*M, -1);
	up.resize(N*M);
	in_st.resize(N*M, 0);
	scc.resize(N*M, -1);
	cur_idx = n_scc = 0;
	for(int i = 0; i < N*M; i++) if(V[i/M][i%M] != '.' && idx[i] == -1) DFS(i, G);
	if(n_scc == 0) {
		cout << "0\n";
		return 0;
	}
	vector< vector<int> > G_scc(n_scc);
	vector<int> Di_scc(n_scc, 0);
	for(int i = 0; i < N*M; i++) for(auto s : G[i]) if(scc[i] != -1 && scc[s] != -1 && scc[i] != scc[s]) {
		G_scc[scc[i]].push_back(scc[s]);
		Di_scc[scc[s]]++;
	}
	vector<int> L(n_scc, M), R(n_scc, -1);
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(idx[i*M+j] != -1) {
		L[scc[i*M+j]] = min(L[scc[i*M+j]], j);
		R[scc[i*M+j]] = max(R[scc[i*M+j]], j);
	}
	vector< pair<int, int> > top;
	queue<int> q;
	for(int i = 0; i < n_scc; i++) if(Di_scc[i] == 0) {
		top.push_back({L[i], i});
		q.push(i);
	}
	sort(begin(top), end(top));
	vector<int> L_id(n_scc, n_scc), R_id(n_scc, -1);
	for(int i = 0; i < (int)top.size(); i++) L_id[top[i].ss] = R_id[top[i].ss] = i;
	while(!q.empty()) {
		for(auto s : G_scc[q.front()]) {
			L_id[s] = min(L_id[s], L_id[q.front()]);
			R_id[s] = max(R_id[s], R_id[q.front()]);
			Di_scc[s]--;
			if(Di_scc[s] == 0) q.push(s);
		}
		q.pop();
	}
	vector<int> A(M);
	for(int i = 0; i < M; i++) {
		// int n = 0;
		// for(int j = 0; j < N; j++) if(V[j][i] == '#') n++;
		// A[i] = rand()%(n+1);
		cin >> A[i];
	}
	vector< pair<int, int> > I;
	for(int i = 0; i < M; i++) if(A[i]) {
		int a = A[i], r = -1;
		for(int j = N-1; j >= 0; j--) if(V[j][i] == '#') {
			a--;
			if(a == 0) {r = j; break;}
		}
		I.push_back({L_id[scc[r*M+i]], R_id[scc[r*M+i]]});
	}
	int sz = I.size(), K = top.size();
	if(sz == 0) {
		cout << "0\n";
		return 0;
	}
	for(int i = 0; i < sz; i++) swap(I[i].ff, I[i].ss);
	sort(begin(I), end(I));
	for(int i = 0; i < sz; i++) swap(I[i].ff, I[i].ss);
	vector<int> cnt(K, K+1);
	int L_max = -1;
	minfin<int> F(K, K+1);
	for(int i = 0, j = 0; i < K; i++) {
		while(j < sz && I[j].ss < i) {
			L_max = max(L_max, I[j].ff);
			j++;
		}
		// previous >= L_max
		if(L_max == -1) cnt[i] = 1;
		else cnt[i] = F.get(K-1-L_max)+1;
		F.put(K-1-i, cnt[i]);
	}
	for(int i = 0; i < sz; i++) L_max = max(L_max, I[i].ff);
	int ans = K+1;
	for(int i = L_max; i < K; i++) ans = min(ans, cnt[i]);
	cout << ans << "\n";
}

// look at my code
// my code is amazing