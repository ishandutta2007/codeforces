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
	int N;
	cin >> N;
	map<string,int> M1,M2;
	vector< vector<int> > G;
	int n =0, m =0;
	vector<string> I;
	for(int i =0; i < N; i++) {
		string S;
		cin >> S;
		int x =7;
		while(x < (int)S.length() && S[x] != '/') x++;
		string S1 =S.substr(7,x-7);
		string S2 =(x == (int)S.length())?"":S.substr(x,S.length()-x);
		auto it =M1.find(S1), jt =M2.find(S2);
		if(it == M1.end()) {
			I.push_back("http://"+S1);
			M1[S1] =n++;
			G.push_back(vector<int>());}
		if(jt == M2.end()) M2[S2] =m++;
		G[M1[S1]].push_back(M2[S2]);}
	for(int i =0; i < n; i++) sort(begin(G[i]),end(G[i]));
	long long p =1234567, mod1 =1000000007, mod2 =1000000009;
	map<long long,vector<int> > M;
	for(int i =0; i < n; i++) {
		long long h1 =0, h2 =0;
		for(int j =0; j < (int)G[i].size(); j++) if(j == 0 || G[i][j] != G[i][j-1]) {
			h1 =(p*h1+G[i][j]+1)%mod1;
			h2 =(p*h2+G[i][j]+1)%mod2;}
		if(h1 < 0) h1 +=mod1;
		if(h2 < 0) h2 +=mod2;
		M[h1*mod2+h2].push_back(i);}
	int ans =0;
	ALL_THE(M,it) if(it->ss.size() > 1) ans++;
	cout << ans << "\n";
	ALL_THE(M,it) if(it->ss.size() > 1) {
		vector<int> v =it->ss;
		for(int i =0; i < (int)v.size(); i++) cout << I[v[i]] << ((i == (int)v.size()-1)?"\n":" ");
		}
	return 0;}

// look at my code
// my code is amazing