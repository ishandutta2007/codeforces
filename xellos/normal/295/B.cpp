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
	vector< vector<int> > W(N,vector<int>(N));
	for(int i =0; i < N; i++) for(int j =0; j < N; j++) cin >> W[i][j];
	vector<int> X(N);
	for(int i =0; i < N; i++) {cin >> X[i]; X[i]--;}

	vector< vector<int> > D(N,vector<int>(N,OVER9000));
	vector<bool> live(N,false);
	vector<long long> ans(N,0);
	for(int i =N-1; i >= 0; i--) {
		D[X[i]][X[i]] =0;
		live[X[i]] =true;
		for(int j =0; j < N; j++) if(live[j])
			for(int k =0; k < N; k++) if(live[k]) {
				D[X[i]][k] =min(D[X[i]][k],D[j][k]+W[X[i]][j]);
				D[k][X[i]] =min(D[k][X[i]],D[k][j]+W[j][X[i]]);}
		for(int j =0; j < N; j++) if(live[j] && D[j][X[i]] != OVER9000)
			for(int k =0; k < N; k++) if(live[k]) {
				D[j][k] =min(D[j][k],D[j][X[i]]+D[X[i]][k]);
				if(D[j][k] < OVER9000) ans[i] +=D[j][k];}
		}

	for(int i =0; i < N; i++) cout << ans[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing