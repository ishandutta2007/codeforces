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
	int x1, y1, x2, y2;
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M;
	cin >> N >> M;
	vector< vector<string> > V(N, vector<string>(M));
	vector< vector<string> > G(N, vector<string>(M));
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> V[i][j];
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> G[i][j];
	vector<op> ops;
	for(int i = 1; i < N; i++) for(int j = 2; j < M; j++)
		for(int k = 0; k < (int)V[i][j].length(); k++) ops.push_back({i, j, 0, j});
	vector<string> IV(M, "");
	for(int i = N-1; i >= 0; i--) for(int j = 2; j < M; j++) IV[j] += V[i][j];
	for(int i = 2; i < M; i++) for(int k = (int)IV[i].length()-1; k >= 0; k--) {
		if(IV[i][k] == '0') ops.push_back({0, i, 0, 0});
		else ops.push_back({0, i, 0, 1});
	}
	for(int i = 1; i < N; i++) {
		queue<char> q0, q1;
		for(int k = (int)V[i][0].length()-1; k >= 0; k--) q0.push(V[i][0][k]);
		for(int k = (int)V[i][1].length()-1; k >= 0; k--) q1.push(V[i][1][k]);
		while(!q0.empty() || !q1.empty()) {
			if(!q0.empty() && q0.front() == '0') {
				ops.push_back({i, 0, 0, 0});
				q0.pop();
				continue;
			}
			if(!q1.empty() && q1.front() == '1') {
				ops.push_back({i, 1, 0, 1});
				q1.pop();
				continue;
			}
			if(!q0.empty()) {
				ops.push_back({i, 0, i, 1});
				q1.push(q0.front());
				q0.pop();
			}
			else {
				ops.push_back({i, 1, i, 0});
				q0.push(q1.front());
				q1.pop();
			}
		}
	}
	{
		int i = 0;
		queue<char> q0, q1;
		for(int k = (int)V[i][0].length()-1; k >= 0; k--) q0.push(V[i][0][k]);
		for(int k = (int)V[i][1].length()-1; k >= 0; k--) q1.push(V[i][1][k]);
		while(!q0.empty() || !q1.empty()) {
			if(!q0.empty() && q0.front() == '0') {
				ops.push_back({0, 0, 1, 0});
				ops.push_back({1, 0, 0, 0});
				q0.pop();
				continue;
			}
			if(!q1.empty() && q1.front() == '1') {
				ops.push_back({0, 1, 1, 1});
				ops.push_back({1, 1, 0, 1});
				q1.pop();
				continue;
			}
			if(!q0.empty()) {
				ops.push_back({0, 0, 0, 1});
				q0.pop();
			}
			else {
				ops.push_back({0, 1, 0, 0});
				q1.pop();
			}
		}
	}
	vector<string> IG(M, "");
	for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) IG[i] += G[j][i];
	for(int i = 2; i < M; i++) for(int j = (int)IG[i].length()-1; j >= 0; j--) {
		if(IG[i][j] == '0') ops.push_back({0, 0, 0, i});
		else ops.push_back({0, 1, 0, i});
	}
	for(int i = 2; i < M; i++) for(int j = N-1; j > 0; j--)
		for(int k = 0; k < (int)G[j][i].length(); k++) ops.push_back({0, i, j, i});
	for(int j = 0; j < 2; j++) for(int k = (int)G[0][j].length()-1; k >= 0; k--) {
		if(G[0][j][k] != '0'+j) ops.push_back({0, 1-j, 0, j});
		else {
			ops.push_back({0, j, 1, j});
			ops.push_back({1, j, 0, j});
		}
	}
	for(int i = 1; i < N; i++) {
		for(int j = 0; j < 2; j++)
			for(int k = (int)G[i][j].length()-1; k >= 0; k--) if(G[i][j][k] != '0'+j)
				ops.push_back({0, 1-j, i, 1-j});
		for(int j = 0; j < 2; j++) for(int k = (int)G[i][j].length()-1; k >= 0; k--) {
			if(G[i][j][k] == '0'+j) ops.push_back({0, j, i, j});
			else ops.push_back({i, 1-j, i, j});
		}
	}
	cout << ops.size() << "\n";
	for(int i = 0; i < (int)ops.size(); i++)
		cout << ops[i].x1+1 << " " << ops[i].y1+1 << " " << ops[i].x2+1 << " " << ops[i].y2+1 << "\n";
	// vector< vector<string> > test = V;
	// ALL_THE(ops, it) {
	// 	assert(test[it->x1][it->y1].length() != 0);
	// 	char c = test[it->x1][it->y1][test[it->x1][it->y1].length()-1];
	// 	test[it->x1][it->y1] = test[it->x1][it->y1].substr(0, test[it->x1][it->y1].length()-1);
	// 	string s = ""; s += c;
	// 	test[it->x2][it->y2] = s + test[it->x2][it->y2];
	// }
	// for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cout << test[i][j] << "\n";
	return 0;
}

// look at my code
// my code is amazing