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
#define soclose 1e-10
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

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N),B(N);
	for(int i =0; i < N; i++) cin >> A[i];
	for(int i =0; i < N; i++) cin >> B[i];

	if(N <= 00) {
		vector< vector<int> > akoA(N+1,vector<int>(N*N+1,-1));
		akoA[0][0] =0;
		for(int i =0; i < N; i++) {
			for(int j =0; j <= N*N; j++) if(akoA[i][j] != -1) akoA[i+1][j] =-2;
			for(int j =0; j <= N*N-A[i]; j++) if(akoA[i][j] != -1) akoA[i+1][j+A[i]] =j;}
		vector< vector<int> > akoB(N+1,vector<int>(N*N+1,-1));
		akoB[0][0] =0;
		for(int i =0; i < N; i++) {
			for(int j =0; j <= N*N; j++) if(akoB[i][j] != -1) akoB[i+1][j] =-2;
			for(int j =0; j <= N*N-B[i]; j++) if(akoB[i][j] != -1) akoB[i+1][j+B[i]] =j;}
		int akt =-1;
		for(int i =1; i <= N*N; i++) if(akoA[N][i] != -1 && akoB[N][i] != -1) akt =i;
		if(akt == -1) {cout << "-1\n"; return 0;}
		vector<int> sA,sB;
		int akt0 =akt;
		for(int i =N; i > 0; i--) {
			if(akoA[i][akt] == -2) continue;
			sA.push_back(i);
			akt =akoA[i][akt];}
		akt =akt0;
		for(int i =N; i > 0; i--) {
			if(akoB[i][akt] == -2) continue;
			sB.push_back(i);
			akt =akoB[i][akt];}
		cout << sA.size() << "\n";
		for(int i =0; i < (int)sA.size(); i++) cout << sA[i] << ((i == sA.size()-1)?"\n":" ");
		cout << sB.size() << "\n";
		for(int i =0; i < (int)sB.size(); i++) cout << sB[i] << ((i == sB.size()-1)?"\n":" ");
		return 0;}

	vector< vector<int> > dif(2*N+tisic);
	for(int i =0; i < N; i++) dif[A[i]-B[i]+N].push_back(i);
	for(int i =0; i < N; i++) if(!dif[N+i].empty() && !dif[N-i].empty()) {
		if(i == 0) {
			cout << "1\n" << dif[N][0]+1 << "\n1\n" << dif[N][0]+1 << "\n";
			return 0;}
		cout << "2\n" << dif[N+i][0]+1 << " " << dif[N-i][0]+1 << "\n";
		cout << "2\n" << dif[N+i][0]+1 << " " << dif[N-i][0]+1 << "\n";
		return 0;}

	vector<int> ord,sums(1,0);
	int sum =0;
	for(int i =0; i < N; i++) {
		int tp =1;
		if(sum <= 0) {
			sum +=A[i];
			ord.push_back(i+1);}
		else {
			tp =-1;
			sum -=B[i];
			ord.push_back(-i-1);}
		sums.push_back(sum);
		if(tp == 1 && sum-B[i] >= -N) {
			sum -=B[i];
			sums.push_back(sum);
			ord.push_back(-i-1);}
		if(tp == -1 && sum+A[i] <= N) {
			sum +=A[i];
			sums.push_back(sum);
			ord.push_back(i+1);}
		}
	vector<int> buc(2*N+tisic,-1);
	buc[N] =0;
	for(int i =0; i < (int)ord.size(); i++) {
		if(buc[sums[i+1]+N] == -1) {
			buc[sums[i+1]+N] =i+1;
			continue;}
		vector<int> fA,fB;
		for(int j =buc[sums[i+1]+N]; j <= i; j++) {
			if(ord[j] > 0) fA.push_back(ord[j]);
			else fB.push_back(-ord[j]);}
		cout << fA.size() << "\n";
		for(int j =0; j < (int)fA.size(); j++) cout << fA[j] << ((j == (int)fA.size()-1)?"\n":" ");
		cout << fB.size() << "\n";
		for(int j =0; j < (int)fB.size(); j++) cout << fB[j] << ((j == (int)fB.size()-1)?"\n":" ");
		return 0;}

	cout << "-1\n";
	return 0;}

// look at my code
// my code is amazing