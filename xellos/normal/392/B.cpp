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
#define OVER9000 12345678901234567LL
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
	int N;
	int D[3][3];
	for(int i =0; i < 9; i++) cin >> D[i/3][i%3];
	cin >> N;

	long long A[42][3][3];
	for(int i =0; i < 9; i++) A[0][i/3][i%3] =0;

	for(int i =1; i <= N; i++)
		for(int j =0; j < 3; j++) for(int k =0; k < 3; k++) if(j != k)
			A[i][j][k] =min(D[j][k]+A[i-1][j][3-j-k]+A[i-1][3-j-k][k],2*A[i-1][j][k]+A[i-1][k][j]+D[j][3-j-k]+D[3-j-k][k]);
	cout << A[N][0][2] << "\n";
	return 0;}

// look at my code
// my code is amazing