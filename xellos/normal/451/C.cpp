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
#define OVER9000 1234567890123456780LL
#define patkan 9
#define tisic 47
#define soclose 1e-7
#define pi 3.1415926535898
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
#define uint unsigned int
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		long long N,K;
		long long D[2];
		cin >> N >> K >> D[0] >> D[1];
		bool ans =false;
		for(int a =0; a < 2; a++) for(int b =0; b < 2; b++) {
			D[0] =abs(D[0])*(2*b-1);
			D[1] =abs(D[1])*(2*a-1);
			if((K-D[0]+D[1])%3 != 0) continue;
			long long W[3];
			W[1] =(K-D[0]+D[1])/3;
			W[0] =D[0]+W[1];
			W[2] =W[1]-D[1];
			if(W[0] < 0 || W[1] < 0 || W[2] < 0) continue;
			long long mx =max(W[0],max(W[1],W[2]));
			if(3*mx-W[0]-W[1]-W[2] > N-K) continue;
			if((W[0]+W[1]+W[2]+N-K)%3 == 0) ans =true;}
		cout << (ans?"yes\n":"no\n");}
	return 0;}

// look at my code
// my code is amazing