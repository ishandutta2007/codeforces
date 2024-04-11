// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int main() {
	cin.sync_with_stdio(0);
	int N,a;
	cin >> N;
	vector<int> A[3];
	vector<int> S[3];
	for(int i =0; i < 3; i++) {
		A[i].resize(N);
		for(int j =0; j < N; j++) cin >> A[i][j];
		S[i].resize(N+1,0);
		for(int j =0; j < N; j++) S[i][j+1] =S[i][j]+A[i][j];}
	
	vector<int> C(N);
	vector<int> B(N);
	a =-OVER9000;
	for(int i =0; i < N; i++) {
		// prvy
		C[i] =A[0][i]+S[1][i];
		// pred nim i-1
		if(i > 0) C[i] =max(C[i],A[1][i]+C[i-1]);
		// pred nim skorsi
		if(i > 1) {
			a =max(a,B[i-2]);
			C[i] =max(C[i],A[0][i]+S[1][i]+a);}
		if(i < N-2) B[i] =C[i]+A[2][i+1]-S[1][i+2];}
	
	cout << C[N-1] << "\n";
    return 0;}
        
// look at my code
// my code is amazing