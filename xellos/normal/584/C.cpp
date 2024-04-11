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
	string S[2];
	char ch[100000+tisic];
	for(int k =0; k < 2; k++) {
		scanf(" %s",ch);
		S[k] =(string)ch;}

	int p1 =0, p2 =0;
	for(int i =0; i < N; i++) {
		if(S[0][i] == S[1][i]) p1++;
		else p2++;}
	for(int x =0; x <= p2/2; x++) if(T-p2+x >= 0 && T-p2+x <= p1) {
		int y =x, z =p2-2*x, z2 =T-p2+x, w =p1-(T-p2+x);
		string ans;
		for(int i =0; i < N; i++) {
			if(S[0][i] == S[1][i]) {
				if(w > 0) {ans +=S[0][i]; w--; continue;}
				z2--;
				for(int k =0; k < 3; k++) if(S[0][i] != 'a'+k && S[1][i] != 'a'+k) {
					ans +=('a'+k);
					break;}
				continue;}
			if(x > 0) ans +=S[0][i], x--;
			else if(y > 0) ans +=S[1][i], y--;
			else {
				z--;
				for(int k =0; k < 3; k++) if(S[0][i] != 'a'+k && S[1][i] != 'a'+k) {
					ans +=('a'+k);
					break;}
				}
			}
		printf("%s\n",ans.c_str());
		return 0;}
	printf("-1\n");
	return 0;}

// look at my code
// my code is amazing