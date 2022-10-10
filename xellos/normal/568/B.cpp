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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;

	long long mod =1000000007;
	vector< vector<long long> > C(N+1,vector<long long>(N+1,0));
	for(int i =0; i <= N; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) {
			C[i][j] =C[i-1][j]+C[i-1][j-1];
			if(C[i][j] >= mod) C[i][j] -=mod;}
		}

	vector<long long> eq(N+1,0), eq_chudak(N+1,0);
	eq[0] =eq_chudak[0] =1;
	for(int i =1; i <= N; i++) {
		for(int j =0; j < i; j++) eq[i] =(eq[i]+eq[j]*C[i-1][j])%mod;
		for(int j =0; j < i-1; j++) eq_chudak[i] =(eq_chudak[i]+eq_chudak[j]*C[i-1][j])%mod;
		eq_chudak[i] =(eq_chudak[i]+eq_chudak[i-1]*2)%mod;
		if(eq[i] < 0) eq[i] +=mod;
		if(eq_chudak[i] < 0) eq_chudak[i] +=mod;}

	long long ans =(eq_chudak[N]-eq[N])%mod;
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing