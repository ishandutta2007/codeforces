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
	int N,T;
	scanf(" %d %d",&N,&T);
	int r =1, v =1;
	for(int i =0; i < N-1; i++) {
		r =(r*10)%T;
		v *=10;}
	if(N <= 4) {
		if(v+(T-r)%T >= 10*v) printf("-1\n"); 
		else printf("%d\n",v+(T-r)%T);
		return 0;}
	string S ="1";
	for(int i =0; i < N-2; i++) S +="0";
	S +=('0'+(T-r)%T);
	printf("%s\n",S.c_str());
	return 0;}

// look at my code
// my code is amazing