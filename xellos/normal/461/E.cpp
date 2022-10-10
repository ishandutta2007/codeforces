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
#define soclose 1e-6
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

vector< vector<long long> > D;
long long L;

vector< vector<long long> > pw(long long e) {
	if(e == 1) return D;
	vector< vector<long long> > V =pw(e/2),W(4,vector<long long>(4,L+1));
	for(int i =0; i < 4; i++) for(int j =0; j < 4; j++)
		for(int k =0; k < 4; k++) W[i][j] =min(W[i][j],V[i][k]+V[k][j]);
	if(e%2 == 0) return W;
	for(int i =0; i < 4; i++) for(int j =0; j < 4; j++) {
		V[i][j] =L+1;
		for(int k =0; k < 4; k++) V[i][j] =min(V[i][j],W[i][k]+D[k][j]);}
	return V;}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> L >> s;
	int N =s.length();
	D.resize(4,vector<long long>(4,L+patkan));
	vector<string> S[4][4][20]; // stringy zac. i, konciace j, dlhe k
	for(int i =0; i < N; i++) for(int j =i+1; j < min(i+13,N); j++)
		S[s[i]-'A'][s[j]-'A'][j-1-i].push_back(s.substr(i+1,j-1-i));

	for(int i =0; i < 4; i++) for(int j =0; j < 4; j++)
		for(int k =0; k < 13; k++) {
			sort(S[i][j][k].begin(),S[i][j][k].end());
			S[i][j][k].resize(unique(S[i][j][k].begin(),S[i][j][k].end())-S[i][j][k].begin());
			int x =1;
			for(int l =0; l < k; l++) x *=4;
			if(x != S[i][j][k].size()) {
				D[i][j] =k+1;
				break;}
			}

	long long ansA =0, ansB =L+1;
	while(ansB-ansA > 1) {
		vector< vector<long long> > V =pw((ansA+ansB)/2);
		bool b =false;
		for(int i =0; i < 4; i++)
			for(int j =0; j < 4; j++) if(V[i][j] < L) b =true;
//		cout << (ansA+ansB)/2 << " " << b << "\n";
		if(b) ansA =(ansA+ansB)/2;
		else ansB =(ansA+ansB)/2;}

	cout << ansA+1 << "\n";
	return 0;}

// look at my code
// my code is amazing