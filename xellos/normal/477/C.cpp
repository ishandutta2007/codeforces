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
	string S,P;
	cin >> S >> P;
	int N =S.length(), M =P.length();

	vector<int> nxt(N+1,N+M+tisic);
	for(int i =0; i < N; i++) {
		int a =0;
		for(int j =i; j < N; j++) {
			if(P[a] == S[j]) a++;
			if(a == M) {nxt[i] =j+1; break;}
			}
		}

	vector< vector<int> > A(N+1,vector<int>(N+1,N+2)); 
	// kolko pismen najmenej zmazem na to aby v sufixe i bolo j vyskytov
	A[N][0] =0;
	for(int i =N-1; i >= 0; i--) {
		// nezacina
		for(int j =0; j <= N; j++) A[i][j] =A[i+1][j];
		// zacina
		for(int j =0; j < N; j++) if(nxt[i] <= N) 
			A[i][j+1] =min(A[i][j+1],nxt[i]-i-M+A[nxt[i]][j]);
		}

	vector<int> ans(N+1,0);
	for(int j =0; j <= N; j++) if(A[0][j] <= N) ans[A[0][j]] =max(ans[A[0][j]],j);
	for(int i =0; i < N; i++) {
		if(N-i-ans[i]*M > 0) ans[i+1] =max(ans[i+1],ans[i]);
		else ans[i+1] =max(ans[i+1],ans[i]-1);}
	for(int i =0; i <= N; i++) cout << ans[i] << ((i == N)?"\n":" ");
	return 0;}

// look at my code
// my code is amazing