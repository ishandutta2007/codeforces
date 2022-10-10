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
#define ull unsigned long long
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> B(N);
	for(int i =0; i < N; i++) cin >> B[i];
	if(N == 1) {cout << "1\n"; return 0;}

	ull mod =1000000007;
	vector< vector<ull> > P(N+1,vector<ull>(N+1,0));
	for(int i =N; i > 0; i--) for(int j =i; j <= N; j++) {
		if(i == j) {P[i][j] =1; continue;}
		// jediny syn
		P[i][j] =P[i+1][j];
		// dalsi syn
		for(int k =i+1; k < j; k++) if(B[k] > B[i])
			P[i][j] =(P[i][j]+P[i+1][k]*P[k][j])%mod;
		}

	cout << P[1][N] << "\n";
	return 0;}

// look at my code
// my code is amazing