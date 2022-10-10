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
	vector<string> S(N);
	for(int i =0; i < N; i++) cin >> S[i];
	vector< vector<int> > C(N,vector<int>(M));
	for(int i =0; i < N*M; i++) cin >> C[i/M][i%M];

	vector< vector< pair<int,int> > > sets(M);
	for(int i =0; i < M; i++) {
		for(int j =0; j < N; j++) sets[i].push_back(make_pair(C[j][i],1<<j));
		for(int j =0; j < 26; j++) {
			pair<int,int> p =make_pair(0,0);
			int xm =-1, cm =-1;
			for(int k =0; k < N; k++) if(S[k][i] == 'a'+j) {
				if(cm < C[k][i]) cm =C[k][i], xm =k;
				p.ss +=1<<k;
				p.ff +=C[k][i];}
			if(xm == -1) continue;
			p.ff -=cm;
			sets[i].push_back(p);}
		}

	vector<long long> ans(1<<N,1e9);
	ans[0] =0;
	for(int i =0; i < M; i++) {
		for(int j =0; j < (1<<N); j++) ALL_THE(sets[i],it) 
			ans[j|it->ss] =min(ans[j|it->ss],ans[j]+it->ff);
		}

	cout << ans[(1<<N)-1] << "\n";
	return 0;}

// look at my code
// my code is amazing