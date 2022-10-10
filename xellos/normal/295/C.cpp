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

typedef unsigned long long ll;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N,K;
	cin >> N >> K;
	K /=50;
	int P[2] ={0,0};
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		P[a/50-1]++;}

	ll mod =1000000007;
	ll C[100][100];
	for(int i =0; i < 100; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) C[i][j] =(C[i-1][j]+C[i-1][j-1])%mod;
		}

	ll A[210][51][51];
	for(int i =0; i < 210; i++) 
		for(int j =0; j <= 50; j++) for(int k =0; k <= 50; k++) A[i][j][k] =0;
	A[0][P[0]][P[1]] =1;
	for(int i =0; i <= 200; i++) {
		for(int j =0; j <= P[0]; j++) for(int d0 =0; d0 <= j; d0++)
			for(int k =0; k <= P[1]; k++) for(int d1 =0; d1 <= k; d1++) if(d0+d1 > 0 && d0+2*d1 <= K) 
				A[i+1][d0+P[0]-j][d1+P[1]-k] =(A[i+1][d0+P[0]-j][d1+P[1]-k]+(A[i][j][k]*C[j][d0])%mod*C[k][d1])%mod;

		if(i%2 == 0 && A[i+1][P[0]][P[1]] != 0) {
			cout << i+1 << "\n" << A[i+1][P[0]][P[1]] << "\n";
			return 0;}
		}

	cout << "-1\n0\n";
	return 0;}

// look at my code
// my code is amazing