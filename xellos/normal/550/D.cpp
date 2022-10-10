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
	int K;
	cin >> K;
	if(K%2 == 0) {cout << "NO\n"; return 0;}
	cout << "YES\n";
	if(K == 1) {cout << "2 1\n1 2\n"; return 0;}

	vector< pair<int,int> > E;
	E.push_back(make_pair(0,(K*K+1)/2));

	for(int k =0; k < 2; k++) {
		int n =1+k*(K*K+1)/2;
		for(int j =0; j < (K-1)/2; j++) {
			E.push_back(make_pair(k*(K*K+1)/2,n));
			E.push_back(make_pair(k*(K*K+1)/2,n+1));
			for(int a =0; a <= K; a++) for(int b =a+1; b <= K; b++) 
				if(a != 0 || b != 1) E.push_back(make_pair(n+a,n+b));
			n +=K+1;}
		}

/*	for(int i =0; i < K*K+1; i++) {
		int D =0;
		for(int j =0; j < K*K+1; j++) D +=G[i][j];
		if(D != K) {cout << "FAIL\n"; return 0;}
		}
*/
	cout << K*K+1 << " " << K*(K*K+1)/2 << "\n";
	ALL_THE(E,it) cout << it->ff+1 << " " << it->ss+1 << "\n";
	return 0;}

// look at my code
// my code is amazing