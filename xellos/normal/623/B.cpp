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
	int N,x;
	long long A,B;
	cin >> N >> A >> B;
	vector<int> V(N);
	for(int i =0; i < N; i++) cin >> V[i];
	if(N == 1) {cout << "0\n"; return 0;}
	
	vector<int> PD;
	for(int d =-1; d <= 1; d++) {
		x =V[0]+d;
		for(int k =2; k <= 100000; k++) if(x%k == 0) {
			PD.push_back(k);
			while(x%k == 0) x /=k;}
		if(x > 1) PD.push_back(x);
		x =V[N-1]+d;
		for(int k =2; k <= 100000; k++) if(x%k == 0) {
			PD.push_back(k);
			while(x%k == 0) x /=k;}
		if(x > 1) PD.push_back(x);}

	long long ans =A*(N-1);
	for(int k =0; k < (int)PD.size(); k++) if(k == 0 || PD[k] != PD[k-1]) {
		vector<long long> costR(N,0);
		int G =PD[k];

		int mib =N+1, mxb =-1;
		for(int i =0; i < N; i++) {
			if(V[i]%G == 0) continue;
			if((V[i]+1)%G == 0 || (V[i]-1)%G == 0) {costR[i]++; continue;}
			mib =min(mib,i);
			mxb =max(mxb,i);}
		if(mib == 0 && mxb == N-1) continue;

		vector<long long> sum1(N+1,0),sum2(N+1,0);
		for(int i =0; i < N; i++) sum1[i+1] =sum1[i]+costR[i];
		for(int i =N-1; i >= 0; i--) sum2[i] =sum2[i+1]+costR[i];

		if(mxb != -1) {
			long long mc1 =ans, mc2 =ans;
			for(int i =0; i <= mib; i++) mc1 =min(mc1,sum1[i]*B+(mib-i)*A);
			for(int i =mxb+1; i <= N; i++) mc2 =min(mc2,sum2[i]*B+(i-1-mxb)*A);
			ans =min(ans,(mxb-mib+1)*A+mc1+mc2);
			continue;}

		long long aktS =1e18;
//		min sum1[i]+sum2[j]+A*(j-i) = min sum1[i]-A*i + sum2[j]+A*j
		for(int i =N; i > 0; i--) {
			aktS =min(aktS,sum2[i]*B+A*i);
			if(i > 0) ans =min(ans,sum1[i]*B-A*i+aktS);}
		for(int i =N-1; i >= 0; i--) ans =min(ans,sum2[i]*B+A*i);
		}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing