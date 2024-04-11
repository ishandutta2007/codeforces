// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	int N,a;
	cin >> N;
	vector<string> S0(N);
	vector< vector<int> > adjL0(N);
	for(int i =1; i < N; i++) {
		cin >> a >> S0[i];
		adjL0[--a].push_back(i);}

	vector< vector<int> > adjL(1);
	vector<int> par(1,0);
	vector<char> C(1,' ');
	vector<int> kod(N,0);
	vector<int> null;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		a =q.front();
		for(uint j =0; j < adjL0[a].size(); j++) {
			int akt =kod[a], b =adjL0[a][j];
			for(uint k =0; k < S0[b].length(); k++) {
				adjL[akt].push_back(adjL.size());
				par.push_back(akt);
				akt =adjL.size();
				C.push_back(S0[b][k]);
				adjL.push_back(null);}
			kod[b] =akt;
			q.push(b);}
		q.pop();}
	
	string t;
	cin >> t;
	vector<int> prev(t.length()+1,0);
	for(uint i =2; i <= t.length(); i++) {
		prev[i] =prev[i-1];
		while(prev[i] > 0 && t[i-1] != t[prev[i]]) prev[i] =prev[prev[i]];
		if(t[i-1] == t[prev[i]]) prev[i]++;}
	
	int ans =0;
	vector<int> X(adjL.size(),0);
	for(uint i =1; i < adjL.size(); i++) {
		int akt =X[par[i]];
		while(akt > 0 && t[akt] != C[i]) akt =prev[akt];
		if(t[akt] == C[i]) akt++;
		if(akt == (int)t.length()) {
			ans++;
			akt =prev[akt];}
		X[i] =akt;}
	cout << ans << endl;
	return 0;}
        
// look at my code
// my code is amazing