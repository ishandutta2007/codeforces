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
	int N,D;
	cin >> N >> D;
	vector<int> A(N,0),X(N),Y(N);
	for(int i =1; i < N-1; i++) cin >> A[i];
	for(int i =0; i < N; i++) cin >> X[i] >> Y[i];

	int tA =-1, tB =100000000;
	while(tB-tA > 1) {
		int t =(tB+tA)/2;
		vector<int> maxT(N,-1);
		maxT[0] =t;
		vector<bool> used(N,false);
		bool win =true;
		for(int i =0; i < N; i++) {
			int x =-1, s =0;
			for(int j =0; j < N; j++) 
				if(maxT[j] >= 0 && !used[j] && maxT[j] >= s) x =j, s =maxT[j];
			if(x == -1) {win =false; break;}
			used[x] =true;
			for(int j =0; j < N; j++) if(j != x) 
				maxT[j] =max(maxT[j],maxT[x]+A[j]-D*abs(X[j]-X[x])-D*abs(Y[j]-Y[x]));
			if(x == N-1) break;}
		if(win) tB =t;
		else tA =t;}

	cout << tB << "\n";
	return 0;}

// look at my code
// my code is amazing