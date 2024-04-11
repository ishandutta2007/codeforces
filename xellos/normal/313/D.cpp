// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 12345678901234567LL
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	int N,M,K;
	cin >> N >> M >> K;

	vector< vector<long long> > C(N, vector<long long> (N+1,OVER9000));
	// cena segmentu [i,j)
	for(int i =0; i < M; i++) {
		int a,b;
		long long c;
		cin >> a >> b >> c;
		C[a-1][b] =min(C[a-1][b],c);}
	
	for(int i =2; i <= N; i++) for(int j =0; j <= N-i; j++) {
		// kolko stoji segment [j,i+j)?
		// vyskladam z [j,k) a [l,i+j); j < l <= k
		long long x =C[j+1][i+j];
		for(int k =j+1; k < i+j; k++) {
			x =min(x,C[k][i+j]);
			C[j][i+j] =min(C[j][i+j],x+C[j][k]);}}
	
	vector< vector<long long> > A(N+1, vector<long long> (N+1,OVER9000));
	A[0][0] =0;
	// z intervalu [0,i) vyberiem j dier, aka je najmensia cena?
	for(int i =0; i < N; i++) for(int j =0; j <= i; j++)
		for(int k =i+1; k <= N; k++) {
			// plny segment [i,k)
			A[k][j+k-i] =min(A[k][j+k-i],A[i][j]+C[i][k]);
			// prazdny segment [i,k)
			A[k][j] =min(A[k][j],A[i][j]);}
	
	long long ans =OVER9000;
	for(int i =0; i <= N; i++) for(int j =K; j <= N; j++) ans =min(ans,A[i][j]);
	if(ans == OVER9000) cout << "-1\n";
	else cout << ans << "\n";
    return 0;}
        
// look at my code
// my code is amazing