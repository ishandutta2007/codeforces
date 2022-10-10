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
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,K;
	cin >> N >> K;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	sort(begin(A),end(A));

	long long mod =1000000007;
	vector< vector<long long> > poc(N+2,vector<long long>(K+tisic,0));
	poc[1][0] =poc[0][0] =1;
	for(int i =N-2; i >= 0; i--) {
		vector< vector<long long> > poc_nw(N+2,vector<long long>(K+tisic,0));
		for(int j =0; j <= N; j++) for(int k =0; k <= K-j*(A[i+1]-A[i]); k++) {
			if(j+1 <= N) poc_nw[j+1][k+j*(A[i+1]-A[i])] +=poc[j][k];
			poc_nw[j][k+j*(A[i+1]-A[i])] +=(j+1)*poc[j][k];
			if(j > 0) poc_nw[j-1][k+j*(A[i+1]-A[i])] +=j*poc[j][k];
			}
		for(int j =0; j <= N; j++) for(int k =0; k <= K; k++) {
			poc[j][k] =poc_nw[j][k]%mod;
			if(poc[j][k] < 0) poc[j][k] +=mod;}
		}

	long long ans =0;
	for(int i =0; i <= K; i++) {
		ans +=poc[0][i];
		if(ans >= mod) ans -=mod;}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing