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

int solve(vector<int> &A, vector<int> &res) {
	bool skip = true, done = true;
	int N = A.size();
	for(int i = 0; i < N; i++) {
		if(A[i]&1) skip = false;
		if(A[i]) done = false;
	}
	if(done) return 0;
	if(skip) {
		for(int i = 0; i < N; i++) A[i] /= 2;
		vector<int> optres;
		int ret = solve(A, optres);
		ALL_THE(optres, it) res.push_back((*it)*2);
		return ret;
	}
	int ret = 100;
	vector<int> optres, curres;
	vector<int> A_nw;
	for(int k = 0; k < 20; k++) {
		A_nw.clear();
		bool fail = false;
		int mind = 0, maxd = 0;
		for(int i = 0; i < N; i++) {
			int al = (A[i]>>(k+2))<<(k+2);
			int ar = (al < A[i]) ? (al + (1<<(k+2))) : (al - (1<<(k+2)));
			if(al > ar) swap(al, ar);
			// 0..k pouzijem, k+1 nepouzijem, musi byt delitelne k+2
			if(A[i]-al <= (1<<(k+1))-1) {
				mind = min(mind, al-A[i]);
				if(al != 0) A_nw.push_back(al/(1<<(k+1)));
			}
			if(ar-A[i] <= (1<<(k+1))-1) {
				maxd = max(maxd, ar-A[i]);
				if(ar != 0) A_nw.push_back(ar/(1<<(k+1)));
			}
			if(2*A[i] == al+ar) {
				fail = true;
				break;
			}
		}
		if(fail || maxd-mind >= (1<<(k+1))) continue;
		sort(begin(A_nw), end(A_nw));
		A_nw.resize(unique(begin(A_nw), end(A_nw)) - begin(A_nw));
		curres.clear();
		int curret = k+1 + solve(A_nw, curres);
		ALL_THE(curres, it) *it *= 1<<(k+1);
		for(int i = k; i >= 0; i--) {
			if(maxd >= (1<<i)) {
				curres.push_back(-(1<<i));
				maxd -= 1<<i;
			}
			else {
				curres.push_back(1<<i);
				mind += 1<<i;
			}
		}
		if(curret < ret) {
			ret = curret;
			optres = curres;
			break;
		}
	}
	ALL_THE(optres, it) res.push_back(*it);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N), res;
	for(int i = 0; i < N; i++) cin >> A[i];
	cout << solve(A, res) << "\n";
	for(int i = 0; i < (int)res.size(); i++) cout << res[i] << ((i == (int)res.size()-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing