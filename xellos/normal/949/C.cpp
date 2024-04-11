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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, vector< vector<int> > &G, vector<int> &idx, vector<int> &min_idx, int &idx_cur, stack<int> &S, vector<bool> &inS, vector<int> &ans) {
	min_idx[R] = idx[R];
	S.push(R);
	inS[R] = true;
	ALL_THE(G[R], it) {
		if(idx[*it] == -1) {
			idx[*it] = idx_cur++;
			DFS(*it, G, idx, min_idx, idx_cur, S, inS, ans);
			min_idx[R] = min(min_idx[R], min_idx[*it]);
		}
		else if(inS[*it])
			min_idx[R] = min(min_idx[R], idx[*it]);
	}
	if(min_idx[R] == idx[R]) {
		vector<int> cur(1, R);
		while(S.top() != R) {
			cur.push_back(S.top());
			S.pop();
		}
		S.pop();
		bool ok = true;
		ALL_THE(cur, it) ALL_THE(G[*it], jt) if(!inS[*jt]) ok = false;
		ALL_THE(cur, it) inS[*it] = false;
		if(ok && ans.size() > cur.size()) ans = cur;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, H;
	cin >> N >> M >> H;
	vector<int> U(N);
	for(int i = 0; i < N; i++) cin >> U[i];
	vector< vector<int> > G(N);
	for(int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if((U[x]+1-U[y])%H == 0) G[x].push_back(y);
		if((U[y]+1-U[x])%H == 0) G[y].push_back(x);
	}
	vector<int> idx(N, -1), min_idx(N), ans(N);
	for(int i = 0; i < N; i++) ans[i] = i;
	int idx_cur = 0;
	stack<int> S;
	vector<bool> inS(N, false);
	for(int i = 0; i < N; i++) if(idx[i] == -1) {
		idx[i] = idx_cur++;
		DFS(i, G, idx, min_idx, idx_cur, S, inS, ans);
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < (int)ans.size(); i++) cout << ans[i]+1 << ((i == (int)ans.size()-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing