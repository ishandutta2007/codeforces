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
#define OVER9000 223456789012345678LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector< vector<int> > A(N,vector<int>(M));
	for(int i =0; i < N*M; i++) cin >> A[i/M][i%M];
	int ans =1;

	vector<int> occL(160000+tisic,-1);
	vector< vector< vector<int> > > lastR(M,vector< vector<int> >(M,vector<int>(N,-1)));
	for(int i =0; i < M; i++) for(int j =i; j < M; j++) {
		for(int k =0; k < N; k++) {
			if(i != j && A[k][i] == A[k][j]) lastR[i][j][k] =k;
			else lastR[i][j][k] =max(occL[A[k][i]],occL[A[k][j]]);
			occL[A[k][i]] =occL[A[k][j]] =k;}
		for(int k =0; k < N; k++) occL[A[k][i]] =occL[A[k][j]] =-1;}

	for(int l =2; l <= M; l++) for(int i =0; i <= M-l; i++)
		for(int k =0; k < N; k++) lastR[i][i+l-1][k] =max(lastR[i][i+l-1][k],max(lastR[i+1][i+l-1][k],lastR[i][i+l-2][k]));

	for(int i =0; i < M; i++) for(int j =i; j < M; j++) {
		int last =-1;
		for(int k =0; k < N; k++) {
			last =max(last,lastR[i][j][k]);
			ans =max(ans,(j-i+1)*(k-last));}
		}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing