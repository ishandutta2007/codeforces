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
	int N,M,Et,E;
	cin >> N >> M >> Et >> E;
	vector<int> A(N), B(M);
	vector< set<int> > S(100000+tisic);
	for(int i =0; i < N; i++) cin >> A[i];
	for(int i =0; i < M; i++) {
		cin >> B[i];
		S[B[i]].insert(i);}

	vector< vector<int> > C(300+tisic,vector<int>(N+1,M+1));
	C[0][0] =0;
	for(int i =1; i <= 300; i++) {
		int a =M+1;
		for(int j =1; j <= N; j++) {
			a =min(a,C[i-1][j-1]);
			auto it =S[A[j-1]].lower_bound(a);
			if(it != S[A[j-1]].end()) C[i][j] =*it+1;}
		}

	int ans =0;
	for(int i =1; i <= 300; i++) for(int j =1; j <= N; j++) if(C[i][j] <= M)
		if(Et >= E*i+(j+C[i][j])) ans =i;
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing