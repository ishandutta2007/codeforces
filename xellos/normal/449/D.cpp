// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,a,A =(1<<20)-1;
	cin >> N;
	vector< vector<long long> > P(21,vector<long long>(1<<20,0));
	for(int i =0; i < N; i++) {
		cin >> a;
		A =A&a;
		P[20][a]++;}

	for(int i =(1<<20)-1; i > 0; i--) for(int j =0; j <= 20; j++) if(P[j][i] != 0) {
		for(int k =j-1; k >= 0; k--) if((i&(1<<k)) != 0)
			P[k][i^(1<<k)] +=P[j][i];
		}

	long long mod =1000000007;
	vector<long long> pw(1<<20,1);
	for(int i =1; i <= 1000000; i++) pw[i] =(2*pw[i-1])%mod;

	long long ans =0;
	for(int i =0; i <= 1000000; i++) {
		int p =0;
		long long q =0;
		for(int j =0; j <= 20; j++) q +=P[j][i];
//		cout << q<< "\n";
		for(int k =0; k < 20; k++) if((i&(1<<k)) != 0) p++;
		if(q == 0) continue;
		if(p%2 == 0) ans +=pw[q%(mod-1)]-1;
		else ans -=pw[q%(mod-1)]-1;
		if(ans < 0) ans +=mod;
		if(ans >= mod) ans -=mod;}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing