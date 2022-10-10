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
#define OVER9000 1234567890123456780LL
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
	K--;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	long long mod =1000000007;
	vector<long long> pw2(N+1,1);
	for(int i =N-1; i >= 0; i--) {
		pw2[i] =(pw2[i+1]*((A[i] == 0)?2:1))%mod;
		if(pw2[i] < 0) pw2[i] +=mod;}
	vector<long long> P(1<<K,0);
	P[0] =1;

	long long ans =0;
	for(int i =0; i < N; i++) {
		vector<long long> Pn(1<<K,0);
		if(A[i] == 2 || A[i] == 0) for(int j =0; j < (1<<K); j++) {
			int k =j+1;
			if(k&(1<<K)) ans =(ans+P[j]*pw2[i+1])%mod;
			else Pn[k] +=P[j];}
		if(A[i] == 4 || A[i] == 0) for(int j =0; j < (1<<K); j++) {
			int k =(j&1)?2:(j+2);
			if(k&(1<<K)) ans =(ans+P[j]*pw2[i+1])%mod;
			else Pn[k] +=P[j];}
		for(int j =0; j < (1<<K); j++) {
			P[j] =Pn[j]%mod;
			if(P[j] < 0) P[j] +=mod;}
		}

	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing