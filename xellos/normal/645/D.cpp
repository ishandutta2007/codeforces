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
	vector< pair<int,int> > E(M);
	for(int i =0; i < M; i++) {
		cin >> E[i].ff >> E[i].ss;
		E[i].ff--, E[i].ss--;}
	int ansA =0, ansB =M+1;
	while(ansB-ansA > 1) {
		int C =(ansA+ansB)/2;
		vector< vector<int> > G(N);
		vector<int> D(N,0);
		for(int i =0; i < C; i++) {
			G[E[i].ff].push_back(E[i].ss);
			D[E[i].ss]++;}
		queue<int> q;
		int sz =0, proc =0;
		bool ok =true;
		for(int i =0; i < N; i++) if(D[i] == 0) {
			q.push(i);
			sz++;}
		while(!q.empty()) {
			if(sz > 1) {ok =false; break;}
			proc++;
			ALL_THE(G[q.front()],it) {
				D[*it]--;
				if(D[*it] == 0) {
					sz++;
					q.push(*it);}
				}
			sz--;
			q.pop();}
		if(proc != N) ok =false;
		if(ok) ansB =C;
		else ansA =C;}
	if(ansB == M+1) ansB =-1;
	cout << ansB << "\n";
	return 0;}

// look at my code
// my code is amazing