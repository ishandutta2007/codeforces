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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> P(2*N), occ(N);
	for(int i = 0; i < N; i++) {
		cin >> P[i];
		P[i]--;
		occ[P[i]] = i;
		P[i+N] = P[i];
	}

	vector<int> prev(2*N), next(2*N);
	stack< pair<int, int> > st;
	for(int i = 0; i < 2*N; i++) {
		while(!st.empty() && st.top().ff >= P[i]) st.pop();
		if(st.empty()) prev[i] = -1;
		else prev[i] = st.top().ss;
		st.push({P[i], i});
	}
	while(!st.empty()) st.pop();
	for(int i = 2*N-1; i >= 0; i--) {
		while(!st.empty() && st.top().ff >= P[i]) st.pop();
		if(st.empty()) next[i] = 2*N;
		else next[i] = st.top().ss;
		st.push({P[i], i});
	}

	vector<int> dep0L(2*N, 0), dep0R(2*N, 0);
	vector<int> min0L(2*N, -1), min0R(2*N, -1);
	for(int i = N-1; i >= 0; i--) for(int k = 0; k < 2; k++) {
		int c = occ[i]+k*N;
		int p = prev[c], n = next[c];
		if(p == -1 || n == 2*N) continue;
		int d = max(dep0L[c], dep0R[c]);
		if(next[p] == n) {
			min0R[p] = c;
			dep0R[p] = d+1;
		}
		if(prev[n] == p) {
			min0L[n] = c;
			dep0L[n] = d+1;
		}
	}

	vector<int> minL(2*N, -1), minR(2*N, -1);
	for(int i = N-1; i >= 0; i--) for(int k = 0; k < 2; k++) {
		int c = occ[i]+k*N;
		int p = prev[c], n = next[c];
		if(p != -1) minR[p] = c;
		if(n != 2*N) minL[n] = c;
	}

	vector<int> depL(2*N), depR(2*N), dL(2*N, 0), dR(2*N, 0);
	for(int i = 0; i < 2*N; i++) if(prev[i] != -1) {
		int p = prev[i], n = next[i];
		dL[i] = dL[p]+1;
		depL[i] = max(dep0L[i]+dL[i], depL[p]);
	}
	for(int i = 2*N-1; i >= 0; i--) if(next[i] != 2*N) {
		int p = prev[i], n = next[i];
		dR[i] = dR[n]+1;
		depR[i] = max(dep0R[i]+dR[i], depR[n]);
	}

	int opt_dep = N, opt_shift = 0;
	for(int i = 0; i < N; i++) {
		int l = i, r = i+N-1, dep = N;
		if(P[l] == 0) dep = depL[r];
		else if(P[r] == 0) dep = depR[l];
		else dep = max(depR[l], depL[r]);
		if(dep < opt_dep) {
			opt_dep = dep;
			opt_shift = i;
		}
	}
	cout << opt_dep+1 << " " << opt_shift << "\n";
	return 0;
}

// look at my code
// my code is amazing