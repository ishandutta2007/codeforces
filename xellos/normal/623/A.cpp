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
	int N,M;
	cin >> N >> M;
	vector< vector<int> > G(N,vector<int>(N,0));
	for(int i =0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		G[a-1][b-1] =G[b-1][a-1] =1;}
	vector<int> S(N,-1);
	queue<int> q;
	for(int i =0; i < N; i++) {
		bool isb =true;
		for(int j =0; j < N; j++) if(i != j && G[i][j] == 0) isb =false;
		if(isb) continue;
		S[i] =0;
		for(int j =0; j < N; j++) if(i != j && G[i][j] == 0) {
			S[j] =2;
			for(int k =0; k < N; k++) if(j != k && G[j][k] == 0) S[k] =0;}
		break;}
	for(int i =0; i < N; i++) if(S[i] == -1) S[i] =1;

	bool ok =true;
	for(int i =0; i < N; i++) for(int j =0; j < N; j++) if(i != j)
		if(G[i][j]^(abs(S[i]-S[j]) < 2)) ok =false;
	if(!ok) {cout << "No\n"; return 0;}
	cout << "Yes\n";
	for(int i =0; i < N; i++) cout << (char)('a'+S[i]);
	cout << "\n";
	return 0;}

// look at my code
// my code is amazing