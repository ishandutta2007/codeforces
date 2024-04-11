// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1034567890
#define patkan 9
#define tisic 47
#define soclose 1e-9
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<string> V(N);
	for(int i =0; i < N; i++) cin >> V[i];

	int dx[] ={-1,0,1,-1,1,-1,0,1};
	int dy[] ={-1,-1,-1,0,0,1,1,1};
	vector< vector<int> > L[8];
	for(int i =0; i < 8; i++) L[i].resize(N,vector<int>(M,0));
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(V[i][j] == '0') {
		L[0][i][j] =1+((i > 0 && j > 0)?L[0][i-1][j-1]:0);
		L[1][i][j] =1+((i > 0)?L[1][i-1][j]:0);
		L[3][i][j] =1+((j > 0)?L[3][i][j-1]:0);}
	for(int i =0; i < N; i++) for(int j =M-1; j >= 0; j--) if(V[i][j] == '0') {
		L[2][i][j] =1+((i > 0 && j < M-1)?L[2][i-1][j+1]:0);
		L[4][i][j] =1+((j < M-1)?L[4][i][j+1]:0);}
	for(int i =N-1; i >= 0; i--) for(int j =0; j < M; j++) if(V[i][j] == '0') {
		L[5][i][j] =1+((i < N-1 && j > 0)?L[5][i+1][j-1]:0);
		L[6][i][j] =1+((i < N-1)?L[6][i+1][j]:0);
		L[7][i][j] =1+((i < N-1 && j < M-1)?L[7][i+1][j+1]:0);}

	int ans =0;
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) {
		for(int k =1; k < min(L[1][i][j],L[3][i][j]); k++)
			if(L[5][i-k][j] >= k) ans++;
		for(int k =1; k < min(L[3][i][j],L[6][i][j]); k++)
			if(L[7][i][j-k] >= k) ans++;
		for(int k =1; k < min(L[6][i][j],L[4][i][j]); k++)
			if(L[2][i+k][j] >= k) ans++;
		for(int k =1; k < min(L[4][i][j],L[1][i][j]); k++)
			if(L[0][i][j+k] >= k) ans++;
		for(int k =1; k < min(L[2][i][j],L[0][i][j]); k++)
			if(L[4][i-k][j-k] >= 2*k) ans++;
		for(int k =1; k < min(L[0][i][j],L[5][i][j]); k++)
			if(L[1][i+k][j-k] >= 2*k) ans++;
		for(int k =1; k < min(L[5][i][j],L[7][i][j]); k++)
			if(L[3][i+k][j+k] >= 2*k) ans++;
		for(int k =1; k < min(L[7][i][j],L[2][i][j]); k++)
			if(L[6][i-k][j+k] >= 2*k) ans++;
		}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing