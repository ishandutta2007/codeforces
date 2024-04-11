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
	int T;
	scanf(" %d",&T);
	char ch[200];
	for(int t =0; t < T; t++) {
		int N,K;
		scanf(" %d %d",&N,&K);
		vector< vector<bool> > tr(3,vector<bool>(N+5,false));
		auto ans =tr;
		for(int i =0; i < 3; i++) {
			scanf(" %s",ch);
			string s =(string)ch;
			for(int j =0; j < N; j++) if(s[j] != '.') tr[i][j] =true;
			if(s[0] == 's') ans[i][0] =true;}
		for(int i =0; i < N; i++) for(int j =0; j < 3; j++) if(ans[j][i]) {
			if(i == N) break;
			if(tr[j][i+1]) continue;
			for(int k =-1; k <= 1; k++) if(j+k >= 0 && j+k <= 2 && !tr[j+k][i+1] && !tr[j+k][i+2] && !tr[j+k][i+3])
				ans[j+k][i+3] =true;
			}
		bool ansF =false;
		for(int i =N; i <= N+4; i++) for(int j =0; j < 3; j++) if(ans[j][i]) ansF =true;
		if(ansF) printf("YES\n");
		else printf("NO\n");}
	return 0;}

// look at my code
// my code is amazing