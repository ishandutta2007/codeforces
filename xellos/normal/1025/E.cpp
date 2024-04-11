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

struct op {
	int ro, co, rg, cg;
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	if(N == 1) {
		cout << "0\n";
		return 0;
	}
	vector< pair<int, int> > pos(M), goal(M);
	for(int i = 0; i < M; i++) cin >> pos[i].ff >> pos[i].ss;
	for(int i = 0; i < M; i++) cin >> goal[i].ff >> goal[i].ss;
	// vector< vector<int> > grid(N, vector<int>(N, -1));
	// for(int i = 0; i < M; i++) grid[pos[i].ff-1][pos[i].ss-1] = i;
	vector< vector< pair<int, int> > > cur(N);
	for(int i = 0; i < M; i++) cur[--pos[i].ff].push_back({--pos[i].ss, i});
	vector<op> ops;
	for(int i = 0; i < N; i++) {
		sort(begin(cur[i]), end(cur[i]));
		for(int j = 0; j < (int)cur[i].size(); j++) while(cur[i][j].ff > j) {
			ops.push_back({i, cur[i][j].ff, i, cur[i][j].ff-1});
			cur[i][j].ff--;
		}
	}
	while(true) {
		int mxl = 0;
		for(int i = 0; i < N; i++) mxl = max(mxl, (int)cur[i].size());
		if(mxl == 1) break;
		int rn = 0;
		while(!cur[rn].empty()) rn++;
		int ro = 0;
		for(int i = rn+1; i < N; i++) if(mxl == (int)cur[i].size()) {
			ro = i;
			break;
		}
		for(int i = rn-1; i > 0; i--) if(mxl == (int)cur[i].size()) {
			ro = i;
			break;
		}
		if(rn > ro)
			for(int j = ro; j < rn; j++) ops.push_back({j, cur[ro].back().ff, j+1, cur[ro].back().ff});
		if(rn < ro)
			for(int j = ro; j > rn; j--) ops.push_back({j, cur[ro].back().ff, j-1, cur[ro].back().ff});
		for(int i = cur[ro].back().ff; i > 0; i--) ops.push_back({rn, i, rn, i-1});
		cur[rn].push_back({0, cur[ro].back().ss});
		cur[ro].pop_back();
	}
	vector< vector< pair<int, int> > > goal_ord(N);
	for(int i = 0; i < M; i++) goal_ord[--goal[i].ff].push_back({--goal[i].ss, i});
	vector<int> goal_rid;
	for(int i = 0; i < N; i++) if(!goal_ord[i].empty()) {
		sort(begin(goal_ord[i]), end(goal_ord[i]));
		int rn = goal_rid.size();
		goal_rid.push_back(i);
		for(int j = 0; j < (int)goal_ord[i].size(); j++) {
			int id = goal_ord[i][j].ss;
			int ro = rn;
			while(cur[ro].empty() || cur[ro][0].ss != id) ro++;
			if(j > 0 || cur[rn].empty()) {
				int c = max(1, goal_ord[i][j].ff);
				for(int k = 0; k < c; k++) ops.push_back({ro, k, ro, k+1});
				for(int k = ro; k > rn; k--) ops.push_back({k, c, k-1, c});
				cur[ro].pop_back();
				if(goal_ord[i][j].ff == 0) ops.push_back({rn, 1, rn, 0});
				continue;
			}
			// j == 0
			ops.push_back({ro, 0, ro, 1});
			cur[ro].pop_back();
			for(int k = ro; k > rn; k--) if(!cur[k-1].empty()) {
				ops.push_back({k-1, 0, k, 0});
				cur[k].push_back(cur[k-1].back());
				cur[k-1].pop_back();
			}
			for(int k = ro; k > rn; k--) ops.push_back({k, 1, k-1, 1});
			if(goal_ord[i][j].ff == 0) ops.push_back({rn, 1, rn, 0});
			else for(int k = 1; k < goal_ord[i][j].ff; k++) ops.push_back({rn, k, rn, k+1});
			cur[rn].push_back({goal_ord[i][0].ff, id});
		}
	}
	for(int i = goal_rid.size()-1; i >= 0; i--) {
		int ro = i, rn = goal_rid[i];
		ALL_THE(goal_ord[rn], it) for(int k = ro; k < rn; k++) ops.push_back({k, it->ff, k+1, it->ff});
	}
	cout << ops.size() << "\n";
	ALL_THE(ops, it) cout << it->ro+1 << " " << it->co+1 << " " << it->rg+1 << " " << it->cg+1 << "\n";
	// ALL_THE(ops, it) {
	// 	if(grid[it->rg][it->cg] != -1) cerr << "FAIL\n";
	// 	if(grid[it->ro][it->co] == -1) cerr << "FAIL\n";
	// 	swap(grid[it->ro][it->co], grid[it->rg][it->cg]);
	// }
	// for(int i = 0; i < M; i++) if(grid[goal[i].ff][goal[i].ss] != i) cerr << "FAIL\n";
	return 0;
}

// look at my code
// my code is amazing