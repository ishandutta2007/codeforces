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
	vector<long long> A(N);
	long long X0 =0;
	for(int i =0; i < N; i++) {
		long long a,b;
		cin >> a >> b;
		A[i] =a^b;
		X0 =X0^a;}

	vector< vector<int> > M(70,vector<int>(N,0));
	vector<int> V(70,0);
	for(int i =0; i < 70; i++) {
		V[i] =X0&1LL;
		X0 /=2;}
	for(int i =0; i < N; i++) for(int j =0; j < 70; j++) {
		M[j][i] =A[i]&1LL;
		A[i] /=2;}

	int a =0;
	vector<int> piv(70,-1);
	for(int i =0; i < N; i++) {
		int x =-1;
		for(int j =a; j < 70; j++) if(M[j][i] != 0) x =j;
		if(x == -1) continue;
		swap(V[x],V[a]);
		swap(M[x],M[a]);
		piv[a] =i;
		for(int j =0; j < 70; j++) if(j != a && M[j][i] != 0) {
			for(int k =0; k < N; k++) M[j][k] ^=M[a][k];
			V[j] ^=V[a];}
		a++;}

	long long ansp =0;
	bool pos =true;
	for(int i =0; i < 70; i++) {
		if(piv[i] != -1) ansp++;
		else if(V[i] != 0) pos =false;}
	if(!pos) cout << "1/1\n";
	else if(ansp == 0) cout << "0/1\n";
	else cout << (1LL<<ansp)-1 << "/" << (1LL<<ansp) << "\n";
	return 0;}

// look at my code
// my code is amazing