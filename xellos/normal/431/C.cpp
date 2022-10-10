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
	int N,K,D;
	cin >> N >> K >> D;
	long long mod =1000000007;
	vector< vector<long long> > A[2];
	for(int i =0; i < 2; i++) A[i].resize(N+tisic,vector<long long>(N+tisic,0));
	A[0][0][N] =1;
	for(int i =0; i < N; i++) for(int j =0; j <= N; j++) for(int k =1; k <= min(K,j); k++) {
		A[0][i][j] %=mod;
		A[1][i][j] %=mod;
		if(k >= D) A[1][i+1][j-k] +=A[0][i][j];
		else A[0][i+1][j-k] +=A[0][i][j];
		A[1][i+1][j-k] +=A[1][i][j];}

	long long ans =0;
	for(int i =0; i <= N; i++) ans +=A[1][i][0];
	ans %=mod;
	if(ans < 0) ans +=mod;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing