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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< pair<int, int> > A(N);
	cat sum = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i].ff;
		sum += A[i].ff;
		A[i].ss = i;
	}
	sort(begin(A), end(A));
	int V = A.back().ff;
	vector< vector<int> > E(N);
	vector<int> V_seq;
	for(int i = 0; i < A.back().ff; i++) {
		V_seq.push_back(i);
		E[A.back().ss].push_back(i);
	}
	A.pop_back();
	vector<int> sums(N, 0);
	for(int i = 1; i < N; i++) sums[i] = sums[i-1] + A[i-1].ff-2;
	while(!A.empty()) {
		if((int)V_seq.size()-2 == sums[A.size()]) {
			int cur = 1;
			for(int i = 0; i < (int)A.size(); i++) {
				E[A[i].ss].push_back(V);
				E[A[i].ss].push_back(V_seq[cur]);
				for(int j = 0; j < A[i].ff-2; j++) {
					cur++;
					E[A[i].ss].push_back(V_seq[cur]);
				}
			}
			V++;
			A.clear();
			break;
		}
		if((int)V_seq.size()-2 == sums[A.size()]-1) {
			int cur = 0;
			for(int i = 0; i < (int)A.size(); i++) {
				E[A[i].ss].push_back(V);
				E[A[i].ss].push_back(V_seq[cur]);
				for(int j = 0; j < A[i].ff-2; j++) {
					cur++;
					E[A[i].ss].push_back(V_seq[cur]);
				}
			}
			V++;
			A.clear();
			break;
		}
		int min_val = (int)V_seq.size() - A.back().ff + 2;
		if(min_val == 2) min_val = 4;
		if(A.size() > 1 && min_val < A[A.size()-2].ff)
			while(min_val < A[A.size()-2].ff) min_val += 2;
		if(min_val == (int)V_seq.size() - A.back().ff + 2 && (int)V_seq.size() <= sums[A.size()]) min_val += 2;
		int id = A.back().ss;
		int rm_e = (V_seq.size()+A.back().ff-min_val) / 2;
		int last_v = V_seq.back();
		for(int i = 0; i <= rm_e; i++) {
			E[id].push_back(V_seq.back());
			if(i < rm_e) V_seq.pop_back();
		}
		for(int i = 0; i < A.back().ff-rm_e-1; i++) {
			E[id].push_back(V);
			V_seq.push_back(V++);
		}
		V_seq.push_back(last_v);
		A.pop_back();
	}
	cout << V << "\n";
	for(int i = 0; i < N; i++)
		for(int j = 0; j < (int)E[i].size(); j++)
			cout << E[i][j]+1 << ((j+1 == (int)E[i].size()) ? "\n" : " ");
	cerr << (N+V-1)*2-sum << "\n";
	return 0;
}

// look at my code
// my code is amazing