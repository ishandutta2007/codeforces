// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 200
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,M,K;
	scanf(" %d %d %d",&N,&M,&K);
	vector< vector<int> > A(N,vector<int>(M,0));
	for(int i =0; i < N*M; i++) scanf(" %d",&A[i/M][i%M]);

	vector< vector<long long> > S(N+M+2*tisic,vector<long long>(N+M+2*tisic,0));
	auto S_diag =S, S_adiag =S;
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
		S[i+j+tisic][i+M-j+tisic] =A[i][j];
		S_diag[i+j+tisic][i+M-j+tisic] =A[i][j];
		S_adiag[i+j+tisic][i+M-j+tisic] =A[i][j];}
	for(int i =1; i < N+M+2*tisic; i++) for(int j =1; j < N+M+2*tisic; j++) {
		S[i][j] +=S[i-1][j]+S[i][j-1]-S[i-1][j-1];
		S_diag[i][j] +=S_diag[i-1][j-1];}
	for(int i =1; i < N+M+2*tisic; i++) for(int j =N+M+2*tisic-2; j >= 0; j--) 
		S_adiag[i][j] +=S_adiag[i-1][j+1];

	int ansx =0, ansy =0;
	long long ansv =-OVER9000;
	for(int i =K+2; i <= N+M+2*tisic-K-2; i++) {
		long long akt =0, akt_tr1 =0, akt_tr2 =0;
		int x =(i+K+2-M)/2-tisic, y =(i-K-2+M)/2;
		if(x >= K-1 && y >= K-1 && x <= N-K && y <= M-K && akt > ansv) ansv =akt, ansx =x, ansy =y;
		for(int j =K+3; j <= N+M+2*tisic-K-2; j++) {
			akt -=akt_tr1;
			akt_tr1 -=S[i+(K-1)][j-K]-S[i-(K-1)-1][j-K]-S[i+(K-1)][j-K-1]+S[i-(K-1)-1][j-K-1];
			akt_tr1 +=S_diag[i][j]-S_diag[i-K][j-K]+S_adiag[i+K-1][j-K+1]-S_adiag[i][j];
			akt_tr2 -=S_diag[i+K-1][j-1+K-1]-S_diag[i-1][j-2]+S_adiag[i-1][j]-S_adiag[i-K][j-1+K];
			akt_tr2 +=S[i+(K-1)][j+K-1]-S[i-(K-1)-1][j+K-1]-S[i+(K-1)][j+K-2]+S[i-(K-1)-1][j+K-2];
			akt +=akt_tr2;
			x =(i+j-M)/2-tisic, y =(i-j+M)/2;
			if(x >= K-1 && y >= K-1 && x <= N-K && y <= M-K && akt > ansv) ansv =akt, ansx =x, ansy =y;}
		}

	printf("%d %d\n",ansx+1,ansy+1);
	return 0;}

// look at my code
// my code is amazing