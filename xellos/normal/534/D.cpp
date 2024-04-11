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
	int N, maxA =0;
	cin >> N;
	vector< vector<int> > P(N+1);
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		maxA =max(maxA,a);
		P[a].push_back(i+1);}

	vector<int> ans;
	for(int i =0; i <= maxA; i++) {
		if(P[i].empty()) {cout << "Impossible\n"; return 0;}
		ans.push_back(*P[i].rbegin());
		P[i].pop_back();}
	int akt =maxA+1;
	for(int i =maxA; i >= 0; i--) while(!P[i].empty()) {
		int x =i;
		while((x-akt)%3 != 0) x--;
		if(x < 0) {cout << "Impossible\n"; return 0;}
		for(int j =x; j <= i; j++) {
			if(P[j].empty()) {cout << "Impossible\n"; return 0;}
			ans.push_back(*P[j].rbegin());
			P[j].pop_back();}
		akt =i+1;}

	cout << "Possible\n";
	for(int i =0; i < N; i++) cout << ans[i] << ((i == N-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing