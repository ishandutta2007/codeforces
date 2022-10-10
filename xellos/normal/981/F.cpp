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

bool check(int L, auto A, auto B, int d) {
	int N = A.size();
	int l = 0, r = 0;
	vector<int> lp(N), rp(N);
	while(l > -N && B[0]+L-A[N-1+l] <= d) l--;
	for(int i = 0; i < N; i++) {
		while(A[r%N]+1LL*(r/N)*L <= B[i]+d) r++;
		while(l < 0 && L-A[N+l]+B[i] > d) l++;
		while(l >= 0 && l < N && B[i]-A[l] > d) l++;
		lp[i] = l;
		rp[i] = r;
		if(l >= r) return false;
	}
	vector<int> pair(N);
	for(int i = 0; i < N; i++) {
		pair[i] = lp[i];
		if(i > 0 && pair[i] <= pair[i-1]) {
			pair[i] = pair[i-1]+1;
			if(pair[i] >= rp[i]) return false;
		}
	}
	while(true) {
		int p0 = (pair[0]+5*N)%N;
		int pl = (pair[N-1]+5*N)%N;
		bool ord = true;
		for(int i = 1; i < N; i++) {
			int px = (pair[i-1]+5*N)%N, py = (pair[i]+5*N)%N;
			if(px >= py) ord = false;
		}
		if(ord) break;
		if(pair[0] < 0 && pair[N-1] >= N) pair[0] = 0;
		else {
			if(pl < p0) break;
			pair[0] = pl+1;
			while(pair[0] < lp[0]) pair[0] += N;
			while(pair[0]-N >= lp[0]) pair[0] -= N;
		}
		if(pair[0] >= rp[0]) return false;
		for(int i = 1; i < N; i++) {
			pair[i] = lp[i];
			if(i > 0 && pair[i] <= pair[i-1]) {
				pair[i] = pair[i-1]+1;
				if(pair[i] >= rp[i]) return false;
			}
		}
	}
	vector<int> used(N);
	for(int i = 0; i < N; i++) used[(pair[i]+5*N)%N]++;
	// cout << d << ":";
	// for(int i = 0; i < N; i++) cout << " " << (pair[i]+N)%N;
	// cout << endl;
	for(int i = 0; i < N; i++) if(used[i] > 1) return false;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, L;
	cin >> N >> L;
	vector<int> A(N), B(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	for(int i = 0; i < N; i++) cin >> B[i];
	sort(begin(A), end(A));
	sort(begin(B), end(B));
	// for(int i = 0; i < N; i++) cout << A[i] << "  ";
	// cout << endl;
	// for(int i = 0; i < N; i++) cout << B[i] << "  ";
	// cout << endl;
	int mind = -1, maxd = (L+1)/2;
	while(maxd-mind > 1) {
		int curd = (mind+maxd) / 2;
		if(check(L, A, B, curd)) maxd = curd;
		else mind = curd;
	}
	cout << maxd << "\n";
	return 0;}

// look at my code
// my code is amazing