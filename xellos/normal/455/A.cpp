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
	int N,a;
	cin >> N;
	vector<int> P(100000+tisic,0);
	for(int i =0; i < N; i++) {
		cin >> a;
		P[a]++;}

	vector<long long> A[2];
	A[0].resize(100000+tisic,0);
	A[1].resize(100000+tisic,0);
	for(int i =1; i <= 100000; i++) {
		A[1][i] =A[0][i-1]+1LL*i*P[i];
		A[0][i] =max(A[0][i-1],A[1][i-1]);}

	cout << max(A[0][100000],A[1][100000]) << "\n";
	return 0;}

// look at my code
// my code is amazing