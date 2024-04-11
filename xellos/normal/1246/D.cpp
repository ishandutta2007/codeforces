#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, auto & sons, auto & dep) {
	for(auto s : sons[R]) {
		dep[s] = dep[R]+1;
		DFS(s, sons, dep);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> par(N, 0);
	vector< vector<int> > sons(N);
	set< pair<int, int> > E;
	for(int i = 0; i < N-1; i++) {
		cin >> par[i+1];
		sons[par[i+1]].push_back(i+1);
		E.insert({par[i+1], i+1});
	}
	// vector<int> par0 = par;
	vector<int> dep(N, 0);
	DFS(0, sons, dep);
	int max_dep_v = 0;
	for(int i = 0; i < N; i++)
		if(dep[i] > dep[max_dep_v]) max_dep_v = i;
	vector<int> V, Vr(1, 0);
	while(max_dep_v) {
		V.push_back(max_dep_v);
		max_dep_v = par[max_dep_v];
	}
	vector<int> ans;
	while(!V.empty()) {
		auto it = E.lower_bound({Vr.back(), 0});
		auto jt = it; jt++;
		if(jt == end(E) || jt->first != it->first) {
			Vr.push_back(V.back());
			V.pop_back();
			continue;
		}
		int s = (it->ss == V.back()) ? jt->ss : it->ss;
		ans.push_back(V.back());
		par[V.back()] = s;
		E.erase({Vr.back(), V.back()});
		E.insert({s, V.back()});
		V.push_back(s);
	}

	for(int i = 0; i < N; i++) cout << Vr[i] << ((i == N-1) ? "\n" : " ");
	reverse(begin(ans), end(ans));
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << ((i+1 == ans.size()) ? "\n" : " ");
	// vector<int> par1(N);
	// for(int i = 1; i < N; i++) par1[Vr[i]] = Vr[i-1];
	// par1[Vr[0]] = Vr[0];
	// for(int i = 0; i < (int)ans.size(); i++) {
	// 	if(ans[i] == 	) cerr << "FAIL\n";
	// }
	// cerr << (par1 == par0) << "\n";
	return 0;
}

// look at my code
// my code is amazing