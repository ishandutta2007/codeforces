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
	cin.tie(0);
	long long M;
	int K;
	cin >> M >> K;
	K--;
	long long ans =0;
	long long C[80][80];
	for(int i =0; i < 80; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) C[i][j] =C[i-1][j-1]+C[i-1][j];}
	while(K > 0) {
		if(M == 0) break;
		for(int i =K; i < 70; i++)
			if(C[i][K] >= M) {
				M -=C[i-1][K];
				ans +=1LL<<(i-1);
				break;}
		K--;}
	cout << ans+1 << "\n";
	return 0;}

// look at my code
// my code is amazing