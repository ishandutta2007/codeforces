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
	int N,D;
	cin >> N >> D;
	vector<int> P(30001,0);
	for(int i =0; i < N; i++) {
		int p;
		cin >> p;
		P[p]++;}

	vector<int> S =P;
	for(int i =29999; i >= 0; i--) S[i] +=S[i+1];
	vector< vector<int> > ans(30001,vector<int>(700,-OVER9000));

	ans[D][300] =P[D];
	int ansF =0;
	for(int i =D; i <= 30000; i++) for(int j =0; j < 700; j++) if(j-300+D > 1) {
		ansF =max(ansF,ans[i][j]);
		if(j-300+D+i <= 30000) ans[j-300+D+i][j] =max(ans[j-300+D+i][j],ans[i][j]+P[j-300+D+i]);
		if(j-300+D+i+1 <= 30000) ans[j-300+D+i+1][j+1] =max(ans[j-300+D+i+1][j+1],ans[i][j]+P[j-300+D+i+1]);
		if(j-300+D+i-1 <= 30000) ans[j-300+D+i-1][j-1] =max(ans[j-300+D+i-1][j-1],ans[i][j]+P[j-300+D+i-1]);}

	for(int i =D; i < 30000; i++) for(int j =0; j < 700; j++) 
		if(j-300+D == 1) ansF =max(ansF,ans[i][j]+S[i+1]);
	cout << ansF << "\n";
	return 0;}

// look at my code
// my code is amazing