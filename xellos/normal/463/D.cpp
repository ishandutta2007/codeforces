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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	vector< vector<int> > M(N,vector<int>(N,0));
	vector< vector<int> > A(K,vector<int>(N,0));
	for(int i =0; i < K; i++) for(int j =0; j < N; j++) {
		cin >> A[i][j];
		for(int k =0; k < j; k++) M[A[i][k]-1][A[i][j]-1]++;}

	vector<int> ans(N,1);
	for(int i =0; i < N; i++) for(int j =0; j < i; j++)
		if(M[A[0][j]-1][A[0][i]-1] == K) ans[i] =max(ans[i],ans[j]+1);
	int ansT =0;
	for(int i =0; i < N; i++) ansT =max(ansT,ans[i]);
	cout << ansT << "\n";
	return 0;}

// look at my code
// my code is amazing