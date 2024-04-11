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
#define OVER9000 1234567890123456780LL
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
	cin.tie(0);
	cin.sync_with_stdio(0);
	int N,M,K,W;
	cin >> N >> M >> K >> W;
	vector< vector<string> > A(K);
	vector< vector< vector< vector<int> > > > P(53,vector< vector< vector<int> > >(N,vector< vector<int> >(M)));
	for(int k =0; k < K; k++) {
		A[k].resize(N);
		for(int i =0; i < N; i++) {
			cin >> A[k][i];
			for(int j =0; j < M; j++) {
				int x =52;
				if(A[k][i][j] >= 'A' && A[k][i][j] <= 'Z') x =A[k][i][j]-'A';
				if(A[k][i][j] >= 'a' && A[k][i][j] <= 'z') x =A[k][i][j]-'a'+26;
				P[x][i][j].push_back(k);}
			}
		}

	vector< vector<int> > C(K+1,vector<int>(K+1,N*M*W));
	C[K][K] =0;
	for(int i =0; i < 53; i++) for(int j =0; j < N; j++) for(int k =0; k < M; k++)
		for(int a =0; a < P[i][j][k].size(); a++) for(int b =a+1; b < P[i][j][k].size(); b++)
			C[P[i][j][k][a]][P[i][j][k][b]] -=W;
	for(int i =0; i < K; i++) {
		C[i][i] =C[i][K] =C[K][i] =N*M;
		for(int j =i+1; j < K; j++) C[j][i] =C[i][j];}

	vector< pair<int,int> > ansX;
	int ans =0;
	vector<int> U(K+1,false);
	vector<int> minH(K+1,N*M);
	vector<int> akoH(K+1,K);
	minH[K] =0; U[K] =true;
	for(int i =0; i < K; i++) {
		int a =-1, h =N*M+1, b =-1;
		for(int j =0; j < K; j++) if(!U[j] && minH[j] < h) {
			h =minH[j];
			a =j;
			b =akoH[j];}
		if(a == -1) break;
		U[a] =true;
		ans +=h;
		ansX.push_back(make_pair(b,a));
		for(int j =0; j < K; j++) if(minH[j] > C[j][a]) {
			minH[j] =C[j][a];
			akoH[j] =a;}
		}

	cout << ans << "\n";
	for(int i =0; i < K; i++) {
		if(ansX[i].ff == K) ansX[i].ff =0;
		else ansX[i].ff++;
		if(ansX[i].ss == K) ansX[i].ss =0;
		else ansX[i].ss++;
		cout << ansX[i].ss << " " << ansX[i].ff << "\n";}
	return 0;}

// look at my code
// my code is amazing