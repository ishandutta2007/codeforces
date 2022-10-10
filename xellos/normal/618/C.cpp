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

struct pt {
	long long x,y;
};

long long vs(pt &A, pt &B, pt &O) {
	return (A.x-O.x)*(B.y-O.y)-(B.x-O.x)*(A.y-O.y);}

long long sig(long long a) {
	if(a == 0) return 0;
	if(a > 0) return 1;
	return -1;}

bool ins(pt &A, pt &B, pt &C, pt &P) {
	if(sig(vs(A,B,C))*sig(vs(P,B,C)) < 0) return false;
	if(sig(vs(B,A,C))*sig(vs(P,A,C)) < 0) return false;
	if(sig(vs(C,B,A))*sig(vs(P,B,A)) < 0) return false;
	return true;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<pt> V(N);
	for(int i =0; i < N; i++) cin >> V[i].x >> V[i].y;
	int W[3];
	W[0] =0;
	W[1] =1;
	W[2] =2;
	for(int i =0; i < N; i++) if(vs(V[W[0]],V[W[1]],V[i]) != 0) W[2] =i;

	while(true) {
		int vin =-1;
		for(int i =0; i < N; i++) if(ins(V[W[0]],V[W[1]],V[W[2]],V[i]) && i != W[0] && i != W[1] && i != W[2]) {
			vin =i;
			break;}
		if(vin == -1) break;
		long long S =abs(vs(V[W[0]],V[W[1]],V[W[2]]));
		if(vs(V[vin],V[W[1]],V[W[2]]) != 0 && abs(vs(V[vin],V[W[1]],V[W[2]]))*2 <= S) {
			W[0] =vin;
			continue;}
		if(vs(V[W[0]],V[vin],V[W[2]]) != 0 && abs(vs(V[W[0]],V[vin],V[W[2]]))*2 <= S) {
			W[1] =vin;
			continue;}
		W[2] =vin;}

	cout << W[0]+1 << " " << W[1]+1 << " " << W[2]+1 << "\n";
	return 0;}

// look at my code
// my code is amazing