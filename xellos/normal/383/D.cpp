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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];

	long long mod =1000000007;
	vector<long long> P(20000+patkan,0);
	long long ans =0;
	for(int i =0; i < N; i++) {
		vector<long long> Pn =P;
		ans =(ans+Pn[10000])%mod;
		for(int j =0; j <= 20000; j++) P[j] =0;
		for(int j =0; j <= 20000; j++) {
			if(j+A[i] <= 20000) P[j+A[i]] +=Pn[j];
			if(j-A[i] >= 0) P[j-A[i]] +=Pn[j];}
		P[10000+A[i]]++;
		P[10000-A[i]]++;
		for(int j =0; j <= 20000; j++) P[j] %=mod;}
	ans =(ans+P[10000])%mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing