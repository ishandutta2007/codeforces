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
	char ch[100000+tisic];
	scanf(" %s",ch);
	string s =(string)ch;
	int N =s.length();

	vector<string> nz;
	int l =0;
	for(int i =1; i < N; i++) if(s[i] != '0') {
		nz.push_back(s.substr(l,i-l));
		l =i;}
	nz.push_back(s.substr(l,N-l));
	int M =nz.size();

	int lA =-1, lB =M;
	while(lB-lA > 1) {
		int l =(lA+lB)/2, sum =0;
		for(int i =0; i < l; i++) sum +=nz[i].length();
		bool ok =true;
		for(int i =l; i < M; i++) {
			if((int)nz[i].length() > sum) {ok =false; break;}
			if(nz[i].length() == sum) 
				if(s.substr(0,sum) < s.substr(sum,sum)) {ok =false; break;}
			sum +=nz[i].length();}
		if(ok) lB =l;
		else lA =l;}
	printf("%d\n",M-lA);
	return 0;}

// look at my code
// my code is amazing