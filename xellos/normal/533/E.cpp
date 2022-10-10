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
	string S[2];
	cin >> N >> S[0] >> S[1];

	int s =0, f =N-1;
	while(s < N && S[0][s] == S[1][s]) s++;
	while(f >= 0 && S[0][f] == S[1][f]) f--;

	if(s == f) {cout << "2\n"; return 0;}

	set<string> ans;
	bool b =true;
	for(int i =s+1; i <= f; i++) if(S[0][i] != S[1][i-1]) b =false;
	if(b) {
		string W =S[0];
		W.insert(W.begin()+f+1,S[1][f]);
		ans.insert(W);
		W =S[1];
		W.insert(W.begin()+s,S[0][s]);
		ans.insert(W);}
	b =true;
	for(int i =s+1; i <= f; i++) if(S[0][i-1] != S[1][i]) b =false;
	if(b) {
		string W =S[1];
		W.insert(W.begin()+f+1,S[0][f]);
		ans.insert(W);
		W =S[0];
		W.insert(W.begin()+s,S[1][s]);
		ans.insert(W);}

	cout << ans.size() << "\n";
	return 0;}

// look at my code
// my code is amazing