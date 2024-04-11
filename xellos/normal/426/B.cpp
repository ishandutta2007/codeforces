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
	int N,M;
	cin >> N >> M;
	vector< vector<int> > A(N,vector<int>(M));
	for(int i =0; i < N*M; i++) cin >> A[i/M][i%M];
	int n =N;
	while(n%2 == 0) {
		bool stop =false;
		for(int i =0; i < n/2; i++) for(int j =0; j < M; j++)
			if(A[i][j] != A[n-1-i][j]) stop =true;
		if(stop) break;
		n /=2;}
	cout << n << "\n";
	return 0;}

// look at my code
// my code is amazing