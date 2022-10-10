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
#define OVER9000 1234567890LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
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
	int N,M,K;
	cin >> N >> M >> K;
	vector< vector<int> > A(N,vector<int>(M));
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) cin >> A[i][j];
	int ans =K+1;

	if(K >= M) {
		for(int k =0; k < (1<<M); k++) {
			int akt =0, a =k;
			vector<int> B =A[0];
			for(int i =0; i < M; i++) {
				if(a%2 != 0) {akt++; B[i] =1-B[i];}
				a /=2;}
			for(int i =1; i < N; i++) {
				int C[] ={0,0};
				for(int j =0; j < M; j++)
					if(A[i][j] != B[j]) C[1]++;
					else C[0]++;
				akt +=min(C[0],C[1]);}
			ans =min(ans,akt);}
		cout << ((ans == K+1)?-1:ans) << "\n";
		return 0;}

	for(int i =0; i < M; i++) {
		int akt =0;
		for(int j =0; j < M; j++) if(j != i) {
			int C[] ={0,0};
			for(int k =0; k < N; k++)
				if(A[k][j] != A[k][i]) C[0]++;
				else C[1]++;
			akt +=min(C[0],C[1]);}
		ans =min(ans,akt);}

	cout << ((ans == K+1)?-1:ans) << "\n";
	return 0;}

// look at my code
// my code is amazing