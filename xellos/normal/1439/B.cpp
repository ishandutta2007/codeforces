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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M, K;
		cin >> N >> M >> K;
		vector< vector<int> > G(N);
		vector<int> deg(N, 0);
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
			deg[u]++, deg[v]++;
		}
		vector<char> live(N, 1);
		queue<int> q;
		for(int i = 0; i < N; i++) if(deg[i] < K-1) {
			q.push(i);
			live[i] = 0;
		}
		while(!q.empty()) {
			for(auto v : G[q.front()]) if(live[v]) {
				deg[v]--;
				if(deg[v] < K-1) {
					q.push(v);
					live[v] = 0;
				}
			}
			q.pop();
		}
		vector< vector<int> > cl_cand;
		vector<char> ndel = live;
		for(int i = 0; i < N; i++) if(live[i] && deg[i] < K) {
			if(deg[i] == K-1) {
				vector<int> cl = {i};
				for(auto u : G[i]) if(ndel[u]) cl.push_back(u);
				cl_cand.push_back(cl);
			}
			q.push(i);
			live[i] = 0;
		}
		vector<int> seq, seq_id(N, -1);
		while(!q.empty()) {
			seq_id[q.front()] = seq.size();
			seq.push_back(q.front());
			ndel[q.front()] = 0;
			for(auto v : G[q.front()]) if(live[v]) {
				deg[v]--;
				if(deg[v] < K) {
					if(deg[v] == K-1) {
						vector<int> cl = {v};
						for(auto u : G[v]) if(ndel[u]) cl.push_back(u);
						cl_cand.push_back(cl);
					}
					q.push(v);
					live[v] = 0;
				}
			}
			q.pop();
		}
		vector<int> ans_set;
		for(int i = 0; i < N; i++) if(live[i]) ans_set.push_back(i);
		if(!ans_set.empty()) {
			cout << "1 " << ans_set.size() << "\n";
			for(int i = 0; i < (int)ans_set.size(); i++) {
				if(i) cout << " ";
				cout << ans_set[i]+1;
			}
			cout << "\n";
			continue;
		}
		vector< vector<int> > cl_cand_s;
		vector< vector<int> > in_cl(N);
		for(auto cl : cl_cand) {
			vector<int> cl_s;
			for(auto v : cl) {
				cl_s.push_back(seq_id[v]);
				in_cl[seq_id[v]].push_back(cl_cand_s.size());
			}
			sort(begin(cl_s), end(cl_s));
			cl_cand_s.push_back(cl_s);
		}
		vector<char> ok_cl(cl_cand_s.size(), 1);
		vector<int> has_edge(N, -1);
		for(int i = 0; i < (int)seq.size(); i++) {
			int v = seq[i];
			for(auto u : G[v]) if(seq_id[u] != -1 && seq_id[u] < i)
				has_edge[seq_id[u]] = i;
			for(auto id : in_cl[i]) if(ok_cl[id]) {
				for(int j = 0; cl_cand_s[id][j] != i; j++)
					ok_cl[id] &= (has_edge[cl_cand_s[id][j]] == i);
			}
		}
		vector<int> ans_cl;
		for(int i = 0; i < (int)cl_cand.size(); i++) if(ok_cl[i]) ans_cl = cl_cand[i];
		if(ans_cl.empty()) cout << "-1\n";
		else {
			cout << "2\n";
			for(int i = 0; i < K; i++) cout << ans_cl[i]+1 << ((i == K-1) ? "\n" : " ");
		}
	}
}

// look at my code
// my code is amazing