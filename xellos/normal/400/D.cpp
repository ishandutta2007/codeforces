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
	int N,M,K;
	cin >> N >> M >> K;
	vector< vector< pair<int,int> > > G0(N);
	vector< vector<int> > C(K,vector<int>(K,OVER9000));
	for(int i =0; i < K; i++) C[i][i] =0;
	vector<int> A(N);
	vector<int> T(N);
	int A0 =0;
	for(int i =0; i < K; i++) {
		cin >> A[i];
		for(int j =0; j < A[i]; j++) T[A0+j] =i;
		A0 +=A[i];}
	for(int i =0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		G0[--a].push_back(make_pair(--b,c));
		G0[b].push_back(make_pair(a,c));
		C[T[a]][T[b]] =min(C[T[a]][T[b]],c);
		C[T[b]][T[a]] =min(C[T[b]][T[a]],c);}

	vector<int> V(N,-1);
	int c =0;
	queue<int> q;
	for(int i =0; i < N; i++) if(V[i] == -1) {
		q.push(i);
		V[i] =c;
		while(!q.empty()) {
			int a =q.front();
			ALL_THE(G0[a],it) if(it->ss == 0 && V[it->ff] == -1) {
				V[it->ff] =c;
				q.push(it->ff);}
			q.pop();}
		c++;}

	A0 =0;
	for(int i =0; i < K; i++) {
		for(int j =0; j < A[i]; j++) if(V[A0+j] != V[A0]) {
			cout << "No\n";
			return 0;}
		A0 +=A[i];}
	cout << "Yes\n";

	vector< vector<int> > D =C;
	for(int i =0; i < K; i++)
		for(int j =0; j < K; j++) for(int k =0; k < K; k++)
			D[j][k] =min(D[j][k],D[j][i]+D[i][k]);

	for(int i =0; i < K; i++)
		for(int j =0; j < K; j++) cout << ((D[i][j] == OVER9000)?-1:D[i][j]) << ((j == K-1)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing