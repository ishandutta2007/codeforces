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
	int N,K;
	string S;
	cin >> N >> K >> S;
	vector<int> sum(N+1,0);
	for(int i =0; i < N; i++) sum[i+1] =sum[i]+('1'-S[i]);
	int ansB =N+tisic, ansA =0;
	while(ansB-ansA > 1) {
		int C =(ansA+ansB)/2;
		bool ok =false;
		for(int i =0; i < N; i++) if(S[i] == '0') {
			int x =sum[i]-sum[max(0,i-C)]+sum[min(N,i+C+1)]-sum[i+1];
			if(x >= K) ok =true;
			}
		if(ok) ansB =C;
		else ansA =C;}
	cout << ansB << "\n";
	return 0;}

// look at my code
// my code is amazing