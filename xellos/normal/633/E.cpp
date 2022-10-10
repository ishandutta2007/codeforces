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
	int K,N;
	cin >> N >> K;
	vector<int> V(N),C(N);
	for(int i =0; i < N; i++) cin >> V[i];
	for(int i =0; i < N; i++) cin >> C[i];

	vector< vector<int> > RMQV(20,vector<int>(N,0));
	vector< vector<int> > RMQC(20,vector<int>(N,10000000));
	RMQV[0] =V;
	RMQC[0] =C;
	for(int i =1; i < 20; i++) for(int j =0; j < N; j++) if(j+(1<<i) <= N) {
		RMQV[i][j] =max(RMQV[i-1][j],RMQV[i-1][j+(1<<(i-1))]);
		RMQC[i][j] =min(RMQC[i-1][j],RMQC[i-1][j+(1<<(i-1))]);}

	vector<int> A(N);
	for(int i =N-1; i >= 0; i--) {
		int x =i+1, maxv =V[i], minc =C[i];
		for(int j =19; j >= 0; j--) if(x+(1<<j) <= N) {
			int maxv_nw =max(RMQV[j][x],maxv);
			int minc_nw =min(RMQC[j][x],minc);
			if(minc_nw < 100*maxv_nw) continue;
			maxv =maxv_nw;
			minc =minc_nw;
//			if(i == 0) cout << x << " " << maxv << " " << minc << "\n";
			x +=1<<j;}
		A[i] =min(100*maxv,minc);
		if(x < N) {
			maxv =max(maxv,V[x]);
			minc =min(minc,C[x]);
			A[i] =max(A[i],min(100*maxv,minc));}
		}	

	sort(begin(A),end(A));
	dbl d =1, ans =0;
	for(int i =0; i < N; i++) {
		ans +=A[i]*d*(1.0*K/(N-i));
		d *=1.0*(N-i-K)/(N-i);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing