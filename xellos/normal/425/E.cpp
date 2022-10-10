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
#define dibs reserve
#define OVER9000 1234567890LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	long long mod =1000000007;
	vector<long long> p2(1000000,1);
	for(int i =1; i < 1000000; i++) {
		p2[i] =p2[i-1]*2;
		if(p2[i] >= mod) p2[i] -=mod;}
	vector< vector<long long> > A(K+1,vector<long long>(N+1,0));

	for(int i =0; i <= N; i++) A[0][i] =1;
	for(int k =1; k <= K; k++) for(int i =1; i <= N; i++) for(int j =1; j <= i; j++) {
		long long p =(p2[(i-j)*j]*(p2[j]-1))%mod;
		if(p < 0) p +=mod;
		A[k][i] =(A[k][i]+A[k-1][i-j]*p)%mod;
		if(A[k][i] < 0) A[k][i] +=mod;}

	cout << A[K][N] << "\n";
	return 0;}

// look at my code
// my code is amazing