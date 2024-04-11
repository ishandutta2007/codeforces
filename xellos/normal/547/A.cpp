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
#define soclose 1e-5
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
	int M;
	int H[2], Y[2], A[2], X[2];
	cin >> M;
	for(int i =0; i < 2; i++) cin >> H[i] >> A[i] >> X[i] >> Y[i];
	int P[2], P0[2];
	int maxC[2];

	for(int k =0; k < 2; k++) {
		vector<int> T(M,-1);
		T[H[k]] =0;
		int t =0;
		while(true) {
			H[k] =(1LL*X[k]*H[k]+Y[k])%M;
			if(H[k] < 0) H[k] +=M;
			t++;
			if(T[H[k]] != -1) {
				P[k] =t-T[H[k]];
				P0[k] =T[A[k]];
				if(T[A[k]] < T[H[k]]) maxC[k] =0;
				else maxC[k] =-1;
				break;}
			T[H[k]] =t;}
		if(P0[k] == -1) {cout << "-1\n"; return 0;}
		}


	// P0[0]+k*P[0] == P0[1]+l*P[1]
	if(P0[0] < P0[1]) {swap(P0[0],P0[1]); swap(P[0],P[1]); swap(maxC[0],maxC[1]);}
	if(maxC[0] == -1) maxC[0] =P[1]-1;
	if(maxC[1] == -1) maxC[1] =OVER9000;
	// k < P[1]
	for(int k =0; k <= maxC[0]; k++) if((P0[0]+1LL*k*P[0]-P0[1])%P[1] == 0 && (P0[0]+1LL*k*P[0]-P0[1])/P[1] <= maxC[1]) {
		cout << P0[0]+1LL*k*P[0] << "\n";
		return 0;}
	cout << "-1\n";
	return 0;}

// look at my code
// my code is amazing