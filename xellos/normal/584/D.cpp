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
	scanf(" %d",&N);
	int range =min(N-1,100000);
	vector<bool> isPr(range+tisic,true);
	for(int i =2; i <= 40000; i++) 
		for(int j =max(2,(N-range+i-1)/i); j <= N/i; j++) isPr[N-i*j] =false;
	if(isPr[0]) {printf("1\n%d\n",N); return 0;}
	if(N > 4 && isPr[4]) {printf("3\n2 2 %d\n",N-4); return 0;}
	int mx =100000;
	vector<bool> isP(mx+tisic,true);
	for(int i =2; i <= mx; i++) if(isP[i])
		for(int j =i; j <= mx/i; j++) isP[i*j] =false;
	for(int i =0; i <= range; i++) if(isPr[i])
		for(int j =3; j <= i-3; j++) if(isP[j] && isP[i-j]) {
			printf("3\n");
			printf("%d %d %d\n",N-i,j,i-j);
			return 0;}
	return 0;}

// look at my code
// my code is amazing