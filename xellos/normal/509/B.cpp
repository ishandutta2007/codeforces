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
	int N,K;
	cin >> N >> K;
	vector<int> A(N);
	for(int i =0; i < N; i++) cin >> A[i];
	vector< vector<int> > ans(N,vector<int>(K,0));
	for(int i =0; i < K; i++) {
		int x =-1;
		for(int j =0; j < N; j++) if(x == -1 || A[j] < A[x]) x =j;
		for(int j =0; j < N; j++) {
			if(A[j] == A[x]) ans[j][i] =A[x];
			else ans[j][i] =A[x]+1;}
		for(int j =0; j < N; j++) A[j] -=ans[j][i];}
	for(int i =0; i < N; i++) if(A[i] > 0) {cout << "NO\n"; return 0;}
	cout << "YES\n";
	for(int i =0; i < N; i++) {
		for(int j =0; j < K; j++) for(int l =0; l < ans[i][j]; l++) 
			cout << j+1 << " ";
		cout << "\n";}
	return 0;}

// look at my code
// my code is amazing