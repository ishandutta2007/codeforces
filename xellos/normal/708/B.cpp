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
	int A[2][2];
	cin >> A[0][0] >> A[0][1];
	cin >> A[1][0] >> A[1][1];
	int p0 =1, p1 =1;
	while(p0*(p0-1)/2 < A[0][0]) p0++;
	while(p1*(p1-1)/2 < A[1][1]) p1++;

	if(A[1][0]+A[0][1] == 0) {
		if(p0*(p0-1)/2 == A[0][0] && A[1][1] == 0) {
			for(int i =0; i < p0; i++) cout << "0";
			cout << "\n";
			return 0;}
		if(p1*(p1-1)/2 == A[1][1] && A[0][0] == 0) {
			for(int i =0; i < p1; i++) cout << "1";
			cout << "\n";
			return 0;}
		cout << "Impossible\n";
		return 0;}

	if(p0*(p0-1)/2 != A[0][0] || p1*(p1-1)/2 != A[1][1]) {
		cout << "Impossible\n";
		return 0;}
	if(1LL*p0*p1 != A[0][1]+A[1][0]) {
		cout << "Impossible\n";
		return 0;}

	string S;
	int p1l =0, p0l =0, N =p0+p1;
	for(int i =0; i < N; i++) {
		if(p0 > 0 && p1 <= A[0][1]) {
			A[0][1] -=p1;
			p0--;
			p0l++;
			S +="0";}
		else {
			A[1][0] -=p0;
			p1--;
			p1l++;
			S +="1";}
		}
	cout << S << "\n";
	return 0;}

// look at my code
// my code is amazing