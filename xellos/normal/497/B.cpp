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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> P[2];
	for(int i =0; i < N; i++) {
		cin >> A[i];
		P[--A[i]].push_back(i);}
	vector<int> S[2];
	for(int i =0; i < 2; i++) {
		S[i].resize(N+1,0);
		ALL_THE(P[i],it) S[i][*it+1]++;
		for(int j =0; j < N; j++) S[i][j+1] +=S[i][j];}
	// st <= N
	// pevne t: jasny match
	// male t: odsimulujem
	set< pair<int,int> > ans; // s,t
	vector< pair<int,int> > V;
	// t == 1
	for(int i =0; i < N; i++) V.push_back(make_pair(i+1,A[i]));
	int W[2] ={0,0};
	ALL_THE(V,it) W[it->ss]++;
	if(W[A[N-1]] > W[1-A[N-1]]) ans.insert(make_pair(W[A[N-1]],1));
	for(int t =2; t <= N; t++) {
		int a =0;
		for(uint i =0; i < V.size(); i++) {
			V[i].ff =max(V[i].ff,a);
			while(V[i].ff <= N && -S[0][a]+S[0][V[i].ff] < t && -S[1][a]+S[1][V[i].ff] < t)
				V[i].ff++;
			if(V[i].ff > N) {V.resize(i); break;}
			if(-S[1-A[V[i].ff-1]][a]+S[1-A[V[i].ff-1]][V[i].ff] < t) V[i].ss =A[V[i].ff-1];
			else V[i].ss =1-A[V[i].ff-1];
			a =V[i].ff;}
		if(V.empty() || V.rbegin()->ff != N) continue;
		W[0] =W[1] =0;
		ALL_THE(V,it) W[it->ss]++;
		if(W[A[N-1]] > W[1-A[N-1]]) ans.insert(make_pair(W[A[N-1]],t));}

	cout << ans.size() << "\n";
	ALL_THE(ans,it) cout << it->ff << " " << it->ss << "\n";
	return 0;}

// look at my code
// my code is amazing