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

void cnst(vector< vector<int> > &ako, int i, int j, string &ret) {
	if(i == ako.size()) return;
	if(ako[i][j] == -1) return;
	ret +="(";
	cnst(ako,i+1,ako[i][j]-2,ret);
	ret +=")";
	cnst(ako,i+ako[i][j]/2,j-ako[i][j],ret);}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> L(N),R(N);
	for(int i =0; i < N; i++) cin >> L[i] >> R[i];

	vector< vector<int> > ako(N+1,vector<int>(2*N+tisic,-1));
	// ak existuje postupnost zacinajuca i-tou dlzky j
	for(int i =N-1; i >= 0; i--) {
		// postupnosti konciace zatvaracou
		for(int j =L[i]; j <= R[i]; j++) if(j%2 != 0)
			if(j == 1 || ako[i+1][j-1] >= 0) ako[i][j+1] =j+1;
		// post. nekonciace zatv.
		for(int j =i+1; j <= N; j++) // dalsia otvarajuca
			for(int k =2; 2*(j-i)+k <= 2*N; k +=2)
				if(ako[j][k] >= 0 && ako[i][2*(j-i)] >= 0) ako[i][2*(j-i)+k] =ako[i][2*(j-i)];
		}

	if(ako[0][2*N] == -1) {cout << "IMPOSSIBLE\n"; return 0;}
	string S;
	cnst(ako,0,2*N,S);
	cout << S << "\n";
	return 0;}

// look at my code
// my code is amazing