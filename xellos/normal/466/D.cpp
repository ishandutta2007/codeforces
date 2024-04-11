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
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,H;
	scanf(" %d %d",&N,&H);
	vector<int> A(N+2,0);
	for(int i =0; i < N; i++) {
		scanf(" %d",&A[i+1]);
		A[i+1] =H-A[i+1];}
	for(int i =1; i <= N+1; i++) if(abs(A[i]-A[i-1]) > 1 || A[i] < 0) {
		printf("0\n");
		return 0;}

	vector<long long> P(N+2,0);
	long long mod =1000000007;
	P[0] =1;
	for(int i =0; i <= N; i++) {
		// jeden zacne
		if(A[i+1] > A[i]) {P[i+1] =P[i]; continue;}
		// jeden skonci
		if(A[i+1] < A[i]) {P[i+1] =(P[i]*A[i])%mod; continue;}
		// nic sa nemeni
		// jeden zacne, jeden skonci
		P[i+1] =(P[i]*(A[i]+1))%mod;}

	if(P[N+1] < 0) P[N+1] +=mod;
	cout << P[N+1] << "\n";
	return 0;}

// look at my code
// my code is amazing