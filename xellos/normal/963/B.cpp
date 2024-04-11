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

void DFS(int R, int par, vector< vector<int> > &G, vector<int> * pos, vector<int> * ako) {
	int p = 0;
	int cnt[3] = {0, 0};
	bool fail = false;
	ALL_THE(G[R], it) if(*it != par) {
		DFS(*it, R, G, pos, ako);
		p ^= 1;
		if(pos[0][*it]^pos[1][*it]) {
			if(pos[0][*it]) cnt[0]++;
			if(pos[1][*it]) cnt[1]++;
		}
		else if(pos[0][*it] && pos[1][*it]) cnt[2]++;
		else fail = true;
	}
	if(fail) return;
	ALL_THE(G[R], it) if(*it != par)
		if(pos[0][*it]^pos[1][*it]) {
			if(pos[0][*it]) ako[0][*it] = ako[1][*it] = 0;
			else ako[0][*it] = ako[1][*it] = 1;
		}
	if(cnt[2]) {
		pos[0][R] = pos[1][R] = 1;
		ALL_THE(G[R], it) if(*it != par)
			if(pos[0][*it] && pos[1][*it]) {
				if(cnt[1]&1) ako[1][*it] = 1, ako[0][*it] = 0, cnt[1]--;
				else ako[1][*it] = 0, ako[0][*it] = 1;
			}
		return;
	}
	if(cnt[1]&1) pos[0][R] = 1;
	else pos[1][R] = 1;
}

void const_seq(int R, int st, int par, vector< vector<int> > &G, vector<int> * pos, vector<int> * ako, vector<int> &seq) {
	ALL_THE(G[R], it) if(*it != par)
		if(ako[st][*it] == 0) const_seq(*it, 1, R, G, pos, ako, seq);
	seq.push_back(R);
	ALL_THE(G[R], it) if(*it != par)
		if(ako[st][*it] == 1) const_seq(*it, 0, R, G, pos, ako, seq);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if(p == 0) continue;
		G[--p].push_back(i);
		G[i].push_back(p);
	}
	vector<int> pos[2], ako[2];
	for(int i = 0; i < 2; i++) {
		pos[i].resize(N, 0);
		ako[i].resize(N, -1);
	}
	DFS(0, 0, G, pos, ako);
	if(pos[1][0] == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	vector<int> seq;
	const_seq(0, 1, 0, G, pos, ako, seq);
	for(int i = 0; i < N; i++) cout << seq[i]+1 << "\n";
	return 0;}

// look at my code
// my code is amazing