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
	int M;
	cin >> M;

	vector< vector<int> > C(20,vector<int>(20,0));
	for(int i =0; i < 20; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) C[i][j] =C[i-1][j-1]+C[i-1][j];}
	vector<int> pw2(20,1), pw8(20,1);
	for(int i =1; i < 20; i++) pw2[i] =2*pw2[i-1], pw8[i] =8*pw8[i-1];
	vector<int> P(10,0);
	int p =0;
	for(int i =10; i >= 0; i--) {
		int d =M;
		for(int j =0; j < i; j++) d /=10;
		d %=10;
		for(int k =0; k < d; k++)
			for(int j =0; j <= i; j++) P[p+j+((k == 4 || k == 7)?1:0)] +=C[i][j]*pw2[j]*pw8[i-j];
		if(d == 4 || d == 7) p++;}
	P[p]++;
	P[0]--;

	long long ans =0, mod =1000000007;
	for(int a =0; a <= 9; a++) for(int b =0; b < a; b++) for(int c =0; c < a; c++) if(b+c < a)
		for(int d =0; d < a; d++) for(int e =0; e < a; e++) if(b+c+d+e < a)
			for(int f =0; f < a; f++) for(int g =0; g < a; g++) if(b+c+d+e+f+g < a) {
				vector<int> X(10,0);
				X[a]++, X[b]++, X[c]++, X[d]++, X[e]++, X[f]++, X[g]++;
				long long akt =1;
				for(int i =0; i < 10; i++) 
					for(int x =P[i]; x > P[i]-X[i]; x--) {
						akt =(akt*x)%mod;
						if(akt < 0) akt +=mod;}
				ans =(ans+akt)%mod;}

	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing