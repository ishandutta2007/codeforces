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

	vector< vector<double> > C(2000,vector<double>(2000,0));
	for(int i =0; i < 2000; i++) {
		C[i][0] =1;
		for(int j =1; j <= i; j++) C[i][j] =C[i-1][j]+C[i-1][j-1];}

	double ans =0, p =0;
	for(int i =0; i <= min(M,N); i++) {
		double x =1;
		for(int j =0; j < i; j++) x *=1.0*(M-j)/(j+1);
		for(int j =0; j < N-i; j++) x *=1.0*((N-1)*M-j)/(j+1);
		ans +=1.0*i*i/N*x;
		p +=x;}

	cout << fixed << setprecision(9) << ans/p << "\n";

	return 0;}

// look at my code
// my code is amazing