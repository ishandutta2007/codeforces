// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-9
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
	vector< vector<long long> > A(N,vector<long long>(M));
	for(int i =0; i < N*M; i++) cin >> A[i/M][i%M];

	vector< vector<long long> > G[4];
	for(int i =0; i < 4; i++) G[i].resize(N,vector<long long>(M,-OVER9000));

	G[0][0][0] =A[0][0];
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
		if(i+1 < N) G[0][i+1][j] =max(G[0][i][j]+A[i+1][j],G[0][i+1][j]);
		if(j+1 < M) G[0][i][j+1] =max(G[0][i][j]+A[i][j+1],G[0][i][j+1]);}

	G[1][N-1][0] =A[N-1][0];
	for(int i =N-1; i >= 0; i--) for(int j =0; j < M; j++) {
		if(i-1 >= 0) G[1][i-1][j] =max(G[1][i][j]+A[i-1][j],G[1][i-1][j]);
		if(j+1 < M) G[1][i][j+1] =max(G[1][i][j]+A[i][j+1],G[1][i][j+1]);}

	G[3][0][M-1] =A[0][M-1];
	for(int i =0; i < N; i++) for(int j =M-1; j >= 0; j--) {
		if(i+1 < N) G[3][i+1][j] =max(G[3][i][j]+A[i+1][j],G[3][i+1][j]);
		if(j-1 >= 0) G[3][i][j-1] =max(G[3][i][j]+A[i][j-1],G[3][i][j-1]);}

	G[2][N-1][M-1] =A[N-1][M-1];
	for(int i =N-1; i >= 0; i--) for(int j =M-1; j >= 0; j--) {
		if(i-1 >= 0) G[2][i-1][j] =max(G[2][i][j]+A[i-1][j],G[2][i-1][j]);
		if(j-1 >= 0) G[2][i][j-1] =max(G[2][i][j]+A[i][j-1],G[2][i][j-1]);}

	long long ans =0;
	for(int i =1; i < N-1; i++) for(int j =1; j < M-1; j++) {
		ans =max(ans,G[0][i-1][j]+G[1][i][j-1]+G[2][i+1][j]+G[3][i][j+1]);
		ans =max(ans,G[0][i][j-1]+G[1][i+1][j]+G[2][i][j+1]+G[3][i-1][j]);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing