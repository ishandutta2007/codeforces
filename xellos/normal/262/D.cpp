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
#define tisic 47
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
	int N,P;
	scanf(" %d",&N);
	vector<int> A(N);
	for(int i =0; i < N; i++) scanf(" %d",&A[i]);
	scanf(" %d",&P);
	
	int s =0;
	for(int i =0; i < N; i++) s +=A[i];
	if(s <= P) {printf("%.10f\n",1.0*N); return 0;}

	vector< vector<dbl> > C(N+1,vector<dbl>(N+1,0));
	for(int i =0; i <= N; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) C[i][j] =C[i-1][j]+C[i-1][j-1];}

	dbl ans =0;
	for(int i =0; i < N; i++) {
		vector< vector<long long> > poc(P+1,vector<long long>(N+1,0));
		poc[0][0] =1;
		for(int j =0; j < N; j++) if(j != i)
			for(int k =P-A[j]; k >= 0; k--) for(int l =0; l < N; l++)
				poc[k+A[j]][l+1] +=poc[k][l];
		for(int j =0; j < N; j++) for(int k =max(0,P-A[i]+1); k <= P; k++) 
			ans +=1.0*j/N*poc[k][j]/C[N-1][j];
		}
	printf("%.10f\n",ans);
	return 0;}

// look at my code
// my code is amazing