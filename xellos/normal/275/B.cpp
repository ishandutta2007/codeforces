// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,M;
	scanf(" %d %d",&N,&M);
	vector<string> S(N);
	for(int i =0; i < N; i++) {
		char ch[60];
		scanf(" %s",ch);
		S[i] =(string)ch;}

	int Lb =0, Lx =-1;
	for(int i =0; i < N; i++) {
		int fb =M+1, lb =-1, pb =0;
		for(int j =0; j < M; j++) if(S[i][j] == 'B') {
			pb++;
			fb =min(fb,j);
			lb =max(lb,j);}
		if(fb == M+1) continue;
		if(lb-fb+1 != pb) {printf("NO\n"); return 0;}
		if(pb > Lb) Lb =pb, Lx =i;}
	if(Lx == -1) {printf("YES\n"); return 0;}
	
	for(int i =Lx-1; i >= 0; i--) for(int j =0; j < M; j++) 
		if(S[i][j] == 'B' && S[i+1][j] != 'B') {printf("NO\n"); return 0;}
	for(int i =Lx+1; i < N; i++) for(int j =0; j < M; j++) 
		if(S[i][j] == 'B' && S[i-1][j] != 'B') {printf("NO\n"); return 0;}

	Lb =0, Lx =-1;
	for(int i =0; i < M; i++) {
		int fb =N+1, lb =-1, pb =0;
		for(int j =0; j < N; j++) if(S[j][i] == 'B') {
			pb++;
			fb =min(fb,j);
			lb =max(lb,j);}
		if(fb == N+1) continue;
		if(lb-fb+1 != pb) {printf("NO\n"); return 0;}
		if(pb > Lb) Lb =pb, Lx =i;}
	
	for(int i =Lx-1; i >= 0; i--) for(int j =0; j < N; j++) 
		if(S[j][i] == 'B' && S[j][i+1] != 'B') {printf("NO\n"); return 0;}
	for(int i =Lx+1; i < M; i++) for(int j =0; j < N; j++) 
		if(S[j][i] == 'B' && S[j][i-1] != 'B') {printf("NO\n"); return 0;}

	for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(S[i][j] == 'B')
		for(int k =i; k < N; k++) for(int l =0; l < M; l++) if(S[k][l] == 'B') {
			bool ok =true;
			for(int m =i+1; m < k; m++) if(S[m][j] != 'B') ok =false;
			for(int m =min(j,l); m < max(j,l); m++) if(S[k][m] != 'B') ok =false;
			if(ok) continue;
			ok =true;
			for(int m =i+1; m < k; m++) if(S[m][l] != 'B') ok =false;
			for(int m =min(j,l); m < max(j,l); m++) if(S[i][m] != 'B') ok =false;
			if(!ok) {printf("NO\n"); return 0;}
			}

	printf("YES\n");
	return 0;}

// look at my code
// my code is amazing