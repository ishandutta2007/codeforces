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
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	long long C[8][3];
	for(int i =0; i < 8*3; i++) cin >> C[i/3][i%3];
	long long P[6][3] ={
		{0,1,2},
		{0,2,1},
		{1,0,2},
		{1,2,0},
		{2,0,1},
		{2,1,0}};

	long long Cs[8][3];
	for(int k =0; k < 279936; k++) {
		for(int i =0; i < 3; i++) Cs[0][i] =C[0][i];
		int x =k;
		for(int j =1; j < 8; j++) {
			for(int i =0; i < 3; i++) Cs[j][i] =C[j][P[x%6][i]];
			x /=6;}

		vector<long long> D(7,0);
		for(int j =1; j < 8; j++) for(int i =0; i < 3; i++)
			D[j-1] +=(Cs[0][i]-Cs[j][i])*(Cs[0][i]-Cs[j][i]);
		long long a =1000000000000000LL;
		for(int i =0; i < 7; i++) a =min(a,D[i]);
		int t =0,s =0,q =0;
		for(int i =0; i < 7; i++) {
			if(D[i] == a) t++;
			if(D[i] == 2*a) s++;
			if(D[i] == 3*a) q++;}
		if(a == 0 || t != 3 || s != 3 || q != 1) continue;

		bool ok =true;
		for(int i =1; i < 8; i++) if(ok) {
			s =t =q =0;
			for(int j =0; j < 8; j++) if(i != j) {
				long long d =0;
				for(int l =0; l < 3; l++) d +=(Cs[i][l]-Cs[j][l])*(Cs[i][l]-Cs[j][l]);
				if(d == a) s++;
				if(d == 2*a) t++;
				if(d == 3*a) q++;}
			if(s != 3 || t != 3 || q != 1) ok =false;}
		if(!ok) continue;

		cout << "YES\n";
		for(int i =0; i < 8; i++) for(int j =0; j < 3; j++)
			cout << Cs[i][j] << ((j == 2)?"\n":" ");
		return 0;}

	cout << "NO\n";
	return 0;}

// look at my code
// my code is amazing