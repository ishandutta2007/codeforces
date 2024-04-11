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
	int N,M;
	string P;
	cin >> N >> M >> P;
	vector<int> X(M);
	for(int i =0; i < M; i++) {
		cin >> X[i];
		X[i]--;}

	int n =P.length();
	vector<int> prev(n+1,0);
	for(int i =2; i <= n; i++) {
		prev[i] =prev[i-1];
		while(prev[i] > 0 && P[prev[i]] != P[i-1]) prev[i] =prev[prev[i]];
		if(P[prev[i]] == P[i-1]) prev[i]++;}

	vector<bool> inters(n+1,false);
	int akt =prev[n];
	while(akt > 0) {
		inters[akt] =true;
		akt =prev[akt];}

	int e =(M == 0)?N:(X[0]+N-n-X[M-1]);
	long long ans =1;
	for(int i =1; i < M; i++) {
		if(X[i] >= n+X[i-1]) e +=X[i]-n-X[i-1];
		else if(!inters[X[i-1]+n-X[i]]) ans =0;}

	long long mod =1000000007;
	for(int i =0; i < e; i++) ans =(ans*26)%mod;
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing