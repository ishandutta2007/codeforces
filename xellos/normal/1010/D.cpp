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
#define soclose 1e-7
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, vector< vector<int> > & G, vector<string> & tp, vector<int> & inp, vector<int> & val) {
	if(tp[R] == "IN") {
		val[R] = inp[R];
		return;
	}
	vector<int> inp_cur;
	ALL_THE(G[R], it) {
		DFS(*it, G, tp, inp, val);
		inp_cur.push_back(val[*it]);
	}
	if(tp[R] == "NOT") val[R] = 1-inp_cur[0];
	if(tp[R] == "XOR") val[R] = (inp_cur[0] ^ inp_cur[1]);
	if(tp[R] == "OR") val[R] = (inp_cur[0] | inp_cur[1]);
	if(tp[R] == "AND") val[R] = (inp_cur[0] & inp_cur[1]);
}

void DFS2(int R, vector< vector<int> > & G, vector<string> & tp, vector<int> & inp, vector<int> & val, vector<int> & res_inv) {
	if(tp[R] == "IN") return;
	vector<int> inp_cur;
	ALL_THE(G[R], it) inp_cur.push_back(val[*it]);
	for(int i = 0; i < (int)G[R].size(); i++) {
		// invert inp[i]
		inp_cur[i] = 1-inp_cur[i];
		int res_cur = val[R];
		if(tp[R] == "NOT") res_cur = 1-inp_cur[0];
		if(tp[R] == "XOR") res_cur = (inp_cur[0] ^ inp_cur[1]);
		if(tp[R] == "OR") res_cur = (inp_cur[0] | inp_cur[1]);
		if(tp[R] == "AND") res_cur = (inp_cur[0] & inp_cur[1]);
		if(res_cur != val[R]) res_inv[G[R][i]] = res_inv[R];
		else res_inv[G[R][i]] = val[0];
		inp_cur[i] = 1-inp_cur[i];
	}
	for(int i = 0; i < (int)G[R].size(); i++) DFS2(G[R][i], G, tp, inp, val, res_inv);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<string> tp(N);
	vector< vector<int> > G(N);
	vector<int> inp(N);
	for(int i = 0; i < N; i++) {
		cin >> tp[i];
		if(tp[i] == "IN") {
			cin >> inp[i];
			continue;
		}
		if(tp[i] == "NOT") G[i].resize(1);
		else G[i].resize(2);
		for(int j = 0; j < (int)G[i].size(); j++) {
			cin >> G[i][j];
			G[i][j]--;
		}
	}
	vector<int> val(N);
	DFS(0, G, tp, inp, val);
	vector<int> res_inv(N);
	res_inv[0] = 1-val[0];
	DFS2(0, G, tp, inp, val, res_inv);
	for(int i = 0; i < N; i++) if(tp[i] == "IN") cout << res_inv[i];
	cout << "\n";
	return 0;
}

// look at my code
// my code is amazing