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
	int N,M,Q;
	cin >> N >> M >> Q;
	vector< vector<int> > A(N,vector<int>(M));
	for(int i =0; i < N*M; i++) cin >> A[i/M][i%M];

	vector<int> sc(N,0);
	for(int i =0; i < N; i++) {
		int x =0;
		for(int j =0; j < M; j++) {
			if(A[i][j] == 0) x =0;
			else x++;
			sc[i] =max(sc[i],x);}
		}

	for(int q =0; q < Q; q++) {
		int r,c;
		cin >> r >> c;
		r--, c--;
		A[r][c] =1-A[r][c];
		int x =0;
		sc[r] =0;
		for(int j =0; j < M; j++) {
			if(A[r][j] == 0) x =0;
			else x++;
			sc[r] =max(sc[r],x);}
		int ans =0;
		for(int i =0; i < N; i++) ans =max(ans,sc[i]);
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing