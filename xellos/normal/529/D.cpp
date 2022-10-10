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
	int N,M,T;
	scanf("%d %d %d",&N,&M,&T);
	vector<int> I(N);
	for(int i =0; i < N; i++) {
		int d,m,s;
		scanf("%d:%d:%d",&d,&m,&s);
		I[i] =d*60*60+m*60+s;}

	int a =0, b =0, mm =0;
	set< pair<int,int> > S;
	vector<int> ans(N);
	for(int i =0; i < N; i++) {
		while(!S.empty() && S.begin()->ff+T <= I[i]) {
			S.erase(S.begin());
			a--;}

		if(a == M) {
			ans[i] =S.rbegin()->ss;
			S.erase(--S.end());}
		else {
			ans[i] =++b;
			a++;}

		S.insert(make_pair(I[i],ans[i]));
		mm =max(mm,a);}

	if(mm < M) {cout << "No solution\n"; return 0;}

	cout << b << "\n";
	for(int i =0; i < N; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing