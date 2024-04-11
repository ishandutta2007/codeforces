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
	string ST;
	cin >> N >> ST;
	vector< vector<int> > son(1000000+tisic,vector<int>(26,-1)),ends(1000000+tisic);
	int V =1, M;
	cin >> M;
	vector<string> W(M);
	for(int i =0; i < M; i++) {
		string s;
		cin >> s;
		W[i] =s;
		int akt =0;
		for(int j =0; j < (int)s.length(); j++) {
			int x =s[j]-'a';
			if(s[j] >= 'A' && s[j] <= 'Z') x =s[j]-'A';
			if(son[akt][x] == -1) {
				son[akt][x] =V;
				V++;}
			akt =son[akt][x];}
		ends[akt].push_back(i);}

	vector<int> ako(N+1,-1);
	ako[0] =0;
	for(int i =0; i < N; i++) {
		int akt =0;
		for(int j =i; j >= 0; j--) {
			int x =ST[j]-'a';
			if(son[akt][x] == -1) break;
			akt =son[akt][x];
			if(ako[j] >= 0 && !ends[akt].empty()) {
				ako[i+1] =ends[akt][0];
				break;}
			}
		}

	vector<string> ans;
	int akt =N;
	while(akt > 0) {
		ans.push_back(W[ako[akt]]);
		akt -=ans.back().length();}
	reverse(begin(ans),end(ans));
	for(int i =0; i < ans.size(); i++) cout << ans[i] << ((i == ans.size()-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing