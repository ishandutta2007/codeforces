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

vector< pair<cat, cat> > I;
vector< map<cat, int> > down_times;
vector<int> id;

void DFS(int v, int par, auto & G, auto & fin, auto & dep, auto & sz) {
	sz[v] = fin[v].size();
	int max_sz = 0, max_sz_son = -1, last_son = -1;
	for(auto [s, d] : G[v]) if(par != s) {
		last_son = s;
		dep[s] = dep[v] + d;
		DFS(s, v, G, fin, dep, sz);
		sz[v] += sz[s];
		if(sz[s] > max_sz) max_sz = sz[s], max_sz_son = s;
	}
	if(max_sz) {
		id[v] = id[max_sz_son];
		cat first_time = begin(down_times[id[v]])->ff;
		int first_dir = max_sz_son;
		auto & S = down_times[id[v]];
		static vector<decltype(begin(S))> added;
		added.clear();
		for(auto [s, x] : G[v]) if(par != s && max_sz_son != s) {
			if(sz[s] == 0) continue;
			if(begin(down_times[id[s]])->ff < first_time) {
				first_time = begin(down_times[id[s]])->ff;
				first_dir = s;
			}
			for(auto [t, y] : down_times[id[s]]) {
				auto [it, b] = S.insert({t, id[s]});
				if(!b) {
					I.push_back({t+dep[v], t+dep[v]});
					continue;
				}
				added.push_back(it);
			}
		}
		for(auto it : added) {
			if(it != begin(S)) {
				auto jt = it;
				jt--;
				if(jt->ss != it->ss)
					I.push_back({jt->ff+dep[v], it->ff+dep[v]});
			}
			auto jt = it;
			jt++;
			if(jt != end(S) && jt->ss != it->ss && jt->ss == id[v])
				I.push_back({it->ff+dep[v], jt->ff+dep[v]});
		}
		for(auto it : added) it->ss = id[v];
		if(first_dir != last_son) I.push_back({0, first_time+dep[v]});
	}
	else {
		id[v] = down_times.size();
		down_times.push_back({});
	}
	for(auto t : fin[v]) down_times[id[v]].insert({t, id[v]});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cat d;
		cin >> u >> v >> d;
		G[--u].push_back({--v, d});
		G[v].push_back({u, d});
	}
	vector< vector<cat> > fin(N);
	for(int i = 0; i < M; i++) {
		int s;
		cat t;
		cin >> s >> t;
		fin[--s].push_back(t);
	}
	vector<cat> dep(N, 0);
	vector<int> sz(N, 0);
	id.resize(N);
	DFS(0, 0, G, fin, dep, sz);
	for(auto & p : I) swap(p.ff, p.ss);
	sort(begin(I), end(I));
	for(auto & p : I) swap(p.ff, p.ss);
	set< pair<cat, cat> > used_times;
	int a = 0;
	while(a < (int)I.size()) {
		cat t = I[a].ff+1;
		// find mex time
		auto it = used_times.lower_bound({t+1, -1LL});
		if(it != begin(used_times)) {
			it--;
			if(it->ss > t) t = it->ss;
		}
		if(t > I[a].ss) break;
		if(it != end(used_times) && t == it->ss) {
			used_times.insert({it->ff, it->ss+1});
			used_times.erase(it);
		}
		else used_times.insert({t, t+1});
		it = used_times.lower_bound({t+1, -1LL});
		if(it != end(used_times) && it->ff == t+1) {
			auto jt = it;
			jt--;
			if(jt->ss == t+1) {
				used_times.insert({jt->ff, it->ss});
				used_times.erase(jt);
				used_times.erase(it);
			}
		}
		a++;
	}
	if(a == (int)I.size()) {
		cout << "-1 " << I.size() << "\n";
		return 0;
	}
	for(int i = 0; i < (int)I.size(); i++) if(I[i].ss == I[a].ss) {
		cout << I[i].ss << " " << i << "\n";
		break;
	}
	return 0;
}

// look at my code
// my code is amazing