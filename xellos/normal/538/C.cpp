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
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< pair<int,int> > H(M);
	int Hmax =0;
	for(int i =0; i < M; i++) {
		cin >> H[i].ff >> H[i].ss;
		if(i == 0) Hmax =max(Hmax,H[i].ss+H[i].ff-1);
		if(i == M-1) Hmax =max(Hmax,H[i].ss+(N-H[i].ff));
		if(i == 0) continue;
		if(abs(H[i].ff-H[i-1].ff) < abs(H[i].ss-H[i-1].ss)) {cout << "IMPOSSIBLE\n"; return 0;}
		int a =H[i-1].ff, b =H[i].ff;
		while(b-a > 1) {
			int c =(b+a)/2;
			if(H[i-1].ss+(c-H[i-1].ff) <= H[i].ss+(H[i].ff-c)) a =c;
			else b =c;}
		Hmax =max(Hmax,max(H[i-1].ss+(a-H[i-1].ff),H[i].ss+(H[i].ff-b)));}
	cout << Hmax << "\n";
	return 0;}

// look at my code
// my code is amazing