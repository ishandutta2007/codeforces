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
#define OVER9000 1234567890
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
#include <time.h>
// mylittlepony
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		int N,P;
		cin >> N >> P;
		vector< vector<bool> > E(N,vector<bool>(N,false));
		for(int i =0; i < N; i++) {
			E[i][(i+1)%N] =E[(i+1)%N][i] =true;
			cout << i+1 << " " << (i+1)%N+1 << "\n";}
		for(int i =0; i < N; i++) {
			E[i][(i+2)%N] =E[(i+2)%N][i] =true;
			cout << i+1 << " " << (i+2)%N+1 << "\n";}
		for(int i =0; i < N; i++) for(int j =i+1; j < N; j++)
			if(P > 0 && !E[i][j]) {
				P--;
				cout << i+1 << " " << j+1 << "\n";}
		}
	return 0;}

// look at my code
// my code is amazing