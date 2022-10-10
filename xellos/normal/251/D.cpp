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
#define soclose 1e-5
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
	int N;
	scanf(" %d",&N);
	vector<long long> V(N);
	vector<int> poc(60,0);
	for(int i =0; i < N; i++) {
		scanf(" %I64d",&V[i]);
		for(int j =0; j < 60; j++) poc[j] +=(V[i]>>j)&1;}

	vector< vector<int> > C;
	vector<int> val,piv;
	int R =0;
	for(int i =59; i >= 0; i--) if(poc[i]%2 == 0) {
		val.push_back(1);
		C.push_back(vector<int>(N,0));
		R++;
		for(int j =0; j < N; j++) C[R-1][j] =(V[j]>>i)&1;
		// GEM
		for(int j =0; j < R-1; j++) if(piv[j] != -1 && C[R-1][piv[j]]) {
			for(int k =0; k < N; k++) C[R-1][k] ^=C[j][k];
			val[R-1] ^=val[j];}
		piv.push_back(-1);
		for(int j =0; j < N; j++) if(C[R-1][j]) {
			piv[R-1] =j;
			for(int k =0; k < R-1; k++) if(C[k][j]) {
				for(int l =0; l < N; l++) C[k][l] ^=C[R-1][l];
				val[k] ^=val[R-1];}
			break;}
		if(piv[R-1] == -1 && val[R-1] == 1) {
			C.pop_back();
			val.pop_back();
			piv.pop_back();
			R--;}
		}

	for(int i =59; i >= 0; i--) if(poc[i]%2 != 0) {
		val.push_back(1);
		C.push_back(vector<int>(N,0));
		R++;
		for(int j =0; j < N; j++) C[R-1][j] =(V[j]>>i)&1;
		// GEM
		for(int j =0; j < R-1; j++) if(piv[j] != -1 && C[R-1][piv[j]]) {
			for(int k =0; k < N; k++) C[R-1][k] ^=C[j][k];
			val[R-1] ^=val[j];}
		piv.push_back(-1);
		for(int j =0; j < N; j++) if(C[R-1][j]) {
			piv[R-1] =j;
			for(int k =0; k < R-1; k++) if(C[k][j]) {
				for(int l =0; l < N; l++) C[k][l] ^=C[R-1][l];
				val[k] ^=val[R-1];}
			break;}
		if(piv[R-1] == -1 && val[R-1] == 1) {
			C.pop_back();
			val.pop_back();
			piv.pop_back();
			R--;}
		}

	vector<int> ans(N,-1);
	for(int i =0; i < R; i++) if(piv[i] != -1) {
		for(int j =0; j < N; j++) if(ans[j] == -1 && piv[i] != j && C[i][j]) ans[j] =0;
		ans[piv[i]] =val[i];}
	for(int i =0; i < N; i++) if(ans[i] == -1) ans[i] =0;
	for(int i =0; i < N; i++) printf("%d ",ans[i]+1);
	printf("\n");
	return 0;}

// look at my code
// my code is amazing