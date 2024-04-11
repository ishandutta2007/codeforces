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
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 1e-11
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int N,M,Q;
	cin >> N >> M >> Q;
	vector<string> S(N);
	for(int i =0; i < N; i++) cin >> S[i];
	vector< vector<int> > A(N, vector<int>(M,0));
	for(int i =0; i < N*M; i++) A[i/M][i%M] =S[i/M][i%M]-'0';

	vector< vector<int> > X(N, vector<int>(M,0)); // pocet nul nahor
	for(int i =0; i < N; i++) for(int j =0; j < M; j++) if(A[i][j] == 0) {
		if(i == 0) X[i][j] =1;
		else X[i][j] =X[i-1][j]+1;}

	vector< vector<long long> > ans(N*M, vector<long long>(N*M,0));
	for(int i =0; i < N; i++) for(int j =0; j < M; j++)
		for(int k =i; k < N; k++) for(int l =j; l < M; l++) {
			if(i == k && j == l) {
				if(A[i][j] == 0) ans[i*M+j][k*M+l]++;
				continue;}
			if(i == k) {
				ans[i*M+j][k*M+l] =ans[i*M+j][k*M+l-1];
				for(int m =l; m >= j; m--) {
					if(A[i][m] != 0) break;
					ans[i*M+j][k*M+l]++;}
				continue;}
			if(j == l) {
				ans[i*M+j][k*M+l] =ans[i*M+j][(k-1)*M+l];
				for(int m =k; m >= i; m--) {
					if(A[m][j] != 0) break;
					ans[i*M+j][k*M+l]++;}
				continue;}
			ans[i*M+j][k*M+l] =ans[i*M+j][k*M+l-1]+ans[i*M+j][(k-1)*M+l]-ans[i*M+j][(k-1)*M+l-1];
			int a =k-i+1;
			for(int m =l; m >= j; m--) {
				if(A[k][m] != 0) break;
				a =min(a,X[k][m]);
				ans[i*M+j][k*M+l] +=a;}
			}

	for(int q =0; q < Q; q++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		cout << ans[a*M+b][c*M+d] << "\n";}
	return 0;}

// look at my code
// my code is amazing