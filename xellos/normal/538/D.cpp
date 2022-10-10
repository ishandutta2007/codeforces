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
	int N;
	cin >> N;
	vector<string> S(N);
	for(int i =0; i < N; i++) cin >> S[i];

	set< pair<int,int> > Sv;
	for(int a =-N+1; a <= N-1; a++) for(int b =-N+1; b <= N-1; b++) if(!(a == 0 && b == 0)) {
		bool ok =true;
		for(int i =0; i < N; i++) for(int j =0; j < N; j++) if(S[i][j] == 'o') 
			if(min(i+a,j+b) >= 0 && max(i+a,j+b) < N)
				if(S[i+a][j+b] == '.') ok =false;
		if(ok) Sv.insert(make_pair(a,b));}

	vector< vector<bool> > isAtt(N,vector<bool>(N,false));
	for(int i =0; i < N; i++) for(int j =0; j < N; j++) if(S[i][j] == 'o')
		ALL_THE(Sv,it) if(min(i+it->ff,j+it->ss) >= 0 && max(i+it->ff,j+it->ss) < N)
			isAtt[i+it->ff][j+it->ss] =true;

	for(int i =0; i < N; i++) for(int j =0; j < N; j++)
		if(!isAtt[i][j] && S[i][j] == 'x') {cout << "NO\n"; return 0;}

	cout << "YES\n";
	vector<string> ans(2*N-1);
	for(int i =0; i < 2*N-1; i++) for(int j =0; j < 2*N-1; j++) ans[i] +='.';
	ans[N-1][N-1] ='o';
	ALL_THE(Sv,it) ans[N-1+it->ff][N-1+it->ss] ='x';
	for(int i =0; i < 2*N-1; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing